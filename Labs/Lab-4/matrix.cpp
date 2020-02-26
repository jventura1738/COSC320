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
Matrix::Matrix(size_t & n, size_t & m) {
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