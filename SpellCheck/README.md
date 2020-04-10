# Justin's SpellCheck with Hashing.

by Justin Ventura (Dr. Joe Anderson)

2/3 EXTRA CREDIT COMPLETED.

## Specifications.

This Project uses linear algebra to go through calculating the total output required per sector (in vector form) in the Input-Output model created by Wassily Leontief for economic use.  The model represents interdependencies between different sectors of a national economy or different regional economies.  The inputs for this model are the different sectors, then the correspending amounts of a certain industrial resource (a given row) which should amount to the corresonding "row" in the demand vector.  This can be modeled as: (In - A)^-1 * d where In is the n dimensions Identity matrix, A is the matrix of values required (a row) of certain resources to meet the demand in the column vector, d which is n x 1, all of which where n is the number of differenct sectors.  This model requires A to be square and nonsingular in order to follow through with this calculation.


The following implementations were included in order to go through with this whole process of modeling and calculating the output required in, the IOModel.

- Matrix class (n x m) with functions/overloads included for Matrix Addition, Subtraction, Scalar Multiplication, Matrix Multiplication, "isSymmetric" method, and Matrix Transposition.
- Matrix Inversion function which accurately calculates the inverse of a given matrix (assuming it is non-singular, otherwise gracefully throws an error of std::string) using a divide & conquer algorithm which was explained in the project prompt. This function calls the "isSingular" method which does a check for A being square, symmetric (if not symmetric it will undergo a process to fix this), and a non-zero determinant.
- This inversion requires the matrix to be a matrix of dimensions n x n where n is a power of 2. If it is not a power of 2, then the matrix will be padded to the nearest power of 2 greater than n, then unpadded when the inversion is complete.
- EXTRA CREDIT: (20pts) Strassen's Algorithm for Matrix Multiplication, (5pts) Determinant/Cofactor Calculation involved in finding Non-Singular Matrices


Also note that my matrix inversion is not very fast due to the determinant calculation which has a worst case of O(n!).

## README:

Instructions to run the programs (also located in makefile):
- To create the object files & executables: 'make'
- To run memory checks for the main: 'make memcheck'.  The latter will run with english.txt by default.  If you wish to use your own files, simply use your own commands such as: 'valgrind ./spellcheck <filename>' or 'valgrind ./iomodel <file>'
- NOTE: you may only do one file argument.
  
### Hashing Description & Tests:

Time complexities on valid matrices of dimensions (m x n):
- Addition & Subtraction -> O(m * n)
- Scalar Multiplication -> O(m * n)
- Matrix Multiplication -> O(m^3)
- Strassen's Algorithm -> O(m^2.8)
- Matrix Determinant -> O(n!)

### EXTRA CREDIT!

- I have implemented the highlight for showing mispelled words (5pts).
- I also implemented a feature where the user can choose to add the mispelled words to the dictionary, or add their own (ie. pick from the suggestion list).  
