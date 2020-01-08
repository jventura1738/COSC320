// Justin Ventura COSC320
// Project 1: matrix.h
#include "matrix.h"

// Matrix Display Method.
void Matrix::print() {

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			std::cout << a->M[i * this->col + j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// Matrix Assignment Operation
void Matrix::operator=(const Matrix &A) {

	// De-allocate old matrix pointer.
	delete this->M;
	this->row = A.row;
	this->col = A.col;

	// Copy from A.M to re-allocated this->M.
	size_t len = (this->row * this->col);
	this->M = new float[len];

	for (size_t i = 0; i < len; i++)
		this->M[i] = A.M[i];
}

// Matrix Padding Method
Matrix& Matrix::pad() {

	int newSize = 2;
	while ((newSize < this->row || newSize < this->col) && newSize > 0)
		newSize *= 2;

	size_t tempsize = (this->row * this->col);
	float *oldM = new float[tempsize];
	for (int i = 0; i < tempsize; i++) 
		oldM[i] = this->M[i];

	int oldRow = this->row;
	int oldCol = this->col;
	this->row = newSize;
	this->col = newSize;
	
	this->M = new float[this->row * this->col];

	for(int i = 0; i < this->row; i++) {

		for(int j = 0; j < this->col; j++) {

			if(i >= oldRow || j >= oldCol) {

				if(i == j)
					M[i * this->col + j] = 1;

				else
					M[i * this->col + j] = 0;
			}
			else
				M[i * this->col + j] = oldM[i * oldCol + j];

		}

	}

	delete [] oldM;
	return *this;

}

// Matrix Scalar Multiplication.
Matrix operator*(const Matrix &A, const float &scalar) {

	Matrix C(A.row, A.col);
	size_t n = (A.row + A.col);

	// Multiply scalar to entire matrix.
	for (int i = 0; i < n; i++)
		C.M[i] = (C.M[i] * scalar);

	return C;
}

// Matrix Addition Operation.
Matrix& operator+(const Matrix &A, const Matrix &B) {

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
Matrix& operator-(const Matrix &A, const Matrix &B) {

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
Matrix& operator*(const Matrix &A, const Matrix &B) {

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
Matrix& Matrix::inverse() {

	// Catch non-squares.
	if(row != col) {

		std::cout << "not square.\n";
		return *this;

	}
	// Base of Recursion.
	if(row == 1 && col == 1) {

		std::cout << "base of recursion\n";
		return *this;

	}

	int unPadRows = row;
	int unPadCols = col;
	// std::cout << "padding\n";
	this->pad();

	int halfRow = row / 2;
	int halfCol = col / 2;

	Matrix B = Matrix(halfRow, halfCol);
	Matrix C = Matrix(halfRow, halfCol);
	Matrix Ct = Matrix(halfRow, halfCol);
	Matrix D = Matrix(halfRow, halfCol);

	// divide matrices
	for(int i = 0; i < this->row; i++) {

		for(int j = 0; j < this->col; j++) {

			if(i < halfRow && j < halfCol) //top left
				B.M[i * B.col + j] = this->M[i * this->col + j];

			else if(i < halfRow && j >= halfCol) //top right
				Ct.M[i * Ct.col + (j - halfCol)] = this->M[i * this->col + j];

			else if(i >= halfRow && j < halfCol) // bottom left
				C.M[((i - halfRow) * C.col) + j] = this->M[i * this->col + j];

			else if(i >= halfRow && j >= halfCol) //bottom right
				D.M[((i - halfRow) * D.col) + (j - halfCol)] = this->M[i * this->col + j];

		}

	}

	std::cout << "--B--\n";
	B.print();
	std::cout << "--C TRANSPOSE--\n";
	Ct.print();
	std::cout << "--C--\n";
	C.print();
	std::cout << "--D--\n";
	D.print();

	std::cout << "long algorithm\n";
	Matrix Binv = B.inverse(); //recursion
	std::cout << "\n--B INVERSE--\n";
	Binv.print();

	Matrix W = (C * Binv);
	std::cout << "\n--W--\n";
	W.print();

	Matrix Wt = (Binv * Ct);
	std::cout << "\n--W TRANSPOSE--\n";
	Wt.print();

	Matrix X = (W * Ct);
	std::cout << "\n--X--\n";
	X.print();

	Matrix S = (D - X);
	std::cout << "\n--S--\n";
	S.print();

	Matrix V = S.inverse(); //recursion
	std::cout << "\n--V--\n";
	V.print();

	Matrix Y = (V * W);
	std::cout << "\n--Y--\n";
	Y.print();

	Matrix Yt = (-Y);
	std::cout << "\n--Y TRANSPOSE--\n";
	Yt.print();

	Matrix T = (Yt * -1);
	std::cout << "\n--T--\n";
	T.print();

	Matrix U = (Y * -1);
	std::cout << "\n--U--\n";
	U.print();

	Matrix Z = (Wt * Y);
	std::cout << "\n--Z--\n";
	Z.print();

	Matrix R = (Binv + Z);
	std::cout << "\n--R--\n";
	R.print();
	
	delete [] M;
	this->row = unPadRows;
	this->col = unPadCols;
	M = new float[this->row * this->col];

	for(int i = 0; i < this->row; i++)

		for(int j = 0; j < this->col; j++) {

			if(i < halfRow && j < halfCol) //top left
				this->M[i * this->col + j] = R.M[i * R.col + j];

			else if(i < halfRow && j >= halfCol) //top right
				this->M[i * this->col + j] = T.M[i * T.col + (j - halfCol)];

			else if(i >= halfRow && j < halfCol) // bottom left
				this->M[i * this->col + j] = U.M[((i - halfRow) * U.col) + j];

			else if(i >= halfRow && j >= halfCol) //bottom right
				this->M[i * this->col + j] = V.M[((i - halfRow) * V.col) + (j - halfCol)];
		}

	std::cout << "--THIS MATRIX--\n";
	this->print();
	return *this;

}

