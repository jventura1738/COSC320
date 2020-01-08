// Justin Ventura COSC320
// Project 1: test.cpp
// Demonstrates working operations
#include <iostream>
#include <time.h>
#include "matrix.h"

void initMatrix(Matrix &a) {

	int n = (a.row * a.col);

	for (int i = 0; i < n; i++)
		a.M[i] = ((rand() % 10 + 1));

}

void initMatrix(Matrix *a) {

	int n = (a->row * a->col);

	for (int i = 0; i < n; i++) 
		a->M[i] = ((rand() % 10 + 1));

}

void printMatrix(Matrix &a) {

	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.col; j++) {
			std::cout << a.M[i * a.col + j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void printMatrix(Matrix *a) {

	for (int i = 0; i < a->row; i++)
	{
		for (int j = 0; j < a->col; j++)
		{
			std::cout << a->M[i * a->col + j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main()
{
	srand(time(0));

	Matrix z(3,3);
	z.M[0] = 1;
	z.M[1] = 2;
	z.M[2] = 3;
	z.M[3] = 2;
	z.M[4] = 1;
	z.M[5] = 0;
	z.M[6] = 3;
	z.M[7] = 0;
	z.M[8] = 1;
	printMatrix(z);
	Matrix c = z.inverse();
	printMatrix(c);

	Matrix a(3,3);
	Matrix b(3,3);
	initMatrix(a);
	initMatrix(b);
	std::cout << "Original matrices.\n";
	printMatrix(a);
	printMatrix(b);

	Matrix C = (-a);
	printMatrix(C);


	// Matrix a(2, 2);
	// Matrix b(2, 3);

	// a.M[0] = 2;
	// a.M[1] = 4;
	// a.M[2] = 1;
	// a.M[3] = 6;

	// b.M[0] = 0;
	// b.M[1] = 5;
	// b.M[2] = 1;
	// b.M[3] = 3;
	// b.M[4] = 4;
	// b.M[5] = 2;

	// printMatrix(a);
	// std::cout << "\n";
	// printMatrix(b);

	// Matrix c = (a * b);
	// printMatrix(c);


	// std::cout << "\nTRANSPOSE TEST\n";

	// Matrix matrix1(22,19);
	// initMatrix(matrix1);
	// printMatrix(matrix1);
	
 	// Matrix matrix2 = (-matrix1);
 	// printMatrix(matrix2);

	/*
	
	Matrix x(3,3);
	Matrix y(3,3);
	initMatrix(x);
	initMatrix(y);

	std::cout << "BEFORE.\n";
	printMatrix(x);
	printMatrix(y);

	Matrix z = (x + y);

	std::cout << "AFTER.\n";
	printMatrix(z);

	std::cout << "SUBTRACTION.\n";
	Matrix a = (z - y);

	printMatrix(a);
	
	*/

	return 0;
}

// try { 
// 	std::cout << "test\n";
// } 
// catch (std::bad_alloc & ba) { 
// 	std::cerr << "bad_alloc caught: " << ba.what(); 
// }
