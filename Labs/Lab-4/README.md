# COSC320 Lab-3 for Dr. Joe Anderson

by Justin Ventura

## Questions to Answer:

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed for matrix arithmetic.

Matrix addition & subtraction were simple; with my flat array I simply looped through the right-hand matrix and added/subtracted the corresponding value at the index in the left-hand matrix.  The multiplication took a lot more brain power, but the hardest part was definitely the indexing.  I am currently in Linear Algebra so these operations are pretty fresh and intuitive to me.

### B) Analyze your benchmark observations: what does the timing suggest for the time complexity of addition, subtraction, and multiplication for two n × n matrices?

The complexity of the addition and subtraction were obviously linear with respect to n (rows * cols), considering both of the two were simply looping through each matrix (they were of the same size as required for such an operation) performing constant operations.  The timing supported this, and was relatively fast as anticipated.  The matrix multiplication performed at a polynomial rate of O(n^3) where n is the number of rows (or columns, does not matter for an n x n matrix).  This is included in the data on the back of the lab report.

### C) What is the arithmetic time complexity of your implementation of each operation, when done on two n × n matrices? Give tight asymptotic bounds.

Addition & Subtraction: as previously mentioned, the time complexity of these two operations was linear with respect to n [O(n)] where n is the length of the matrix (rows * cols).  Since the matrices must have the same dimensions, there will be no more than n * c operations where c is some constant operations [O(1)]. 

Multiplication: this operation performs in 0(n^3) for two n x n matrices since the three nested loops will start from 0 to n where n is the number of rows (or cols, again does not matter) and will perform some constant number of operations within the loops.  This is definitely slower than Strassen's Algorithm, but we know this to be the naive algorithm.

### D) How could the code be improved in terms of usability, efficiency, and robustness?

Strassen's algorithm would be a good start for faster multiplication.  I was going to do the extra credit, but this week has been astronomically busy due to the immense amount of homework and research I've been doing.  I just couldn't fit it in.
