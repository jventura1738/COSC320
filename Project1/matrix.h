// Justin Ventura COSC320
// Project 1: matrix.h
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:

public:
	// matrix dynamic array
	double * M;

	// dimensions of matrix
	long unsigned r;
	long unsigned c;

	// constructor
	Matrix(long unsigned n, long unsigned m) : len(n*m)
	{ M = new double[n*m]; }

	// destructor
	~Matrix()
	{ delete M; }

	// matrix operations
	friend Matrix* operator+(Matrix *a, Matrix *b);
	friend Matrix* operator-(Matrix *a, Matrix *b);
	friend Matrix* operator*(Matrix *a, Matrix *b);
};

#endif
