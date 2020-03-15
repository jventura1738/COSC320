# Leontief Input-Output Model Calculation

by Justin Ventura (for Dr. Joe T. Anderson)

Project 1 COSC320 - 002

## Specifications.

This Project uses linear algebra to go through calculating the total output required per sector (in vector form) in the Input-Output model created by Wassily Leontief for economic use.  The model represents interdependencies between different sectors of a national economy or different regional economies.  The inputs for this model are the different sectors, then the correspending amounts of a certain industrial resource (a given row) which should amount to the corresonding "row" in the demand vector.  This can be modeled as: (In - A)^-1 * d where In is the n dimensions Identity matrix, A is the matrix of values required (a row) of certain resources to meet the demand in the column vector, d which is n x 1, all of which where n is the number of differenct sectors.  This model requires A to be square and nonsingular in order to follow through with this calculation.


The following implementations were included in order to go through with this whole process of modeling and calculating the output required in, the IOModel.


- asodjfldkf
- sldfals
