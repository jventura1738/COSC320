// Justin Ventura COSC320
// Project 1: matrix.h
#include "matrix.h"
//#define INDEX(r, c, i, j) i*r + j

Matrix operator+(Matrix &a, Matrix &b)
{
	if (a.r != b.r || a.c != b.c) 
	{
		Matrix c(0,0);
		std::cout << "ERROR.\n";
		return c;
	}
	Matrix c(a.r, a.c);
	long unsigned n = (a.r * a.c);
	for (auto i = 0; i < n; i++)
	{
		c.M[i] = (a.M[i] + b.M[i]);
	}
	return c;
}
Matrix operator-(Matrix &a, Matrix &b)
{
	if (a.r != b.r || a.c != b.c) 
	{
		Matrix c(0,0);
		std::cout << "ERROR.\n";
		return c;
	}
	Matrix c(a.r, a.c);
	long unsigned n = (a.r * a.c);
	for (auto i = 0; i < n; i++)
	{
		c.M[i] = (a.M[i] - b.M[i]);
	}
	return c;
}
Matrix operator*(Matrix &a, Matrix &b)
{
	if (a.c != b.r)
	{
		Matrix c(0,0);
		std::cout << "ERROR.\n";
		return c;
	}

	Matrix c(a.r, b.c);
	long unsigned n = (a.r * b.c);
	long unsigned index = 0;

	for (long unsigned i = 0; i < c.r; i++)
	{
		for (int j = 0; j < c.c; j++)
		{
			long unsigned R = (i * c.r);
			long unsigned C = j;
			double val = 0;
			for (int k = 1; k <= c.r; k++)
			{
				std::cout << R << " " << C << " ";
				val += (a.M[R] * b.M[C]);
				R++;
				C += c.c;
			}
			std::cout << "\n";
			c.M[index] = val;
			index++;
		}
	}

	std::cout << "before.\n";
	return c;
}