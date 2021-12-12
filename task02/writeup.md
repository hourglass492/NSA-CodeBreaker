### First Insights

After finihsing Task 1, we now know roughly 4 IP addresses in relation to the DIB companies that have communicated with the LP. One of the reporting companies *Online Operations and Production Services* (OOPS) has provided us with their network proxy logs, login data, and which subnet was associated with their company. The task is to now narrow down the logon ID of the user that communicated with the LP.

### Starting the Task

To begin we will need to look at the subnet for OOPS, which was given in the *oops_subnet.txt* file:

```
172.17.130.0/23
```

Now that we have the subnet we will match it with one of the IPs we flagged in Task 1. In my case, the only IP that matched was *172.17.130.222* which sent out an HTTP request. Viewing the pcap file in Wireshark, we can figure out the time this request was sent: *12:13:09* in UTC +0. We now have enough information to move onto the porxy file.

### Viewing the Proxy Logs
