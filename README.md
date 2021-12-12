# SpanningTreeProtocol

A simple implementation to show how the spanning tree protocol works in layer 2 devices through the use of BPDU packets. It shows how the protocol can be exploited using the popular tool Yersinia.

Since the BPDU packets require no authentication (including the more recent Rapid Spanning Tree Protocol) it's possible to trick bridges by claiming root. This makes it possible (in theory) to snoop traffic and cause trouble in a netwok. Even worse, since there is often a general assumption that layer 2 traffic (internal device traffic) should be safe, there may be no logging of suspicious activity. 

## BPDU frame

 ----------------------------------------------
 |Offset  |Name                       |Size   |
 ----------------------------------------------
 ----------------------------------------------
 |1       |Protocol Identifier        |2 bytes|
 ----------------------------------------------
 |        |Protocol Version Identifier|1 byte |
 ----------------------------------------------
 |        |BPDU type                  |1 byte |
 ----------------------------------------------
 |        |Flags                      |1 byte |
 ----------------------------------------------
 |        |Root Identifier            |8 bytes|
 ----------------------------------------------
 |        |Root Path Cost             |4 bytes|
 ----------------------------------------------
 |        |Bridge Identifier          |8 bytes|
 ----------------------------------------------
 |        |Port Identifier            |2 bytes|
 ----------------------------------------------
 |        |Message Age                |2 bytes|
 ----------------------------------------------
 |        |Max Age                    |2 bytes|
 ----------------------------------------------
 |        |Hello Time                 |2 bytes|
 ----------------------------------------------
 |35      |Forward Delay              |2 bytes|
 ----------------------------------------------

# Compiling with G++

```
g++ -LC -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Stp.d" -MT"src/Stp.o" -o "src/Stp.o" "../src/BPDU.cpp"
```
