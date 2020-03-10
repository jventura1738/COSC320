/* 
 * Justin Ventura, 03/08/20
 * COSC320-002, Dr. Anderson
 * Project 1: matrix.cpp
*/

// Header file.
#include "matrix.h"

// Formatting and terminal colors.
#include <iomanip>
#include <cmath>
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
Matrix::Matrix(const Matrix & rhs) {
	//std::cout << YELLOW << "Matrix allocated (copy construct).\n" << RESET;
	this->len = rhs.len;
	this->row = rhs.row;
	this->col = rhs.col;

	this->M = new float[this->len];
	for (size_t i = 0; i < this->len; i++)
		this->M[i] = rhs.M[i];
}

// Matrix Assignment Operation
void Matrix::operator=(const Matrix & rhs) {

	// De-allocate old matrix pointer.
	//std::cout << YELLOW << "\n--MATRIX [AO] ALLOCATED--\n" << RESET;
	delete [] this->M;
	this->len = rhs.len;
	this->row = rhs.row;
	this->col = rhs.col;

	// Copy A->M to re-allocated this->M.
	this->M = new float[this->len];

	for (size_t i = 0; i < this->len; i++)
		this->M[i] = rhs.M[i];
}

// Destructor.
Matrix::~Matrix() {
	//std::cout << YELLOW << "Matrix de-allocated (destructor).\n" << RESET;
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

// Matrix Subtraction Operation.
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

			for (size_t k = 0; k < A.col; k++) {

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

// Check if matrix is singular.
bool Matrix::isSingular() {

	// Cannot invert a non-square matrix.
	if (this->row != this->col) {

		return true;

	}
	else {

		// Assumes row == col.
		if (this->determinant() == 0) {

			return true;

		}

		return false;

	}

}

// Check is the matrix is symmetric.
bool Matrix::isSymmetric() {

	// 1 x 1 matrix symmetric by default.
	if (this->row == 1 && this->col == 1) {

		return true;

	}

	// Run through the matrix and compare it to
	// its transpose.  If any instance is not 
	// equal, then the matrix is non symmetric.
	Matrix currTrans = this->transpose();

	for (size_t i = 0; i < this->len; i++) {

		if (currTrans.M[i] != this->M[i]) {

			return false;

		}

	}

	return true;

}

// Calculate the determinant.
float Matrix::determinant() {

	// Base cases of easy to evaluate determinants which
	// correspond to n = 1, 2.
	if (this->row == 1) {

		return this->M[0];

	}
	else if (this->row == 2) {

		return ((this->M[0] * this->M[3]) - (this->M[1] * this->M[2]));

	}

	// General recursive case:
	float det = 0;
	for (size_t j = 0; j < this->row; j++) {

		det += this->M[j] * this->cofactorAt(0, j);

	}

	return det;

}

// Get cofactor at this->M[ij]
float Matrix::cofactorAt(size_t i, size_t j) {

	// Create the disected matrix (to get rid of
	// the ith row and jth col).
	Matrix disected(this->row - 1, this->row - 1);
	size_t traverse = 0;

	for (size_t k = 0; k < this->row; k++) {

		for (size_t l = 0; l < this->row; l++) {

			// "Disect" *this by cutting ith row & jth col.
			if ((k != i && l != j)) {

				disected.M[traverse++] = this->M[k * this->row + l];

			}

		}

	}

	// This is to alternate the signs, complete the definition
	// of a cofactor, and finish the recursion.
	return (pow(-1, i + j) * disected.determinant());

}

// Checks if the matrix needs padding.
bool Matrix::needsPadding() const {

	// Cannot pad a singular matrix.
	if (this->row != this->col) {

		throw std::string("ERROR: Cannot pad singular matrix.\n");

	}
	else {

		// If not a power of two, needs padding.
		if (log2(this->row) - (int)log2(this->row)) {

			return true;

		}

		return false;

	}

}

// Matrix Padding Method.
Matrix Matrix::pad() {

	// Just to be sure this algorithm never fails.
	if (!this->needsPadding()) {

		throw std::string("Error: bruh.\n");

	}

	// If needs padding, pad to the nearest power of
	// 2 greater than the current size.
	size_t newSize = 2;
	while (newSize <= this->row) {

		newSize *= 2;

	}

	// Padded matrix we will return.
	Matrix padded(newSize, newSize);

	for (size_t i = 0; i < newSize; i++) {

		for (size_t j = 0; j < newSize; j++) {

			// Keep the original matrix the same.
			if (i < this->row && j < this->row) {

				padded.M[i * newSize + j] = this->M[i * this->col + j];

			}
			else {

				// Main diagonal for Identity matrix.
				if (i == j) {

					padded.M[i * newSize + j] = 1;

				}
				// Otherwise, we will pad zeroes.
				else {

					padded.M[i * newSize + j] = 0;

				}

			}

		}

	}

	return padded;

}

// Private inversion method.
Matrix Matrix::_inverse() {

	// Base of Recursion.
	if(this->row == 1) {

		//std::cout << "base of recursion\n";
		Matrix base;

		// Inverse of a 1 x 1 is simply the reciprocal.
		if (this->M[0] != 0) {

			base.M[0] = 1.0 / this->M[0];

		}
		else {

			base.M[0] = 0;

		}

		return base;

	}

	// Submatrices.
	size_t halfn = this->row / 2;
	Matrix B = Matrix(halfn, halfn);
	Matrix C = Matrix(halfn, halfn);
	Matrix Ct = Matrix(halfn, halfn);
	Matrix D = Matrix(halfn, halfn);

	// Divide A into [B, Ct,
	//                C, D ]
	// Relationship: i < n/2 & j < n/2 --> B
	//               i < n/2 & j >= n/2 --> Ct
	//               i >= n/2 & j < n/2 --> C
	//               i >= n/2 & j >= n/2 --> D
	for (size_t i = 0; i < this->row; i++) {

		for (size_t j = 0; j < this->col; j++) {

			// i & j values correspond to: B
			if(i < halfn && j < halfn)
				B.M[i * B.col + j] = this->M[i * this->col + j];

			// i & j values correspond to: Ct
			else if(i < halfn && j >= halfn)
				Ct.M[i * Ct.col + (j - halfn)] = this->M[i * this->col + j];

			// i & j values correspond to: C
			else if(i >= halfn && j < halfn) 
				C.M[((i - halfn) * C.col) + j] = this->M[i * this->col + j];

			// i & j values correspond to: D
			else if(i >= halfn && j >= halfn) 
				D.M[((i - halfn) * D.col) + (j - halfn)] = this->M[i * this->col + j];

		}

	}

	// Algorithm
	Matrix Binv = B.inverse();
	Matrix W = C * Binv;
	Matrix Wt = W.transpose();
	Matrix X = W * C.transpose();
	Matrix S = D - X;
	Matrix V = S.inverse();
	Matrix Y = V * W;
	Matrix Yt = Y.transpose();
	Matrix T = Yt * (-1);
	Matrix U = Y * (-1);
	Matrix Z = Wt * Y;
	Matrix R = Binv + Z;

	// Construct Ai as [R, T,
	//                  U, V]
	// Relationship: i < n/2 & j < n/2 --> R
	//               i < n/2 & j >= n/2 --> T
	//               i >= n/2 & j < n/2 --> U
	//               i >= n/2 & j >= n/2 --> V
	Matrix Ainv(this->row, this->row);

	for (size_t i = 0; i < this->row; i++) {

		for (size_t j = 0; j < this->row; j++) {

			// R is the top left corner.
			if (i < halfn && j < halfn) {

				Ainv.M[i * Ainv.row + j] = R.M[i * R.row + j];

			}
			// T is the top right corner.
			else if (i < halfn && j >= halfn) {

				Ainv.M[i * Ainv.row + j] = T.M[i * T.row + (j - halfn)];

			}
			// U is the bottom left corner.
			else if (i >= halfn && j < halfn) {

				Ainv.M[i * Ainv.row + j] = U.M[(i - halfn) * U.row + j];

			}
			// V is the bottom right corner.
			else {

				Ainv.M[i * Ainv.row + j] = V.M[(i - halfn) * V.row + (j - halfn)];

			}

		}

	}

	return Ainv;

}

// Public inverse function.
Matrix Matrix::inverse() {

	// Cannot invert singular matrices.
	if (this->isSingular()) {

		throw std::string("ERROR: Matrix is singular, idiot.\n");

	}

	Matrix inv = *this;

	// If matrix is not symmetric, then we can
	// use this trick to invert it correctly.
	// Ainv = (At * A)inv * At.
	if (!this->isSymmetric()) {

		Matrix At = this->transpose();
		inv = (At) * inv;
		inv = inv.inverse();
		inv = inv * At;
		return inv;

	}

	// If not a power of two, pad the matrix and
	// note that it was padded to be sure of a 
	// safe extraction at the end of the function.
	bool padded = false;
	if (inv.needsPadding()) {

		inv = inv.pad();
		padded = true;

	}

	// Just to guarantee that we have no errors.
	if (!inv.isSymmetric() || inv.row != inv.col) {

		throw std::string("bruh.\n");

	}

	// Begin the actual inversion now that the 
	// candidate is qualified.
	inv = inv._inverse();

	// If the matrix was padded, then we must extract
	// the matrix from the n x n corner and ignore the
	// padded section.
	if (padded) {

		Matrix unPadded(this->row, this->row);

		for (size_t i = 0; i < inv.row; i++) {

			for (size_t j = 0; j < inv.row; j++) {

				if (i < this->row && j < this->row) {

					unPadded.M[i * this->row + j] = inv.M[i * inv.row + j];

				}

			}

		}

		return unPadded;

	}

	// Otherwise we can just return the inverse as is.
	else {

		return inv;

	}

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
	 * 
	 * We will do some gamer moves to take into
	 * account negative signs.
	*/

	// Find the largest number.
	size_t maxIndex = 0;
	bool negative = false;
	for (size_t i = 0; i < this->len; i++) {

		if (this->M[i] > this->M[maxIndex]){

			maxIndex = i;

		}
		if (this->M[i] < 0) {

			negative = true;

		}

	}


	// Now count it's digits then use this to
	// generalize the matrix's spacing format.
	int max = this->M[maxIndex];
	size_t spacing = (negative) ? 2 : 1;

	// Spacing for largest digits.
	while (max >= 1) {

		// division hacks
		max /= 10;
		spacing++;

	}

	std::cout << WHITE;
	std::cout << std::fixed << std::setprecision(2);

	// Nested looping begins.
	for (size_t i = 0; i < this->row; i++) {

		// print the row of the matrix.
		for (size_t j = 0; j < this->col; j++) {
            
			std::cout << std::setfill('0') << std::setw(spacing) << this->M[i * this->col + j] << " ";

		}

    	// new line for the next row in matrix.
		std::cout << "\n";

	}

	std::cout << RESET << "\n";

}

// Basic matrix print, no formatting.
void Matrix::print2() {

	// Replace all indices of the matrix with zeroes.
	for (size_t i = 0; i < this->row; i++) {

		// print the row of the matrix.
		for (size_t j = 0; j < this->col; j++) {
            
			std::cout << this->M[i * this->col + j] << " ";

		}

		std::cout << "\n";

	}

	std::cout << "\n";

}

// Soft reset (refresh).
void Matrix::softreset() {

	// Replace all indices of the matrix with zeroes.
	for (size_t i = 0; i < this->row; i++) {

		// set the row of the matrix.
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