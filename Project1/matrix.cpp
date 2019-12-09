// Justin Ventura COSC320
// Project 1: matrix.h
#include "matrix.h"

Matrix operator+(Matrix &a, Matrix &b)
{
	if (a.row != b.row || a.col != b.col) 
	{
		Matrix c(0,0);
		std::cout << "ERROR.\n";
		return c;
	}
	Matrix c(a.row, a.col);
	long unsigned n = (a.row * a.col);
	for (auto i = 0; i < n; i++)
	{
		c.M[i] = (a.M[i] + b.M[i]);
	}
	return c;
}
Matrix operator-(Matrix &a, Matrix &b)
{
	if (a.row != b.row || a.col != b.col) 
	{
		Matrix c(0,0);
		std::cout << "ERROR.\n";
		return c;
	}
	Matrix c(a.row, a.col);
	long unsigned n = (a.row * a.col);
	for (auto i = 0; i < n; i++)
	{
		c.M[i] = (a.M[i] - b.M[i]);
	}
	return c;
}

Matrix operator*(Matrix &a, Matrix &b)
{	
	Matrix c(a.row, b.col);

	for (int i = 0; i < a.row; i++)
	{
		for (int j = 0; j < b.col; j++)
		{
			c.M[i * c.col + j] = 0;
			for (int k = 0; k < a.col; k++)
			{
				c.M[i * c.col + j] += a.M[i * a.col + k] * b.M[k * b.col + j];
			}
		}
	}
	return c;
}