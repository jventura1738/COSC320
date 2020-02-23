#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
    // Pointer to the matrix.
    float * M;

    // Keep track of the rows & columns.
    size_t row;
    size_t col;

};

#endif