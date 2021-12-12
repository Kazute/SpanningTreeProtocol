# SpanningTreeProtocol

A simple implementation to show how the spanning tree protocol works in layer 2 devices through the use of BPDU packets. It shows how the protocol can be exploited using the popular tool Yersinia.

# Compiling with G++

```
g++ -LC -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Stp.d" -MT"src/Stp.o" -o "src/Stp.o" "../src/BPDU.cpp"
```
