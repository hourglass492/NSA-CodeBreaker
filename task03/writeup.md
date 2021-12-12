### First Insights

At this point in the investigation we know that a machine associated with Online Operations and Production Servicest (OOPS) company has communicated with the foreign Listening Post. From the previous task, we were able to identify the employee associated with the account on the machine. During an incident response interview, the user mentioned that they were checking email around the time that the communication occured. They stated that they did not remember anything weird that occured while checking email. The led OOPS to provide us with a subset of the user's inbox from the day of the incident.

### Beginning the Investigation

Starting with the provided collection of 24 emails, the inital thought was to check the content of the emails for malicious links or files. A few of the suspected emails are contained within this task's directory. After checking the links contained in emails, there was no lead to a malicious actor as there domain of the links did not match the Wireshark capture from Task 1. The next step was to identify an email with a malicious attachment. After doing research on [email attachments](https://en.wikipedia.org/wiki/Email_attachment), it was found that the files are encoded in Base64 and malware is commonly attached, pointing us in the correct direction. 
