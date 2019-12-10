// Justin Ventura COSC320
// Project 1: matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix {

public:
	// Matrix pointer M to be heap-allocated.
	double * M;

	// Dimensions of pointer (Matrix) M.
	size_t row;
	size_t col;

	// Matrix Constructor (1x1 default).
	// Allocates heap memory to M.
	Matrix(size_t m = 1, size_t n = 1) : row(m), col(n) { 
		std::cout << "\n--MATRIX ALLOCATED--\n";
		M = new double[n * m]; 
	}

	// Matrix Copy Constructor.
	// Allocates heap memory to this->M.
	Matrix(const Matrix &A) : row(A.row), col(A.col) {
		std::cout << "\n--MATRIX [CC] ALLOCATED--\n";
		this->M = new double[A.row * A.col];
	}

	// Matrix Assignment Operator Overload.
	// Allocates heap memory to this->M.
	void operator=(Matrix &A) {
		delete this->M;
		this->row = A.row;
		this->col = A.col;
		this->M = new double[this->row * this->col];
	}

	// Matrix Destructor.
	// De-allocated heap memory for M.
	~Matrix() { 
		std::cout << "\n--MATRIX DEALLOCATED--\n";
		delete M; 
	}

	// Matrix Operations.

	Matrix transpose();

	friend Matrix operator+(Matrix &A, Matrix &B);
	friend Matrix operator-(Matrix &A, Matrix &B);
	friend Matrix operator*(Matrix &A, Matrix &B);

	//friend Matrix 
};

#endif
