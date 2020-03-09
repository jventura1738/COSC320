/* 
 * Justin Ventura, 02/23/20
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
	std::cout << YELLOW << "Matrix allocated (default).\n" << RESET;
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
	std::cout << YELLOW << "Matrix allocated (main).\n" << RESET;
	this->len = n * m;
	this->M = new float[this->len];
	this->row = n;
	this->col = m;
}

// Matrix Copy Constructor.
Matrix::Matrix(const Matrix & rhs) {
	std::cout << YELLOW << "Matrix allocated (copy construct).\n" << RESET;
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
	std::cout << YELLOW << "\n--MATRIX [AO] ALLOCATED--\n" << RESET;
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
	std::cout << YELLOW << "Matrix de-allocated (destructor).\n" << RESET;
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
bool Matrix::isSingular() const {

	if (this->row != this->col) {

		return true;

	}
	else {

		if (this->determinant() == 0) {

			return true;

		}

		return false;

	}

}

bool Matrix::isSymmetric() {


	Matrix currTrans = this->transpose();

	for (int i = 0; i < this->len; i++) {

		if (currTrans.M[i] != this->M[i]) {

			return false;

		}

	}

	return true;

}

int Matrix::determinant() const {

	std::cout << "TODO\n";
	return 1;

}

// Matrix Padding Method.
Matrix Matrix::pad() {

	if ((log2(this->row) - (int)log2(this->row)) == 0) {

		return *this;

	}

	// Make sure matrix dimensions are power of 2.
	size_t newSize = 2;
	while ((newSize < this->row || newSize < this->col) && newSize > 0)
		newSize *= 2;

	// Hold the old Matrix.
	size_t tempsize = (this->len);
	float * oldM = new float[tempsize];
	for (size_t i = 0; i < tempsize; i++) 
		oldM[i] = this->M[i];

	int oldRow = this->row;
	int oldCol = this->col;

	Matrix padded = *this;

	padded.row = newSize;
	padded.col = newSize;

	delete [] padded.M;
	padded.M = new float[padded.row * padded.col];

	// In order to pad, the matrix must remain
	// symmetric, (A.pad = padded A.transpose().pad())
	// so put 0's on each new pad space but 1's on the
	// main diagonal.
	for(size_t i = 0; i < padded.row; i++) {

		for(size_t j = 0; j < padded.col; j++) {

			// All new padded spaces.
			if(i >= oldRow || j >= oldCol) {

				if (i == j) {

					padded.M[i * padded.col + j] = 1;

				} 
				else {
					
					padded.M[i * padded.col + j] = 0;

				}				

			}
			// Old matrix spaces must remain the same.
			else
				padded.M[i * padded.col + j] = oldM[i * oldCol + j];

		}

	}

	delete [] oldM;
	return padded;

}

// Matrix Inversion Method.
Matrix Matrix::inverse() {

	// Base of Recursion.
	if(row == 1 || col == 1) {

		std::cout << "base of recursion\n";
		Matrix base;

		if (this->M[0] != 0) {

			base.M[0] = 1.0 / this->M[0];

		}
		else {

			base.M[0] = 0;

		}

		return base;

	}

	// if ((log2(this->row) - (int)log2(this->row)) != 0) {

	// 	Matrix needpad = this->pad();
	// 	Matrix inverse2 = needpad.inverse();
	// 	Matrix inverse3(unPadded, unPadded);
	// 	for (int i = 0; i < unPadded; i++) {

	// 		for (int j = 0; j < unPadded; j++) {

	// 			inverse3.M[i * unPadded + j] = inverse2.M[i * unPadded + j];

	// 		}

	// 	}

	// 	return inverse3;

	// }

	if (!this->isSymmetric()) {

		std::cout << "GAYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n";
		Matrix A = *this;
		Matrix At = A.transpose();
		Matrix term = (At * A);
		Matrix term2 = (term.inverse() * At);
		return term2;

	}

	Matrix inverse = this->pad();

	// Matrix assumed to be square & symmetric
	// (n x n) so we will use the ROW dimension
	// however, it doesn't matter which one we
	// use.
	int halfN = inverse.row / 2;

	// A's submatrices.
	Matrix B = Matrix(halfN, halfN);
	Matrix C = Matrix(halfN, halfN);
	Matrix Ct = Matrix(halfN, halfN);
	Matrix D = Matrix(halfN, halfN);

	// Divide A into [B, Ct,
	//                C, D ]
	// Relationship: i < n/2 & j < n/2 --> B
	//               i < n/2 & j >= n/2 --> Ct
	//               i >= n/2 & j < n/2 --> C
	//               i >= n/2 & j >= n/2 --> D
	for(int i = 0; i < inverse.row; i++) {

		for(int j = 0; j < inverse.col; j++) {

			// i & j values correspond to: B
			if(i < halfN && j < halfN)
				B.M[i * B.col + j] = inverse.M[i * inverse.col + j];

			// i & j values correspond to: Ct
			else if(i < halfN && j >= halfN)
				Ct.M[i * Ct.col + (j - halfN)] = inverse.M[i * inverse.col + j];

			// i & j values correspond to: C
			else if(i >= halfN && j < halfN) 
				C.M[((i - halfN) * C.col) + j] = inverse.M[i * inverse.col + j];

			// i & j values correspond to: D
			else if(i >= halfN && j >= halfN) 
				D.M[((i - halfN) * D.col) + (j - halfN)] = inverse.M[i * inverse.col + j];

		}

	}

	// Temporary prints for debugging.
	// std::cout << "--B--\n";
	// B.print();
	// std::cout << "--C TRANSPOSE--\n";
	// Ct.print();
	// std::cout << "--C--\n";
	// C.print();
	// std::cout << "--D--\n";
	// D.print();

	Matrix Bi = B.inverse(); // recurse
	// std::cout << "\n--B INVERSE--\n";
	// Binv.print();

	Matrix W = (C * Bi); // multiply & assign
	// std::cout << "\n--W--\n";
	// W.print();

	Matrix Wt = (Bi * Ct); // multily & assign
	// std::cout << "\n--W TRANSPOSE--\n";
	// Wt.print();

	Matrix X = (W * Ct); // multiply & assign
	// std::cout << "\n--X--\n";
	// X.print();

	Matrix S = (D - X); // subtract & assign
	// std::cout << "\n--S--\n";
	// S.print();

	Matrix V = S.inverse(); // recurse
	// std::cout << "\n--V--\n";
	// V.print();

	Matrix Y = (V * W); // multiply & assign
	// std::cout << "\n--Y--\n";
	// Y.print();

	Matrix Yt = (Y.transpose()); // transposition
	// std::cout << "\n--Y TRANSPOSE--\n";
	// Yt.print();

	Matrix T = (Yt*(-1)); // scalar m by -1
	// std::cout << "\n--T--\n";
	// T.print();

	Matrix U = (Y*(-1)); // scalar m by -1
	// std::cout << "\n--U--\n";
	// U.print();

	Matrix Z = (Wt * Y); // multiply & assign
	// std::cout << "\n--Z--\n";
	// Z.print();

	Matrix R = (Bi + Z); // add and assign
	// std::cout << "\n--R--\n";
	// R.print();
	
	// Now that we have the new split up matrix,
	// we can delete the old one and form a new
	// one using the sub-matrices created above.
	// This will be unpadded though, as the the
	// padding was simply for keeping powers of 
	// 2 for the sub-matrices' dimensions.

	inverse.row = this->row;
	inverse.col = this->col;
	inverse.len = (this->row * this->col);
	delete [] inverse.M;
	inverse.M = new float[inverse.len];

	// Construct Ai as [R, T,
	//                  U, V]
	// Relationship: i < n/2 & j < n/2 --> R
	//               i < n/2 & j >= n/2 --> T
	//               i >= n/2 & j < n/2 --> U
	//               i >= n/2 & j >= n/2 --> V
	for(int i = 0; i < this->row; i++) {

		for(int j = 0; j < this->col; j++) {

			// i & j values correspond to: R
			if(i < halfN && j < halfN)
				inverse.M[i * inverse.col + j] = R.M[i * R.col + j];

			// i & j values correspond to: T
			else if(i < halfN && j >= halfN)
				inverse.M[i * inverse.col + j] = T.M[i * T.col + (j - halfN)];

			// i & j values correspond to: U
			else if(i >= halfN && j < halfN)
				inverse.M[i * inverse.col + j] = U.M[((i - halfN) * U.col) + j];

			// i & j values correspond to: V
			else if(i >= halfN && j >= halfN)
				inverse.M[i * inverse.col + j] = V.M[((i - halfN) * V.col) + (j - halfN)];

		}

	}

	return inverse;

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
            
			std::cout << std::setfill('0') << std::setw(spacing) << this->M[i * this->col + j] << " ";

		}

    	// new line for the next row in matrix.
		std::cout << "\n";

	}

	std::cout << RESET << "\n";

}

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