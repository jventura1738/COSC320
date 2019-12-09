// Justin Ventura COSC320
// Project 1: matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class Matrix {
private:

public:
	// matrix dynamic array
	double * M;

	// dimensions of matrix
	long unsigned r;
	long unsigned c;
	long unsigned len;

	// constructor
	Matrix(long unsigned m, long unsigned n) : len(n*m), r(m), c(n)
	{ std::cout << "\n--MATRIX ALLOCATED--\n";
		M = new double[n*m]; }

	// destructor
	~Matrix()
	{ std::cout << "\n--MATRIX DEALLOCATED--\n";
		delete M; }

	// matrix operations
	friend Matrix operator+(Matrix &a, Matrix &b);
	friend Matrix operator-(Matrix &a, Matrix &b);
	friend Matrix operator*(Matrix &a, Matrix &b);
};

#endif
