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

Matrix::Matrix(size_t & n, size_t & m) {
	this->M = new size_t[n * m];
	
}


Matrix::print() {

	for (size_t i = 0; i < this->row; i++) {

		for (size_t j = 0; j < this->col; j++) {

			std::cout << this->M[i * this->col + j] << " ";

		}
		std::cout << "\n";
	}
	std::cout << "\n";

}

