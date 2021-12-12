### Assignment requirments

- The report should be in PDF format and should be a maximum of 12 pages long and not less than 7 pages.
 - The report should include:
   - A general overview of the simulated system
   - A table of groups' names and corresponding to each name his/her contribution percentage to the project and a short description of his/her contribution
   - Introduction about the attack performed and its different techniques
   - An attack explanation with commands used, screenshots of outputs and results (step by step)
   - Your contribution if you used one of the posted projects (change attack protocol, complicated scenario.. etc). This contribution should be clarified in your report and the final project selection submission)
   - Explanation of how to detect and defend against this attack
   - Conclusion of lessons learned from an attacker perspective and system defender (administrator) perspective
   - Sources of your information (references)


### What is the NSA codebreaker challenge

The NSA CodeBreaker challenge is a year competion between schools where "The NSA ... provides students with a hands-on opportunity to develop their reverse-engineering / low-level code analysis skills while working on a realistic problem set centered around the NSA's mission." The competion is divided into 2 parts, solo and team, each consiting of 6 and 4 challenges respectivly. 

### This years story



### Individual Contributions
  - Nicholas
    - Complete Challenges 1-6
    - Final Documentation Writing
    - Challenge write-ups - Task 5, 6
  - Seth 
    - Complete Challenges - 1-4
    - Final Documentation Writing
    - Challenge write-ups - Task 3,4
  - Nitin 
    - Complete Challenges - TBD
    - Final Documentation Writing - TBD
    - Challenge write-ups - TBD
  - Kevin
    - Complete Challenges - TBD
    - Final Documentation Writing - TBD
    - Challenge write-ups - TBD
  
### Attacks Seen and overview
  - Supply Chain
  - Phishing
  - Malware

### Overview of skills Involoved
  - Log anylisis and forensics
  - Powershell Malware analyisis
  - Windows Registry Forensics
  - Docker file Forensics and Reverse engineering
  - Object Orinted ELF binary reverse engineering
  - Cryptografic attacks

### Overview of each challenge

#### Disclaimer
Each competitor got slightly different files to insure that commands ran by one competitor couldn't simply be copy pasted by another competitor. As not all of the screen shots came from the same competitor, there will be slight discrepincies between spesific information. This should have no affect on the underlying methiod to solve each challenge though.

#### Task 1
[Full Writeup](task01/writeup.md)

The challenge discription is as follows:

> The NSA Cybersecurity Collaboration Center has a mission to prevent and eradicate threats to the US Defense Industrial Base (DIB). Based on information sharing agreements with several DIB companies, we need to determine if any of those companies are communicating with the actor's infrastructure.

> You have been provided a capture of data en route to the listening post as well as a list of DIB company IP ranges. Identify any IPs associated with the DIB that have communicated with the LP.

And you are given:
    
    Network traffic heading to the LP (capture.pcap)
    DIB IP address ranges (ip_ranges.txt)

Overview of how challenge was completed:

#### Task 2
[Full Writeup](task02/writeup.md)


The challenge discription is as follows:
 > NSA notified FBI, which notified the potentially-compromised DIB Companies. The companies reported the compromise to the Defense Cyber Crime Center (DC3). One of them, Online Operations and Production Services (OOPS) requested FBI assistance. At the request of the FBI, we've agreed to partner with them in order to continue the investigation and understand the compromise.

 > OOPS is a cloud containerization provider that acts as a one-stop shop for hosting and launching all sorts of containers -- rkt, Docker, Hyper-V, and more. They have provided us with logs from their network proxy and domain controller that coincide with the time that their traffic to the cyber actor's listening post was captured.

 > Identify the logon ID of the user session that communicated with the malicious LP (i.e.: on the machine that sent the beacon *and* active at the time the beacon was sent).


And you are given

    Subnet associated with OOPS (oops_subnet.txt)
    Network proxy logs from Bluecoat server (proxy.log)
    Login data from domain controller (logins.json)

Overview of how challenge was completed:


#### Task 3
[Full Writeup](task03/writeup.md)


The challenge discription is as follows:
 > With the provided information, OOPS was quickly able to identify the employee associated with the account. During the incident response interview, the user mentioned that they would have been checking email around the time that the communication occurred. They don't remember anything particularly weird from earlier, but it was a few weeks back, so they're not sure. OOPS has provided a subset of the user's inbox from the day of the communication.
 > Identify the message ID of the malicious email and the targeted server.


And you are given:

    User's emails (emails.zip)

Overview of how challenge was completed:


#### Task 4
[Full Writeup](task04/writeup.md)


The challenge discription is as follows:
 > A number of OOPS employees fell victim to the same attack, and we need to figure out what's been compromised! Examine the malware more closely to understand what it's doing. Then, use these artifacts to determine which account on the OOPS network has been compromised.




And you are given:

    OOPS forensic artifacts (artifacts.zip)
    
And the flags are

    The name of the machine the attackers can now access
    The username the attackers can use to access that machine  
   
   
Overview of how challenge was completed:

#### Task 5
[Full Writeup](task05/writeup.md)

