# Source Code Directory

This directory contains all source code used in our implementation of the simulation.

## File Information:

### Simulation Files Included & Run Instructions:

- RandomWalk.cpp: where the random walk is simulated, and data is collected!
- Interface header and cpp: used as helpers for the RandomWalk.cpp
- Graph header and cpp: the data structure of choice for this problem is a Graph.
- makefile: please refer to the instructions below on how to run!

In order to create the object (.o) files necessary for execution, simply type 'make.'  Then there will be an executable file called 'randomwalk' which can be run with an additional argument (a .txt file) which will be used to shoving output to.  Note that whatever file you pass in will be erased and replaced!  If you want many tests done, the program will prompt you in the terminal for how many simulations you would like done.  If you choose not to pass in an argument, then the program will simply output to the terminal.  To remove all executables and .o files, run 'make clean'.
