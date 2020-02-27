/* 
 * Justin Ventura, 02/25/20
 * COSC320-002, Dr. Anderson
 * Lab-4: Main.cpp
*/

// Necessities.
#include "matrix.h"
#include "timer.h"

// Used for basic formatting, randomizing and stuff.
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <random>
#include <chrono>
#include <algorithm>
#include <iomanip>

// For terminal colors and affects.
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define MAGENTA "\033[35m"      /* Magenta */
#define WHITE   "\033[37m"      /* White */
//#define BLACK   "\033[30m"      /* Black */
//#define YELLOW  "\033[33m"      /* Yellow */
//#define BLUE    "\033[34m"      /* Blue */
//#define CYAN    "\033[36m"      /* Cyan */
#define BOLDON  "\e[1m"
#define BOLDOFF "\e[0m"

// Randomly generates a matrix of the given object dimensions.
void init_matrix(Matrix & A);

// Makes all elements off main diagonal 0's.
void diagonal(Matrix & A);

// Makes all elements above diagonal 0's.
void uppertri(Matrix & A);

// Makes all elements below diaginal 0's.
void lowertri(Matrix & A);

// Converts A to the identity matrix.
void init_identity(Matrix & A);

// Clearly prints the matrix with color coding.
// TYPE: 1 = diagonal
//       2 = upper triangle
//       3 = lower triangle
void print(Matrix & A, int type);

int main () {

    // Matrices for print tests.
    Matrix a(9, 9);  // Random 9 x 9 matrix.
    Matrix b(8, 2);  // Random 8 x 2 matrix.
    Matrix c(2, 8);  // Random 2 x 8 matrix.
    Matrix d(4, 4);  // Random 4 x 4 matrix.
    Matrix v(9, 1);  // Random vector in R9.
    Matrix *temp = nullptr;// placeholder matrix.

    init_matrix(a);
    init_matrix(b);
    init_matrix(c);
    init_matrix(d);
    init_matrix(v);

    /*
     * PRINT TESTS: Test the prints of the matrices
     * and vectors below.  They will be printed in
     * regular, diagonal, upper/lower triangular,
     * and identity form.
    */

    std::cout << BOLDON << WHITE << "\n"; 
    std::cout << "===============================\n";
    std::cout << "       MATRIX PRINT TESTS:     \n";
    std::cout << "===============================\n\n"; 
    std::cout << BOLDOFF << RESET;

    std::cout << BOLDON << "--- Random Matrix A (9 x 9) --- \n" << BOLDOFF;
    std::cout << " --> Initial matrix:\n";
    a.print();

    std::cout << "--> Diagonal matrix:\n";
    temp = new Matrix(a);
    diagonal(a);
    print(a, 1);
    a = *temp;

    std::cout << "--> Upper & Lower triangle matrix:\n";
    uppertri(a);
    print(a, 2);
    std::cout << "\n";
    a = *temp;
    lowertri(a);
    print(a, 3);
    a = *temp;
    delete temp;

    std::cout << BOLDON << "\n--- Random Matrix B (8 x 2) --- \n" << BOLDOFF;
    std::cout << " --> Initial matrix:\n";
    b.print();

    std::cout << "--> Diagonal matrix:\n";
    temp = new Matrix(b);
    diagonal(b);
    print(b, 1);
    b = *temp;

    std::cout << "--> Upper & Lower triangle matrix:\n";
    uppertri(b);
    print(b, 2);
    std::cout << "\n";
    b = *temp;
    lowertri(b);
    print(b, 3);
    std::cout << "\n";
    b = *temp;
    delete temp;


    std::cout << "--> Identity Matrix (square):\n";
    init_identity(a);
    print(a, 1);
    std::cout << "\n";
    
    std::cout << "--> Identity Matrix (verticle)\n";
    init_identity(b);
    print(b, 1);
    std::cout << "\n";

    std::cout << "--> Identity Matrix (horizontal)\n";
    init_identity(c);
    print(c, 1);
    std::cout << "\n";



    
    /*
     * ADDITION AND SUBTRACTION TESTS: a few
     * tests will be performed, including the
     * exception catches for mismatch/incorrect
     * cases.
     * 
     * [EXTRA CREDIT] SCALAR MULTIPLICATION:
     * there are also some tests involving the
     * scalar multiplication * overload.
    */

    std::cout << BOLDON << WHITE << "\n"; 
    std::cout << "===============================\n";
    std::cout << "    ADD/SUB & SCALAR TESTS:    \n";
    std::cout << "===============================\n\n"; 
    std::cout << BOLDOFF << RESET;

   /*
    * MATRIX MULTIPLICATION TESTS: here are a 
    * few cases for matrix multiplication, as
    * well as some extreme cases and the time
    * it takes to perform the multiplication.
   */

    std::cout << BOLDON << WHITE << "\n"; 
    std::cout << "===============================\n";
    std::cout << "  DOT PRODUCT TESTS & TIMING:  \n";
    std::cout << "===============================\n\n"; 
    std::cout << BOLDOFF << RESET;

    return 0;
}

