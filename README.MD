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
    - Complete Challenges 1-6 (excluding 4)
    - Final Documentation Writting
    - Challenge write-ups for: 5
  - Seth 
    - Complete Challenges TBD
    - Final Documentation Writing
    - Challenge write-ups for TBD
  - Nitin 
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
The challenge discription is as follows:

> The NSA Cybersecurity Collaboration Center has a mission to prevent and eradicate threats to the US Defense Industrial Base (DIB). Based on information sharing agreements with several DIB companies, we need to determine if any of those companies are communicating with the actor's infrastructure.

> You have been provided a capture of data en route to the listening post as well as a list of DIB company IP ranges. Identify any IPs associated with the DIB that have communicated with the LP.

And you are given:
    
    Network traffic heading to the LP (capture.pcap)
    DIB IP address ranges (ip_ranges.txt)

Overview of how challenge was completed:

#### Task 2
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
The challenge discription is as follows:
 > With the provided information, OOPS was quickly able to identify the employee associated with the account. During the incident response interview, the user mentioned that they would have been checking email around the time that the communication occurred. They don't remember anything particularly weird from earlier, but it was a few weeks back, so they're not sure. OOPS has provided a subset of the user's inbox from the day of the communication.
 > Identify the message ID of the malicious email and the targeted server.


And you are given:

    User's emails (emails.zip)

Overview of how challenge was completed:


#### Task 4
The challenge discription is as follows:
 > A number of OOPS employees fell victim to the same attack, and we need to figure out what's been compromised! Examine the malware more closely to understand what it's doing. Then, use these artifacts to determine which account on the OOPS network has been compromised.




And you are given:

    OOPS forensic artifacts (artifacts.zip)
    
And the flags are

    The name of the machine the attackers can now access
    The username the attackers can use to access that machine  
   
   
Overview of how challenge was completed:

#### Task 5
The challenge discription is as follows:

 > A forensic analysis of the server you identified reveals suspicious logons shortly after the malicious emails were sent. Looks like the actor moved deeper into OOPS' network. Yikes.

 > The server in question maintains OOPS' Docker image registry, which is populated with images created by OOPS clients. The images are all still there (phew!), but one of them has a recent modification date: an image created by the Prevention of Adversarial Network Intrusions Conglomerate (PANIC).

 > Due to the nature of PANIC's work, they have a close partnership with the FBI. They've also long been a target of both government and corporate espionage, and they invest heavily in security measures to prevent access to their proprietary information and source code.

 > The FBI, having previously worked with PANIC, have taken the lead in contacting them. The FBI notified PANIC of the potential compromise and reminded them to make a report to DC3. During conversations with PANIC, the FBI learned that the image in question is part of their nightly build and test pipeline. PANIC reported that nightly build and regression tests had been taking longer than usual, but they assumed it was due to resourcing constraints on OOPS' end. PANIC consented to OOPS providing FBI with a copy of the Docker image in question.

 > Analyze the provided Docker image and identify the actor's techniques.

And you are given:

    PANIC Nightly Build + Test Docker Image (image.tar)

And the flags are:

  Enter the email of the PANIC employee who maintains the image:
  Enter the URL of the repository cloned when this image runs:
  Enter the full path to the malicious file present in the image:

Overview of how challenge was completed:

#### Task 6
The challenge discription is as follows:

 > Now that we've found a malicious artifact, the next step is to understand what it's doing. Identify some characteristics of the communications between the malicious artifact and the LP.


And you are given no new files

Overview of how challenge was completed:

### Detection and defense of attacks
It is important to note that the senirio given assumes that the NSA had already compromised the malicus listening post and captured the packets to discover the comprimise. This is unrilistic for the average company as it is illigal to attack suspected mallisuous servers in the US. 


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
##### Improve Defence
