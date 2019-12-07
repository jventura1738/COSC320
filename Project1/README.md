# COSC320 Project 1: Linear Least Squares

Project by Justin Ventura.

Dr. Joseph Anderson.


## Application Information

There are two executables included: 'linearleastsquares' and 'matrixDriver'.  The former can be run with a text file full of data to find the optimal vector, B.  The latter is used to confirm that my matrix class works and is fully functional.

Run the progams with the following linux commands: './linearleastsquares.exe <data.txt>' and './matrixDriver'.

### Extra Credit

I did my best on making the code as efficient as possible in terms of run-time and memory usage.  I also checked for memeory leaks with valgrind and have found none.  The only constraints are the limits to the size of the data-types which is out of my control.  (10), (5), (2) or none.


Tested for non-singular matrix in the class. Out put is in the 'matrixDriver'(5)


Added a test for non-symmetric matrices, then made possible to invert the non-symmetric square matrix by computing the following: A^-1 = (A^T * A)^-1 * A^T where (A^T * A) is guaranteed to be symmetric. (10)


Strassen's Algorithm for matrix multiplication implemented.