The challenge discription is as follows:

 > A forensic analysis of the server you identified reveals suspicious logons shortly after the malicious emails were sent. Looks like the actor moved deeper into OOPS' network. Yikes.

 > The server in question maintains OOPS' Docker image registry, which is populated with images created by OOPS clients. The images are all still there (phew!), but one of them has a recent modification date: an image created by the Prevention of Adversarial Network Intrusions Conglomerate (PANIC).

 > Due to the nature of PANIC's work, they have a close partnership with the FBI. They've also long been a target of both government and corporate espionage, and they invest heavily in security measures to prevent access to their proprietary information and source code.

 > The FBI, having previously worked with PANIC, have taken the lead in contacting them. The FBI notified PANIC of the potential compromise and reminded them to make a report to DC3. During conversations with PANIC, the FBI learned that the image in question is part of their nightly build and test pipeline. PANIC reported that nightly build and regression tests had been taking longer than usual, but they assumed it was due to resourcing constraints on OOPS' end. PANIC consented to OOPS providing FBI with a copy of the Docker image in question.

 > Analyze the provided Docker image and identify the actor's techniques.

##### And you are given:

    PANIC Nightly Build + Test Docker Image (image.tar)

##### And the flags are:

  Enter the email of the PANIC employee who maintains the image:
  Enter the URL of the repository cloned when this image runs:
  Enter the full path to the malicious file present in the image:

##### Overview of how challenge was completed:
The tar image given is a complete docker image. Opening up the tar image and looking through the configuration json files gives the first flag. Then looking at the commands ran at startup gives a script that downloads the github repo from the link and the name of the malicius file. At this point, unpacking all of the layier 2 tar files and using find gives the full path.

#### Task 6
[Full Writeup](task06/writeup.md)

##### The challenge discription is as follows:

 > Now that we've found a malicious artifact, the next step is to understand what it's doing. Identify some characteristics of the communications between the malicious artifact and the LP.


And you are given no new files

##### And the flags are:

  Enter the IP of the LP that the malicious artifact sends data to
  Enter the public key of the LP (hex encoded)
  Enter the version number reported by the malware

##### Overview of how challenge was completed:

Drop the binary file into a reverse engineering program. After analizing source code, it becomes clear which functions are called to give the flags. At this point run the program in GDB (which needs to be installed on the docker image) and simply call the functions that give the flags.


### Detection and defense of attacks
It is important to note that the senirio given assumes that the NSA had already compromised the malicus listening post and captured the packets to discover the comprimise. This is unrilistic for the average company as it is illigal to attack suspected mallisuous servers in the US. However, it is perfectly resonable for this whole thing to be kicked off by susspicus communication to an unknown server by several computers within a controled corporate network. 


#### task1
##### Attackers Avoidance
##### Improve Defence
#### task2
##### Attackers Avoidance
##### Improve Defence
#### task3
##### Attackers Avoidance
##### Improve Defence
#### task4
##### Attackers Avoidance
##### Improve Defence
#### task5
##### Attackers Avoidance
In this case the malware was detected on the machine due in part of guessing based on the nature of CTF's. If this wasn't the case it would have been possible to hide the malware better. This obvipously would mean stripping the binary so that it does not stand out. However, editing a known binary such as make leaves the attacker vulnerable to programs such as debsums which compares the hash of all of the binaries on the computer to a known good one on a remote system. This would be possible to get around however by infecting some underlying code needed in checking the hash. The idea behind this was first stated in an paper by Ken Thompson [on trusting trust](https://www.cs.cmu.edu/~rdriley/487/papers/Thompson_1984_ReflectionsonTrustingTrust.pdf). By infecting the debsums equivelent it would be possible to hard code it to always return that debsums is correct. If there is not a debsums type application installed trojonizing make would work just fine
##### Improve Defence
The main defenses against trojinized binarys that we looked at in this challenge is cryptographic signatures and certificats. The idea would be using known good hashes for each binary to check against. If any of the binaries were edited to make them malicuis then the hashes would change. It would also be possible to sign the docker image itself with a gpg key. Assuming that the attackers did not find this key on the server, they would be unable to change anything in the docker image without breaking the signature attached to it.
#### task6
##### Attackers Avoidance
From the attacker side, the same advantages from task 5 apply, however with a larger focus on obfuscating the code. To a certian extent, you have to assume that your malware will eventiaully be found by the defenders. At this point obfuscation and packing are incredibly important and many different methiods could be used. Static analis could be made significantly more difficult by using layers of encryption and encoding that slowly undoes itself each round. This would even be more effective if the entire binary is never un encrypted at any one time to hinder dynamic analisis. Another ideal would be requieing the malware to retrieve a remote key. This could mean that if you suspect your malware is about to be or already has been captured you can stop serving up the key. If the defenders haven't captured the key yet the sample may be useless.
##### Improve Defence
Malware anlising in this case is an incredibly interesting a detail driven job. A couple of the important things that would help the defender in this case are detailed log files and a large amount of time and extra resources to work on this project. There is a direct corrilation between how much time an alisit is able to put into a problem and how much information they are able to get out of it. In this case, it may make sense for the company to stop looking at the malware after task 6 and they know what it is doing. In fact there may even be enough to create an AV rule that detects similar implants and that is good enough for many companies. However, deeper analisis (as done in the solo tasks) can help give an much deeper understand of the ATP that we are dealing with and gives a chance to bring them to justice. The additonal liog files mentioned as will would be important to both detect the attack and to store a key sent over te wire if the malware uswed encryption as  mentioned abouve.
