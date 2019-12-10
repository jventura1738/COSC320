// Justin Ventura COSC320
// Project 1: matrix.h
#include "matrix.h"

// Matrix Addition Operation.
Matrix operator+(Matrix &A, Matrix &B) {

	// Matrices must have same dimensions.

	if (A.row != B.row || A.col != B.col) {
		Matrix C(0,0);
		std::cout << "ERROR.\n";
		return C;
	}
	Matrix C(A.row, A.col);
	size_t n = (A.row * A.col);

	// Algorithm: C[m,n] = A[m,n] + B[m,n],
	// where m is # rows, n is # cols.

	for (int i = 0; i < n; i++)
		C.M[i] = (A.M[i] + B.M[i]);

	return C;
}

// Matrix Subtraction Operation.
Matrix operator-(Matrix &A, Matrix &B) {

	// Matrices must have same dimensions.

	if (A.row != B.row || A.col != B.col) {
		Matrix C(0,0);
		std::cout << "ERROR.\n";
		return C;
	}
	Matrix C(A.row, A.col);
	size_t n = (A.row * A.col);

	// Algorithm: C[m,n] = A[m,n] - B[m,n],
	// where m is # rows, n is # cols.

	for (int i = 0; i < n; i++)
		C.M[i] = (A.M[i] - B.M[i]);

	return C;
}

// Matrix Multiplication Operation.
Matrix operator*(Matrix &A, Matrix &B) {

	std::cout << "in operator*\n";

	// Matrix A.col must equal B.rows

	if (A.col != B.row) {
		Matrix C(0, 0);
		std::cout << "ERROR.\n";
		return C;
	}

	Matrix C(A.row, B.col);

	// C[i,j] = summation l=1 to m{ (A[i,l] + B[l,j])
	// where m is A.cols & B.rows.
	// Algorithm: First loop for row A...
	// Second loop for column B...
	// Third loop to sum up the "dot product"
	// of A row i, and B col j. then
	// that sum accumulates to C[i,j].

	for (int i = 0; i < A.row; i++) {

		for (int j = 0; j < B.col; j++) {

			C.M[i * C.col + j] = 0;
			//std::cout << "test1. i: " << i << "\n";

			for (int k = 0; k < A.col; k++) {

				//std::cout << "test2\n";
				C.M[i * C.col + j] += A.M[i * A.col + k] * B.M[k * B.col + j];
			}
		}
	}
	std::cout << "hi3\n";
	return C;
}

// Matrix Transposition Operation.
Matrix Matrix::transpose() {
		
	Matrix temp(this->col, this->row);

	// Algorithm: simply swap i & j and
	// row & col. 
	
	for (int i = 0; i < col; i++) {

		for (int j = 0; j < row; j++) {

			temp.M[i * row + j] = M[j * col + i];
			//std::cout << "i: " << i << " j: " << j;
		}
		//std::cout << "\n";
	}
	return temp;
}
