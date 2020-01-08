// Justin Ventura COSC320
// Project 1: matrix.h
// Dr. Joseph Anderson.
#include "matrix.h"

// Matrix Display Method.
void Matrix::print() {

	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
		{
			std::cout << this->M[i * this->col + j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// Matrix Assignment Operation
void Matrix::operator=(const Matrix &A) {

	// De-allocate old matrix pointer.
	// std::cout << "\n--MATRIX [AO] ALLOCATED--\n";
	delete this->M;
	this->row = A.row;
	this->col = A.col;

	// Copy from A.M to re-allocated this->M.
	size_t *len = new size_t(this->row * this->col);
	this->M = new float[*len];

	for (size_t i = 0; i < *len; i++)
		this->M[i] = A.M[i];
	delete len;
}

// Matrix Padding Method.
Matrix Matrix::pad() {

	// Make sure matrix dimensions are power of 2.
	int newSize = 2;
	while ((newSize < this->row || newSize < this->col) && newSize > 0)
		newSize *= 2;

	// Hold the old Matrix.
	size_t tempsize = (this->row * this->col);
	float *oldM = new float[tempsize];
	for (int i = 0; i < tempsize; i++) 
		oldM[i] = this->M[i];

	int oldRow = this->row;
	int oldCol = this->col;
	this->row = newSize;
	this->col = newSize;
	
	this->M = new float[this->row * this->col];

	// In order to pad, the matrix must remain
	// symmetric, (padded A = padded At) so put
	// 0's on each new pad space but 1's on the
	// main diagonal.
	for(int i = 0; i < this->row; i++) {

		for(int j = 0; j < this->col; j++) {

			// All new padded spaces.
			if(i >= oldRow || j >= oldCol) {

				// New main diagonal.
				if(i == j)
					M[i * this->col + j] = 1;

				// New padded spaces.
				else
					M[i * this->col + j] = 0;
			}
			// Old matrix spaces must remain the same.
			else
				M[i * this->col + j] = oldM[i * oldCol + j];

		}

	}

	delete [] oldM;
	return *this;

}

// Matrix Negation.
Matrix Matrix::negate() {

	Matrix C(this->row, this->col);
	size_t *n = new size_t(this->row * this->col);

	// Simply flipping the sign on each space.
	for (size_t i = 0; i < *n; i++) 
		C.M[i] = (this->M[i] * -1.0);

	return C;
}

// Matrix Scalar Multiplication.
// Matrix& operator*(const Matrix &A, const float &scalar) {

// 	Matrix C(A.row, A.col);
// 	size_t *n = new size_t(A.row * A.col);

// 	// Multiply scalar to entire matrix.
// 	for (size_t i = 0; i < *n; i++)
// 		C.M[i] = (C.M[i] * scalar);

// 	delete n;
// 	return C;
// }

// Matrix Addition Operation.
Matrix operator+(const Matrix &A, const Matrix &B) {

	// Matrices must have same dimensions.

	if (A.row != B.row || A.col != B.col) {
		Matrix C(0,0);
		std::cout << "ERROR.\n";
		return C;
	}
	
	Matrix C(A.row, A.col);
	size_t *n = new size_t(A.row * A.col);

	// Algorithm: C[m,n] = A[m,n] + B[m,n],
	// where m is # rows, n is # cols.

	for (int i = 0; i < *n; i++)
		C.M[i] = (A.M[i] + B.M[i]);

	return C;
}

// Matrix Subtraction Operation.
Matrix operator-(const Matrix &A, const Matrix &B) {

	// Matrices must have same dimensions.

	if (A.row != B.row || A.col != B.col) {
		Matrix C(0,0);
		std::cout << "ERROR.\n";
		return C;
	}

	Matrix C(A.row, A.col);
	size_t *n = new size_t(A.row * A.col);

	// Algorithm: C[m,n] = A[m,n] - B[m,n],
	// where m is # rows, n is # cols.

	for (int i = 0; i < *n; i++)
		C.M[i] = (A.M[i] - B.M[i]);

	return C;
}

// Matrix Multiplication Operation.
Matrix operator*(const Matrix &A, const Matrix &B) {

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

	return C;

}


// Matrix Transposition Operation.
Matrix operator-(const Matrix& A) {
		
	Matrix temp(A.col, A.row);

	// Algorithm: simply swap i & j and
	// row & col. 

	for (int i = 0; i < temp.col; i++) {

		for (int j = 0; j < temp.row; j++) {

			temp.M[i * temp.row + j] = A.M[j * temp.col + i];
			//std::cout << "i: " << i << " j: " << j;
		}
		//std::cout << "\n";
	}

	return temp;
}

// Matrix Inversion Method.
Matrix Matrix::inverse() {

	// Catch non-square matrices.
	if(row != col) {

		std::cout << "not square.\n";
		return *this;

	}

	// Base of Recursion.
	if(row == 1 && col == 1) {

		std::cout << "base of recursion\n";
		M[0] = 1.0 / M[0];
		return *this;

	}

	int unPadRows = row;
	int unPadCols = col;

	if ((this->row % 2) != 0) {
		//std::cout << "padding dimensions to power of 2\n";
		this->pad();
	}

	// Matrix assumed to be square & symmetric
	// (n x n) so we will use the ROW dimension
	// however, it doesn't matter which one we
	// use.
	int halfN = row / 2;

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
	for(int i = 0; i < this->row; i++) {

		for(int j = 0; j < this->col; j++) {

			// i & j values correspond to: B
			if(i < halfN && j < halfN)
				B.M[i * B.col + j] = this->M[i * this->col + j];

			// i & j values correspond to: Ct
			else if(i < halfN && j >= halfN)
				Ct.M[i * Ct.col + (j - halfN)] = this->M[i * this->col + j];

			// i & j values correspond to: C
			else if(i >= halfN && j < halfN) 
				C.M[((i - halfN) * C.col) + j] = this->M[i * this->col + j];

			// i & j values correspond to: D
			else if(i >= halfN && j >= halfN) 
				D.M[((i - halfN) * D.col) + (j - halfN)] = this->M[i * this->col + j];

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

	Matrix Yt = (-Y); // transposition
	// std::cout << "\n--Y TRANSPOSE--\n";
	// Yt.print();

	Matrix T = (Yt.negate()); // scalar m by -1
	// std::cout << "\n--T--\n";
	// T.print();

	Matrix U = (Y.negate()); // scalar m by -1
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
	delete [] M;
	this->row = unPadRows;
	this->col = unPadCols;
	M = new float[this->row * this->col];

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
				this->M[i * this->col + j] = R.M[i * R.col + j];

			// i & j values correspond to: T
			else if(i < halfN && j >= halfN)
				this->M[i * this->col + j] = T.M[i * T.col + (j - halfN)];

			// i & j values correspond to: U
			else if(i >= halfN && j < halfN)
				this->M[i * this->col + j] = U.M[((i - halfN) * U.col) + j];

			// i & j values correspond to: V
			else if(i >= halfN && j >= halfN)
				this->M[i * this->col + j] = V.M[((i - halfN) * V.col) + (j - halfN)];

		}

	}

	// std::cout << "--THIS MATRIX--\n";
	// this->print();
	return *this;

}

