/* 
 * Justin Ventura, 02/23/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Matrix.cpp
*/

#include "matrix.h"

// Default Constructor.
Matrix::Matrix() {
	std::cout << "Matrix created.\n";
	std::cout << "Not allocated.\n";
}

// Main Constructor.
Matrix::Matrix(size_t & n, size_t & m) {
	this->M = new float[n * m];
	
}

// Matrix Assignment Operation
void Matrix::operator=(const Matrix *A) {

	// De-allocate old matrix pointer.
	// std::cout << "\n--MATRIX [AO] ALLOCATED--\n";
	delete this->M;
	this->row = A->row;
	this->col = A->col;

	// Copy from A.M to re-allocated this->M.
	size_t *len = new size_t(this->row * this->col);
	this->M = new float[*len];

	for (size_t i = 0; i < *len; i++)
		this->M[i] = A->M[i];
	delete len;
}


void Matrix::print() {

	for (size_t i = 0; i < this->row; i++) {

		for (size_t j = 0; j < this->col; j++) {
            
            // print the row of the matrix
			std::cout << this->M[i * this->col + j] << " ";

		}
        // new line for the next row in matrix.
		std::cout << "\n";
	}
	std::cout << "\n";

}

