/* 
 * Justin Ventura, 02/23/20
 * COSC320-002, Dr. Anderson
 * Project 1: matrix.cpp
*/

// Header file.
#include "matrix.h"

// Formatting and terminal colors.
#include <iomanip>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define WHITE   "\033[37m"      /* White */
#define BOLDON  "\e[1m"
#define BOLDOFF "\e[0m"

// Default Constructor.
Matrix::Matrix() {
	//std::cout << YELLOW << "Matrix allocated (default).\n" << RESET;
	this->row = 1;
	this->col = 1;
	this->len = 1;
	this->M = new float[1];
}

// Main Constructor.
Matrix::Matrix(const size_t & n, const size_t & m) {
	if (n < 1 || m < 1) {
		throw std::string("\e[1m \033[31m Exception: matrix dimensions must be >= 1.\n \033[0m \e[0m");
	}
	//std::cout << YELLOW << "Matrix allocated (main).\n" << RESET;
	this->len = n * m;
	this->M = new float[this->len];
	this->row = n;
	this->col = m;
}

// Matrix Copy Constructor.
Matrix::Matrix(const Matrix * rhs) {
	//std::cout << YELLOW << "Matrix allocated (copy construct).\n" << RESET;
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
	//std::cout << "\n--MATRIX [AO] ALLOCATED--\n";
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
		throw std::string("\e[1m \033[31m Exception: addition only defined for matrices with same dimensions.\n \033[0m \e[0m");
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
		throw std::string("\e[1m \033[31m Exception: subtraction only defined for matrices with same dimensions.\n \033[0m \e[0m");
	}
	
	Matrix C(A.row, A.col);

	// Algorithm: C[n,m] = this[n,m] + B[n,m],
	// where n is # rows, m is # cols.

	for (size_t i = 0; i < C.len; i++)
		C.M[i] = A.M[i] - B.M[i];

	return C;
}

// Scalar Multiplication
Matrix operator*(const Matrix & A, const float & scalar) {

	Matrix C(A.row, A.col);

	for(size_t i = 0; i < C.len; i++) {
		C.M[i] = A.M[i] * scalar;
	}

	return C;
}

// Regular Matrix Multiplication.
Matrix operator*(const Matrix & A, const Matrix & B) {

	// Matrix A.col must equal B.rows

	if (A.col != B.row) {
		throw std::string("\e[1m \033[31m Exception: matrix A cols must equal matrix B rows for matrix multiplication.\n \033[0m \e[0m");
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

// Matrix Transposition Operation.
Matrix Matrix::transpose() {
		
	Matrix temp(this->col, this->row);

	// Algorithm: simply swap i & j and
	// row & col. 

	for (int i = 0; i < temp.col; i++) {

		for (int j = 0; j < temp.row; j++) {

			temp.M[i * temp.row + j] = this->M[j * temp.col + i];

		}
	
	}

	return temp;
}

// Matrix print method (PERFECT FORMATTING; SLOW).
void Matrix::print() {

	/*
	 * Nested loops to print out the array in
	 * its matrix form; each col per row since 
	 * I am using a 1D "flat" array.  We will also
	 * find the number with the most digits,
	 * then count it's total digits, and format
	 * the matrix accordingly.
	*/

	// Find the largest number.
	size_t maxIndex = 0;
	for (size_t i = 1; i < this->len; i++) {

		if (this->M[i] > this->M[maxIndex]){

			maxIndex = i;

		}

	}

	// Now count it's digits then use this to
	// generalize the matrix's spacing format.
	int max = this->M[maxIndex];
	size_t spacing = 0;

	while (max >= 1) {

		// division hacks
		max /= 10;
		spacing++;

	}

	std::cout << WHITE; //<< std::setfill('0') << std::setw(spacing);

	// Nested looping begins.
	for (size_t i = 0; i < this->row; i++) {

		// print the row of the matrix.
		for (size_t j = 0; j < this->col; j++) {
            
			std::cout << std::setfill('0') << std::setw(spacing)
			<< this->M[i * this->col + j] << " ";

		}

    	// new line for the next row in matrix.
		std::cout << "\n";

	}

	std::cout << RESET << "\n";

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

	// Refreshes the matrix to default.
	delete [] this->M;
	this->row = 1;
	this->col = 1;
	this->len = 1;
	this->M = new float[1];

}