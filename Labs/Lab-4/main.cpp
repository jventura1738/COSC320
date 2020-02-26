/* 
 * Justin Ventura, 02/25/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Main.cpp
*/

#include "matrix.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <chrono>
#include <algorithm>

// Randomly generates a matrix of the given size.
void init_matrix(Matrix & A, int shift);

int main () {
    Matrix a(10, 10);
    Matrix b(10, 10);

    init_matrix(a, 0);
    init_matrix(b, 1);
    Matrix c = a + b;

    std::cout << "Matrix A: \n";
    a.print();

    std::cout << "Matrix B: \n";
    b.print();

    std::cout << "Matrix A + Matrix B: \n";
    c.print();

    std::cout << "Matrix A - Matrix B: \n";
    c = a - b;
    c.print();

    return 0;
}

// Randomly generates matrix of the given size.
void init_matrix(Matrix & A, int shift) {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    for (size_t i = 0; i < A.len; i++) {

        A.M[i] = (rand() % 99) + 1;

    }
    std::shuffle(A.M, A.M + A.len, std::default_random_engine(seed));
}