// Randomly generates matrix of the given object dimensions.
void init_matrix(Matrix & A) {

    // Random seed for generating random matrix.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    for (size_t i = 0; i < A.len; i++) {

        A.M[i] = (rand() % 999) + 1;

    }

    // Shuffle the array in a random order.
    std::shuffle(A.M, A.M + A.len, std::default_random_engine(seed));
}

// Makes all elements off main diagonal 0's.
void diagonal(Matrix & A) {

    for (size_t i = 0; i < A.row; i++) {

        for (size_t j = 0; j < A.col; j++) {

            // Any spot of the A[i,j] diagonal should be zero.
            if(i != j) {
                A.M[i * A.col + j] = 0;
            } 

        }

    }

}

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

// Clearly prints the matrix with color coding.
// TYPE: 1 = diagonal/identity
//       2 = upper triangle
//       3 = lower triangle
void print(Matrix & A, int type) {

    /*
	 * Nested loops to print out the array in
	 * its matrix form; each col per row since 
	 * I am using a 1D "flat" array.  We will also
	 * find the number with the most digits,
	 * then count it's total digits, and format
	 * the matrix accordingly.
	*/

    // Find the largest number.
	size_t maxIndex = 0;
	for (size_t i = 1; i < A.len; i++) {

		if (A.M[i] > A.M[maxIndex]){

			maxIndex = i;

		}

	}

	// Now count it's digits then use this to
	// generalize the matrix's spacing format.
	int max = A.M[maxIndex];
	size_t spacing = 0;

	while (max >= 1) {

		// division hacks
		max /= 10;
		spacing++;

	}

    // Use the spacing variables above to format matrix.
    switch(type) {

        // Diagonal/Identity print.
        case 1:

        for (size_t i = 0; i < A.row; i++) {

            for (size_t j = 0; j < A.col; j++) {

                // Make the main diagonal colored.
                if (i == j) {

                    std::cout << BOLDON << GREEN << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << BOLDOFF << RESET << " ";

                }
                else {

                    std::cout << WHITE << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << " ";

                }

            }

            std::cout << "\n";

        }

        std::cout << "\n";
        break;

        // Upper Triangle print.
        case 2:

        for (size_t i = 0; i < A.row; i++) {

            for (size_t j = 0; j < A.col; j++) {

                if (i == j) {

                    std::cout << GREEN << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << " ";

                }
                else if (i > j) {

                    std::cout << MAGENTA << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << " "; 

                }
                else {

                    std::cout << BOLDON << WHITE << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << BOLDOFF << " ";

                }

            }

            std::cout << "\n";

        }

        std::cout << "\n";
        break;

        // Lower Triangle print.
        case 3:

        // No change to a vector.
        if (A.col == 1) return;

        for (size_t i = 0; i < A.row; i++) {

            for (size_t j = 0; j < A.col; j++) {

                if (i == j) {

                    std::cout << GREEN << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << " ";

                }
                else if (i < j) {

                    std::cout << MAGENTA << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << " "; 

                }
                else {

                    std::cout << BOLDON << WHITE << std::setfill('0') << std::setw(spacing)
                    << A.M[i * A.col + j] << RESET << BOLDOFF << " ";

                }

            }

            std::cout << "\n";

        }

        std::cout << "\n";
        break;

        default:
        std::cout << RED << BOLDON << "Error: Your IQ is comparable to your shoe size.\n" << RESET << BOLDOFF;
    
    }

}