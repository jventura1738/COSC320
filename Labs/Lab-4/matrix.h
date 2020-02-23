/* 
 * Justin Ventura, 02/23/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Matrix.h
*/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
    // Pointer to the matrix array.
    float * M;

    // Keep track of the rows & columns.
    size_t row;
    size_t col;

    /* (CON/DE)STRUCTORS ETC */

    // Default Constructor.
    // Allocates a 1 x 1 matrix.
    Matrix();

    // Regular Constructor.
    // Allocates a matrix with the given dimensions.
    Matrix(size_t & n = 1, size_t & m = 1) : row(n), col(m);

    // Copy Constructor.
    // Allocates a copy of a given matrix.
    Matrix(Matrix * rhs);

    // De-structor.
    // Frees memory of a matrix out of scope.
    ~Matrix();

    // Overloaded Assignment operator.
    // Allocates a copy matrix by assignment.
    Matrix * operator=(Matrix * rhs);

    /*
     * MATRIX OPERATORS (OVERLOADED):
     * Addition, Subtraction, Scalar &
     * Matrix Mulitiplications, and
     * Strassens's Algorithm.
    */

    // Matrix Addition.
    // Require: A = B = Matrix[n x m].
    Matrix * operator+(Matrix * A, Matrix * B);

    // Matrix Subtraction.
    // Require: A = B = Matrix[n x m].
    Matrix * operator-(Matrix * A, Matrix * B);

    // Matrix Scalar Multiply.
    Matrix * operator*(Matrix * A, size_t scalar);

    // Matrix Multiplication.
    // Require: A = Matrix[n x m]
    //          B = Matrix[m x k]
    // Return:  C = Matrix[n x k]
    Matrix * operator*(Matrix * A, Matrix * B);

    // Strassen's Algorithm for Matrix
    // Multiplication.
    Matrix * StrassenMultiply(Matrix * A, Matrix * B);

    // Additional Print Method.
    void print();
};

#endif