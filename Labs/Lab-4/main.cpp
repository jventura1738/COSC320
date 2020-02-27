/* 
 * Justin Ventura, 02/25/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Main.cpp
*/

// Necessities.
#include "matrix.h"
#include "timer.h"

// Used for basic formatting and stuff.
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <chrono>
#include <algorithm>

// Randomly generates a matrix of the given object dimensions.
void init_matrix(Matrix & A);

// Makes all elements off main diagonal 0's.
void diagonal(Matrix & A);

// Makes all elements above diagonal 0's.
void uppertri(Matrix & A);

// Makes all elements below diaginal 0's.
void lowertri(Matrix & A);

// Converts A to the identity matrix.
void init_identity(Matrix & A);

int main () {
    Matrix a(10, 10);

    init_matrix(a);
    Matrix temp = a;

    std::cout << "Matrix A: \n";
    a.print();

    std::cout << "Diagonal A:\n";
    diagonal(a);
    a.print();

    a = temp;

    std::cout << "Upper Triangle A:\n";
    uppertri(a);
    a.print();

    a = temp;

    std::cout << "Lower Triangle A:\n";
    lowertri(a);
    a.print();

    a = temp;

    std::cout << "Identity matrix:\n";
    init_identity(a);
    a.print();


    // std::cout << "Matrix B: \n";
    // b.print();

    // std::cout << "Matrix A + Matrix B: \n";
    // c.print();

    // std::cout << "Matrix A - Matrix B: \n";
    // c = a - b;
    // c.print();

    return 0;
}

// Randomly generates matrix of the given object dimensions.
void init_matrix(Matrix & A) {

    // Random seed for generating random matrix.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    for (size_t i = 0; i < A.len; i++) {

        A.M[i] = (rand() % 9) + 1;

    }

    // Shuffle the array in a random order.
    std::shuffle(A.M, A.M + A.len, std::default_random_engine(seed));
}

// Makes all elements off main diagonal 0's.
void diagonal(Matrix & A) {

    for (size_t i = 0; i < A.row; i++) {

        for (size_t j = 0; j < A.col; j++) {

            // Any spot of the A[i,j] diagonal should be zero.
            if(i != j) {
                A.M[i * A.col + j] = 0;
            } 

        }

    }

}

// Makes all elements above diagonal 0's.
void uppertri(Matrix & A) {

    // No change to a vector.
    if (A.col == 1) return;

    // A[0,0] is main diagonal, so shift by
    // j.
    size_t i = 0, j = 1;

    // Be sure not to seg fault.
    // Stops after triangle is complete.
    while (i < A.row) {

        // Start the upper triangle.
        A.M[i * A.col + j] = 0;
        j++;

        // If the row is complete, move to the next.
        if ((i * A.col + j) >= ((i + 1) * A.col)) {
            i++;
            j = i + 1;
        }

    }

}

// Makes all elements below diaginal 0's.
void lowertri(Matrix & A) {

    // Start at row 1 instead of row 0 since
    // row 0 has the main diagonal.
    size_t i = 1, j = 0;

    // Start from row 1 and go down to row
    // A.row - 1.
    while (i < A.row) {

        // Start the lower triangle.
        A.M[i * A.col + j] = 0;
        j++;

        // If the row is complete, move to the next.
        if (i == j) {
            i++;
            j = 0;
        }

    }

}

// Converts A to the identity matrix.
void init_identity(Matrix & A) {

    // Create zeroes around the diagonal.
    uppertri(A);
    lowertri(A);

    // Slide down the main diagonal assign 1's.
    size_t i = 0, j = 0;

    // This buffer is to account for all cases, such that
    // regardless of the dimensions of the matrix, there
    // will be no incorrect jumps or seg faults.
    size_t buffer = (A.row >= A.col) ? A.col : A.row;
    while (i < buffer) {

        A.M[i * A.col + j] = 1;
        i++;
        j++;

    }

}

