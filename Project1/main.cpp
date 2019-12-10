#include <iostream>
#include "matrix.h"

void initMatrix(Matrix &a)
{
	int n = (a.row * a.col);
	for (int i = 0; i < n; i++)
	{
		a.M[i] = 1;
	}
}

void printMatrix(Matrix &a)
{
	// int n = (a.row * a.col);
	// for (int i = 0; i < n; i++)
	// {
	// 	std::cout << a.M[i] << " ";
	// }
	// std::cout << "\n";

	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < a.col; j++)
		{
			std::cout << a.M[i * a.col + j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main()
{
	
	Matrix a(2, 2);
	Matrix b(2, 3);

	a.M[0] = 2;
	a.M[1] = 4;
	a.M[2] = 1;
	a.M[3] = 6;

	b.M[0] = 0;
	b.M[1] = 5;
	b.M[2] = 1;
	b.M[3] = 3;
	b.M[4] = 4;
	b.M[5] = 2;

	printMatrix(a);
	std::cout << "\n";
	printMatrix(b);

	std::cout << "before *\n";

	Matrix c = (a * b);

	std::cout << "after *\n";

	printMatrix(c);

	/*

	std::cout << "\nTRANSPOSE TEST\n";

	Matrix matrix1(5,4);
	initMatrix(matrix1);
	printMatrix(matrix1);
	Matrix matrix2 = matrix1.transpose();
	printMatrix(matrix2);
	
	*/
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
	Matrix a = (x - y);

	printMatrix(a);
	*/
	return 0;
}