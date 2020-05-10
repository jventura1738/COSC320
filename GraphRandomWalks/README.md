# Knight's Random Walk Simulation & Analysis

A chess related problem with a purely mathematical solution.

Report by two Salisbury Univerisity Sophomores.

### Collaboration by:

- Justin Ventura (Computer Science, Mathematics, Data Science Majors)
- Jacob Duncan (Computer Science Major, Mathematics Minor)

## Application Description

The "Knight's Random Walk" Problem is a very interesting problem that seems dauntingly difficult to solve at first, but with the use of Markov Chain Theory and Graphs in C++, not only is the problem easily solved with a mathematically proven solution, but is also relatively easy to simulate.  This is one of the many examples of problems that can be made quite simple with the help of mathematical tools.  Looking at problems from another perspective is key in the progression of mathematical research, or any research for that matter.  In this repository you will find the LaTeX report/analysis, and the C++ code used to collect empirical data to support the theoretical results.

### Simulation Files Included & Run Instructions:

- randomwalk.cpp: where the random walk is simulated, and data is collected!
- Interface header and cpp: used as helpers for the RandomWalk.cpp
- Graph header and cpp: the data structure of choice for this problem is a Graph.
- makefile: please refer to the instructions below on how to run!

In order to create the object (.o) files necessary for execution, simply type 'make.'  Then there will be an executable file called 'randomwalk' which can be run with an additional argument (a .txt file) which will be used to shoving output to.  Note that whatever file you pass in will be erased and replaced!  If you want many tests done, the program will prompt you in the terminal for how many simulations you would like done.  If you choose not to pass in an argument, then the program will simply output to the terminal.  To remove all executables and .o files, run 'make clean'.

## Analysis on the Problem:

For a formal analysis, please refer to the following files:

- x.doc: This is the original Research Report document used as a draft to be copied over to LaTeX.  This is pretty up to date, however it is not as cool as the next file.
- x.pdf: This is the final draft of our Research Report & Analysis written in LaTeX.  This includes all sources and citations, data, and source code outputs.  However, if you would like even more outputs, refer to the data.txt!
- x.latex: This is the source code for our LaTeX Report, if for some reason this interests you.
- data.txt: This file contains some of the empirical data collected for viewing purposes.

### Math is fun!
