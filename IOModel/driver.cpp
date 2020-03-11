/* 
 * Justin Ventura, 03/07/20
 * COSC320-002, Dr. Anderson
 * Project 1: driver.cpp
*/

#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "heapq.h"
#include "jspace.h"
#include <chrono>

// Colors to be cool.
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define WHITE   "\033[37m"      /* White */
#define BOLDON  "\e[1m"
#define BOLDOFF "\e[0m"

// Makes all elements above diagonal 0's.
void uppertri(Matrix & A) {

    // No change to a vector.
    if (A.col == 1) return;

    // A[0,0] is main diagonal, so shift by
    // j.
    size_t i = 0, j = 1;

    // Be sure not to seg fault.
    // Stops after triangle is complete.
    size_t buffer;

    if (A.col < A.row) {

        buffer = (A.col - 1) * A.col + (A.col + 1);

    }
    else if (A.col > A.row) {

        buffer = (A.row - 1) * A.col + (A.col - 1);

    }
    else {

        buffer = (A.col - 2) * A.col + (A.col - 1);

    }

    // Create the triangle.
    while ((i * A.col + j) <= buffer) {

        // Start the upper triangle.
        A.M[i * A.col + j] = 0;
        j++;

        // If the row is complete, move to the next.
        if ((i * A.col + j) >= ((i + 1) * A.col)) {

            i++;
            j = i + 1;

        }

    }
}

// Makes all elements below diaginal 0's.
void lowertri(Matrix & A) {

    // Start at row 1 instead of row 0 since
    // row 0 has the main diagonal.
    size_t i = 1, j = 0;

    // Start from row 1 and go down to row
    // A.row - 1.
    while ((i * A.col + j) < A.len) {

        // Start the lower triangle.
        A.M[i * A.col + j] = 0;
        j++;

        // If the row is complete, move to the next.
        if (i == j || j >= (A.col)) {

            i++;
            j = 0;

        }

    }
}

// Converts A to the identity matrix.
void init_identity(Matrix & A) {

    // Create zeroes around the diagonal.
    uppertri(A);
    lowertri(A);

    // Slide down the main diagonal assign 1's.
    size_t i = 0, j = 0;

    // This buffer is to account for all cases, such that
    // regardless of the dimensions of the matrix, there
    // will be no incorrect jumps or seg faults.
    size_t buffer = (A.row >= A.col) ? A.col : A.row;
    while (i < buffer) {

        A.M[i * A.col + j] = 1;
        i++;
        j++;

    }
}

template <typename T>
void shuffle(T * arr, int length) {
    
    // create the bound for random keys, and set up priority queue.
    int bound = pow(length, 3);
    HeapQ<T> pqueue(length);

    // assign the random keys to each value in the array.
    for (int i = 0; i < length; i++) {

        pqueue.enqueue(arr[i], (rand() % bound) + 1);

    }

    // randomly select the elements by priority.
    for (int i = 0; i < length; i++) {

        arr[i] = pqueue.dequeue();

    }

}

// Randomly generates matrix of the given object dimensions.
void init_matrix(Matrix & A) {

    for (size_t i = 0; i < A.len; i++) {

        A.M[i] = (rand() % 99) + 1;

    }

    // Shuffle the array in a random order.
    shuffle(A.M, A.len);
}

void specificprint(Matrix & A) {

    // rounds the number due to precision loss.
    std::cout << WHITE;

    for (size_t i = 0; i < A.row; i++) {

        for (size_t j = 0; j < A.col; j++) {

            if (A.M[i * A.col + j] > .90 && A.M[i * A.col + j] <= 1) {

                std::cout << "1 ";

            }
            else if (A.M[i * A.col + j] > (-.1) && A.M[i * A.col + j] <= 0) {

                std::cout << "0 ";

            }
            else {

                std::cout << int(A.M[i * A.col + j]) << " ";

            }

        }

        std::cout << "\n";

    }

    std::cout << RESET << "\n";

}

int main() {

     // Random seed for generating random matrix.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

	Matrix A(3,3);
	Matrix I(3,3);
	Matrix d(3, 1);

	A.M[0] = 0.6;
	A.M[1] = 0.02;
	A.M[2] = 0.1;
	A.M[3] = 0.3;
	A.M[4] = 0.2;
	A.M[5] = 0.4;
	A.M[6] = 0.2;
	A.M[7] = 0.4;
	A.M[8] = 0.3;
	init_identity(I);
	d.M[0] = 20;
	d.M[1] = 34;
	d.M[2] = 80;

	std::cout << "Matrix A:\n";
	A.print();
    std::cout << "Identity Matrix I:\n";
	I.print();
    std::cout << "Demand Vector d:\n";
	d.print();

	std::cout << "\nSAMPLE RESULT\n";
    Matrix term1 = (I - A);
    std::cout << "Term 1 -> In - A:\n";
    term1.print();
    Matrix term2 = term1.inverse();
    std::cout << "Term 2 -> (In - 1)inv:\n";
    term2.print();
	Matrix result = term2 * d;
    std::cout << "Final term -> (In - A)inv * d:\n";
	result.print();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Amount of each product needed:\n";
    std::cout << "Coal: " << result.M[0] << " units\n";
    std::cout << "Electricity: " << result.M[1] << " units\n"; 
    std::cout << "Produce: " << result.M[2] << " units\n\n";

    std::cout << "INVERSION CORRECTNESS CHECK:\n";
    Matrix X(5, 5);
    init_matrix(X);
    std::cout << "MATRIX X:\n";
    X.print();
    Matrix Xinv = X.inverse();
    std::cout << "MATRIX Xinv:\n";
    Xinv.print();
    Matrix sampleresult = X * Xinv;
    std::cout << "MATRIX X * Xinv = I:\n";
    specificprint(sampleresult);

	return 0;

}