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
 * Don't mess with deletes and news,
 * all of that is done for you.
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
    // NOTE: does not assign any values to the matrix.
    Matrix();

    // Regular Constructor. [MEMORY ALLOCATION]
    // Allocates a matrix with the given dimensions.
    // NOTE: does not assign any values to the matrix.
    // Exceptions: will throw std::string if n, m < 1.
    Matrix(const size_t & n, const size_t & m);

    // Copy Constructor. [MEMORY ALLOCATION]
    // Allocates a copy of a given matrix.
    Matrix(const Matrix & rhs);

    // De-structor. [MEMORY DE-ALLOCATION]
    // Frees memory of a matrix out of scope.
    ~Matrix();

    // Overloaded Assignment operator. [MEMORY ALLOCATION]
    // Allocates a copy matrix by assignment.
    void operator=(const Matrix & rhs);

    /*
     * MATRIX OPERATORS (OVERLOADED):
     * Addition, Subtraction, Scalar &
     * Matrix Mulitiplications, and
     * Strassens's Algorithm.
    */

    // Matrix Addition.
    // Require: A(this) = B = Matrix[n x m].
    friend Matrix operator+(const Matrix & A, const Matrix & B);

    // Matrix Subtraction.
    // Require: A(this) = B = Matrix[n x m].
    friend Matrix operator-(const Matrix & A, const Matrix & B);

    // Matrix Scalar Multiply. [EXTRA CREDIT]
    // Multiplies the scalar to each element in matrix.
    friend Matrix operator*(const Matrix & A, const float & scalar);

    // Matrix Multiplication.
    // Require: A = Matrix[n x m]
    //          B = Matrix[m x k]
    // Return:  C = Matrix[n x k]
    friend Matrix operator*(const Matrix & A, const Matrix & B);

    // Strassen's Algorithm for Matrix
    // Multiplication.
    // Require: A = Matrix[n x m]
    //          B = Matrix[m x k]
    // Return:  C = Matrix[n x k]    
    // Matrix * StrassenMultiply(const Matrix * A, const Matrix * B);

    // Additional Print Method.
    // This prints this->M in matrix form.
    void print();

    // Additional method to "soft" reset the matrix values
    // to consist of all zeroes. Initial size remains constant.
    void softreset();

    // Additional method to "hard" reset the matrix back to an
    // empty 1 x 1.
    void hardreset();
};

#endif