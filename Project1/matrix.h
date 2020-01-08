// Justin Ventura COSC320
// Project 1: matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix {

public:
	// Matrix pointer M to be heap-allocated.
	float * M;

	// Dimensions of pointer (Matrix) M.
	size_t row;
	size_t col;

	// Matrix Constructor (1x1 default).
	// Allocates heap memory to M.
	Matrix(size_t m = 1, size_t n = 1) : row(m), col(n) { 
		std::cout << "\n--MATRIX ALLOCATED--\n";
		M = new float[n * m];
		size_t *len = new size_t(this->row * this->col);

		for (size_t i = 0; i < *len; i++)
			this->M[i] = 0;
		delete len;
	}

	// Matrix Copy Constructor.
	// Allocates heap memory to this->M.
	Matrix(const Matrix &A) : row(A.row), col(A.col) {
		std::cout << "\n--MATRIX [CC] ALLOCATED--\n";
		this->M = new float[A.row * A.col];
		size_t *len = new size_t(A.row * A.col);

		for (size_t i = 0; i < *len; i++)
			this->M[i] = A.M[i];
		delete len;
	}

	// Matrix Assignment Operator Overload.
	// Allocates heap memory to this->M and copies.
	void operator=(const Matrix &A);

	// Matrix Destructor.
	// De-allocated heap memory for M.
	~Matrix() { 
		std::cout << "\n--MATRIX DEALLOCATED--\n";
		delete M; 
	}

	// - [Matrix Operation Methods] -

	// Matrix Negation Method. (-Matrix)
	Matrix negate();

	// Matrix Padding Method.
	Matrix pad();

	// Matrix Inversion Method.
	Matrix inverse();

	// Print Matrix Method.
	void print();

	// - [Matrix Operations] -

	// Scalar Multiplication. (Matrix * float)
	//friend Matrix& operator*(const Matrix &A, const float &scalar);

	// Matrix Transpostion. (-Matrix)
	friend Matrix operator-(const Matrix &A);

	// Matrix Addition. (Matrix + Matrix)
	friend Matrix operator+(const Matrix &A, const Matrix &B);

	// Matrix Subtraction. (Matrix - Matrix)
	friend Matrix operator-(const Matrix &A, const Matrix &B);

	// Matrix Multiplication. (Matrix * Matrix)
	friend Matrix operator*(const Matrix &A, const Matrix &B);
};

#endif
