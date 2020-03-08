/* 
 * Justin Ventura, 03/07/20
 * COSC320-002, Dr. Anderson
 * Project 1: driver.cpp
*/

#include <iostream>
#include "matrix.h"
#include "jspace.h"

// Makes all elements above diagonal 0's.
void uppertri(Matrix & A) {

    // No change to a vector.
    if (A.col == 1) return;

    // A[0,0] is main diagonal, so shift by
    // j.
    size_t i = 0, j = 1;

    // Be sure not to seg fault.
    // Stops after triangle is complete.
    size_t buffer;

    if (A.col < A.row) {

        buffer = (A.col - 1) * A.col + (A.col + 1);

    }
    else if (A.col > A.row) {

        buffer = (A.row - 1) * A.col + (A.col - 1);

    }
    else {

        buffer = (A.col - 2) * A.col + (A.col - 1);

    }

    // Create the triangle.
    while ((i * A.col + j) <= buffer) {

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
    while ((i * A.col + j) < A.len) {

        // Start the lower triangle.
        A.M[i * A.col + j] = 0;
        j++;

        // If the row is complete, move to the next.
        if (i == j || j >= (A.col)) {

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

int main() {

	Matrix A(3,3);
	Matrix I(3,3);
	Matrix d(3, 1);

	A.M[0] = 0.6;
	A.M[1] = 0.2;
	A.M[2] = 0.1;
	A.M[3] = 0.3;
	A.M[4] = 0.2;
	A.M[5] = 0.4;
	A.M[6] = 0.2;
	A.M[7] = 0.4;
	A.M[8] = 0.3;
	init_identity(I);
	d.M[0] = 20;
	d.M[1] = 34;
	d.M[2] = 80;

	std::cout << "test:\n";
	A.print();
	I.print();
	d.print();

	std::cout << "\nresult\n";
    Matrix term1 = (I - A);
    Matrix term2 = term1.inverse();
	Matrix result = term2 * (d);
	result.print();

	return 0;

}