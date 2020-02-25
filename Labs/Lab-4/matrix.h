/* 
 * Justin Ventura, 02/23/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Matrix.h
*/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/*
 * INDEXING: I * COL + J
*/

class Matrix {
public:
    // Pointer to the matrix array.
    // Constructors will take care of allocations,
    // if you free or allocate otherwise, the memory
    // risks are now all up to you.
    float * M;

    // Keep track of the rows & columns.
    size_t row;
    size_t col;
    size_t len;

    /* 
     * (CON/DE)STRUCTORS ETC.
     * All memory (de)allocations are taken care of
     * in these functions.  No need to allocate or
     * free any yourself.  The matrix is public
     * if you choose to manage the memory by yourself, 
     * but you must be aware of the memory risks.
    */

    // Default Constructor. [MEMORY ALLOCATION]
    // Allocates a 1 x 1 matrix.
    // This allocation prevents the AO from attempting
    // to free non-allocated memory.
    Matrix();

    // Regular Constructor. [MEMORY ALLOCATION]
    // Allocates a matrix with the given dimensions.
    Matrix(size_t & n, size_t & m);

    // Copy Constructor. [MEMORY ALLOCATION]
    // Allocates a copy of a given matrix.
    Matrix(const Matrix * rhs);

    // De-structor. [MEMORY DE-ALLOCATION]
    // Frees memory of a matrix out of scope.
    ~Matrix();

    // Overloaded Assignment operator. [MEMORY ALLOCATION]
    // Allocates a copy matrix by assignment.
    void * operator=(const Matrix * rhs);

    /*
     * MATRIX OPERATORS (OVERLOADED):
     * Addition, Subtraction, Scalar &
     * Matrix Mulitiplications, and
     * Strassens's Algorithm.
    */

    // Matrix Addition.
    // Require: A(this) = B = Matrix[n x m].
    Matrix * operator+(const Matrix * B);

    // Matrix Subtraction.
    // Require: A(this) = B = Matrix[n x m].
    Matrix * operator-(const Matrix * B);

    // Matrix Scalar Multiply. [EXTRA CREDIT]
    // Multiplies the scalar to each element in matrix.
    Matrix * operator*(size_t & scalar);

    // Matrix Multiplication.
    // Require: A(this) = Matrix[n x m]
    //          B       = Matrix[m x k]
    // Return:  C       = Matrix[n x k]
    Matrix * operator*(const Matrix * B);

    // Strassen's Algorithm for Matrix
    // Multiplication.
    // Require: A = Matrix[n x m]
    //          B = Matrix[m x k]
    // Return:  C = Matrix[n x k]    
    Matrix * StrassenMultiply(const Matrix * A, const Matrix * B);

    // Additional Print Method.
    // This prints this->M in matrix form.
    void print();
};

#endif