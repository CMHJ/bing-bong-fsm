# Bing Bong FSM

Simple example of a set of services akin to micro-services implemented as
Finite State Machines.
Just a simple toy example.

Each message simply prints a message, nothing more.
The number of cycles is a fixed number so that it doesn't run forever.

Currently the services are given a reference to other services that they need
to communicate with.
An improvement would be to implement some sort of messaging system that allows
the services to communicate with each other without holding a direct reference.

## Build

```
mkdir build
cd build
cmake ..
make
```