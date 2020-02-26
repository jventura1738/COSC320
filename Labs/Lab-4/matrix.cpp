/* 
 * Justin Ventura, 02/23/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Matrix.cpp
*/

#include "matrix.h"

// Default Constructor.
Matrix::Matrix() {
	std::cout << "Matrix allocated (default).\n";
	this->row = 1;
	this->col = 1;
	this->len = 1;
	this->M = new float[1];
}

// Main Constructor.
Matrix::Matrix(const size_t & n, const size_t & m) {
	if (n < 1 || m < 1) {
		throw std::string("Exception: matrix dimensions must be >= 1.\n");
	}
	std::cout << "Matrix allocated (main).\n";
	this->len = n * m;
	this->M = new float[this->len];
	this->row = n;
	this->col = m;
}

// Matrix Copy Constructor.
Matrix::Matrix(const Matrix * rhs) {
	std::cout << "Matrix allocated (copy construct).\n";
	this->len = rhs->len;
	this->row = rhs->row;
	this->col = rhs->col;

	this->M = new float[this->len];
	for (size_t i = 0; i < this->len; i++)
		this->M[i] = rhs->M[i];
}

// Matrix Assignment Operation
void Matrix::operator=(const Matrix * rhs) {

	// De-allocate old matrix pointer.
	// std::cout << "\n--MATRIX [AO] ALLOCATED--\n";
	delete [] this->M;
	this->len = rhs->len;
	this->row = rhs->row;
	this->col = rhs->col;

	// Copy A->M to re-allocated this->M.
	this->M = new float[this->len];

	for (size_t i = 0; i < this->len; i++)
		this->M[i] = rhs->M[i];
}

// Destructor.
Matrix::~Matrix() {
	// std::cout << "Matrix de-allocated (destructor).\n";
	delete [] this->M;
}

/*
 * MATRIX OPERATORS (OVERLOADED):
 * Addition, Subtraction, Scalar &
 * Matrix Mulitiplications, and
 * Strassens's Algorithm.
*/

// Matrix Addition Operation.
Matrix operator+(const Matrix & A, const Matrix & B) {

	// Matrices must have same dimensions.
	if (A.row != B.row || A.col != B.col) {
		throw std::string("Exception: addition only defined for matrices with same dimentions.\n");
	}
	
	Matrix C(A.row, A.col);

	// Algorithm: C[n,m] = this[n,m] + B[n,m],
	// where n is # rows, m is # cols.

	for (size_t i = 0; i < C.len; i++)
		C.M[i] = A.M[i] + B.M[i];

	return C;
}

Matrix operator-(const Matrix & A, const Matrix & B) {

	// Matrices must have same dimensions.
	if (A.row != B.row || A.col != B.col) {
		throw std::string("Exception: addition only defined for matrices with same dimentions.\n");
	}
	
	Matrix C(A.row, A.col);

	// Algorithm: C[n,m] = this[n,m] + B[n,m],
	// where n is # rows, m is # cols.

	for (size_t i = 0; i < C.len; i++)
		C.M[i] = A.M[i] - B.M[i];

	return C;
}

// Scalar Multiplication [EXTRA CREDIT]
Matrix operator*(const Matrix & A, const float & scalar) {

	Matrix C(A.row, A.col);

	for(size_t i = 0; i < C.len; i++) {
		C.M[i] = A.M[i] * scalar;
	}

	return C;
}

Matrix operator*(const Matrix & A, const Matrix & B) {

	// Matrix A.col must equal B.rows

	if (A.col != B.row) {
		throw std::string("Exception: matrix A cols must equal matrix B rows.\n");
	}

	Matrix C(A.row, B.col);

	// C[i,j] = summation l=1 to m{ (A[i,l] + B[l,j])
	// where m is A.cols & B.rows.
	// Algorithm: First loop for row A...
	// Second loop for column B...
	// Third loop to sum up the "dot product"
	// of A row i, and B col j. then
	// that sum accumulates to C[i,j].

	for (size_t i = 0; i < A.row; i++) {

		for (size_t j = 0; j < B.col; j++) {

			C.M[i * C.col + j] = 0;
			//std::cout << "test1. i: " << i << "\n";

			for (size_t k = 0; k < A.col; k++) {

				//std::cout << "test2\n";
				C.M[i * C.col + j] += A.M[i * A.col + k] * B.M[k * B.col + j];
			}

		}

	}

	return C;

}

// Matrix print method.
void Matrix::print() {

	/*
	 * Nested loops to print out the array in
	 * its matrix form; each col per row since 
	 * I am using a 1D "flat" array.
	*/

	for (size_t i = 0; i < this->row; i++) {

		// print the row of the matrix.
		for (size_t j = 0; j < this->col; j++) {
            
			std::cout << this->M[i * this->col + j] << " ";

		}
        // new line for the next row in matrix.
		std::cout << "\n";
	}
	std::cout << "\n";

}

// Soft reset (refresh).
void Matrix::softreset() {

	// Replace all indices of the matrix with zeroes.
	for (size_t i = 0; i < this->row; i++) {

		// print the row of the matrix.
		for (size_t j = 0; j < this->col; j++) {
            
			this->M[i * this->col + j] = 0;

		}
	}
}

// Hard reset (full refresh).
void Matrix::hardreset() {
	delete [] this->M;
	this->row = 1;
	this->col = 1;
	this->len = 1;
	this->M = new float[1];
}