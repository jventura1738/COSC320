// Justin Ventura COSC320
// Project 1: test.cpp
// Demonstrates working operations
#include <iostream>
#include <time.h>
#include "matrix.h"

void initMatrix(Matrix &a) {

	int n = (a.row * a.col);

	for (int i = 0; i < n; i++)
		a.M[i] = ((rand() % 9 + 1));

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

	std::cout << "===================================\n";
	std::cout << "   Justin Ventura's Matrix Test.   \n";
	std::cout << "                                   \n";
	std::cout << "         - Addition Test -         \n";
	Matrix a(5,5);
	Matrix b(5,5);
	initMatrix(a);
	initMatrix(b);
	std::cout << "Original matrices:\n";
	a.print();
	b.print();
	Matrix c = (a + b);
	std::cout << "Addition Result:\n";
	c.print();

	return 0;
}

// try { 
// 	std::cout << "test\n";
// } 
// catch (std::bad_alloc & ba) { 
// 	std::cerr << "bad_alloc caught: " << ba.what(); 
// }
