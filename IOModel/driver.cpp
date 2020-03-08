/* 
 * Justin Ventura, 03/07/20
 * COSC320-002, Dr. Anderson
 * Project 1: driver.cpp
*/

#include <iostream>
#include "matrix.h"
#include "jspace.h"

int main() {

	Matrix A(2,2);
	A.softreset();
	Matrix B = &A;

	A.print();
	B.print();

	return 0;

}