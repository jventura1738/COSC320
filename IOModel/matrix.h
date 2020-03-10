/* 
 * Justin Ventura, 03/07/20
 * COSC320-002, Dr. Anderson
 * Project 1: matrix.h
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
private:
    // Private method to determine whether the matrix is
    // singular or not.  If it is singular, return true.
    // [EXTRA CREDIT, GIVE ME POINTS PLSSSSSS]
    bool isSingular();

    // Private method to determine whether the matrix is
    // symmetric or not.  If it is symmetric, return true.
    bool isSymmetric();

    // Private mthod to determine if this matrix is in
    // need of padding.  True if needs padding.
    bool needsPadding() const;

    // Returns the cofactor at given dimensions.
    float cofactorAt(size_t i, size_t j);

    // Returns the determinant of the matrix.
    float determinant();

    // Inverse of matrix.  This version does all
    // the "dirty" work.  The public version
    // asserts that the matrix is invertible 
    // before the actual inversion takes place, 
    // in this function.
    Matrix _inverse();

public:

    // Pointer to the matrix array.
    // Constructors will take care of allocations, so
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

    // Matrix Scalar Multiply.
    // Multiplies the scalar to each element in matrix.
    friend Matrix operator*(const Matrix & A, const float & scalar);

    // Matrix Multiplication.
    // Require: A = Matrix[n x m]
    //          B = Matrix[m x k]
    // Return:  C = Matrix[n x k]
    friend Matrix operator*(const Matrix & A, const Matrix & B);

    // Matrix Transposition Method.
    Matrix transpose();

    // Matrix Padding Method.
    Matrix pad();

    // Matrix Inversion Method.  This will calculate
    // the inverse of the matrix which calles this
    // method.
    // Throws various std::strings for errors in
    // which the inverse is not defined.
    Matrix inverse();

    // Strassen's Algorithm for Matrix
    // Multiplication.
    // Require: A = Matrix[n x m]
    //          B = Matrix[m x k]
    // Return:  C = Matrix[n x k]    
    // Matrix StrassenMultiply(const Matrix * A, const Matrix * B);

    // Additional Print Method.
    // This prints this->M in matrix form, such that
    // the format is perfect.  This will affect the
    // runtime negatively but looks clean.
    void print();

    // Prints with no format.
    void print2();

    // Additional method to "soft" reset the matrix values
    // to consist of all zeroes. Initial size remains constant.
    void softreset();

    // Additional method to "hard" reset the matrix back to an
    // empty 1 x 1.
    void hardreset();
};

#endif