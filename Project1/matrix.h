// Justin Ventura COSC320
// Project 1: matrix.h
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
	int * matrix;

public:
	Matrix(int n, int m) : 
	{
		matrix = new int[n*m];
	}
	~Matrix()
	{ delete matrix; }

};

#ifndef
