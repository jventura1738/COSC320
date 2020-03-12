/* 
 * Justin Ventura, 03/09/20
 * COSC320-002, Dr. Anderson
 * Project 1: IOModel.cpp
*/

// Files included.
#include <iostream>
#include <fstream>
#include "matrix.h"
#include "jspace.h"
#include <iomanip>
#include <cmath>
#include <vector>

// Colors to be cool.a
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

int main (int argc, char **argv) {

    size_t argNumber = 1;

    std::cout << WHITE << "===========================================\n";
    std::cout << WHITE << "| Justin Ventura's total output calculator|\n";
    std::cout << WHITE << "| based on Leontif's I/O model which uses |\n";
    std::cout << WHITE << "| linear algebra techniques to perform the|\n";
    std::cout << WHITE << "| required output calculation defined by: |\n";
    std::cout << WHITE << "|                                         |\n";
    std::cout << WHITE << "|             x = (I - A) * d             |\n";
    std::cout << WHITE << "|                                         |\n";
    std::cout << WHITE << "| where x = total output vector,          |\n";
    std::cout << WHITE << "|       I = nxn identity matrix,          |\n";
    std::cout << WHITE << "|       A = inter-dependecny matrix,      |\n";
    std::cout << WHITE << "|   and d = external demand vector.       |\n";
    std::cout << WHITE << "===========================================\n\n" << RESET;

    if (argc < 2) {
        // Should be in the form: ./IOModel <filename.txt>
        std::cout << RED << "at least 2 arguments expected, " << argc << " arguments recieved.\n" << RESET;
        return 0;
    }
    else {
        while (argNumber < argc) {
            std::ifstream IOModel(argv[argNumber]);
            try {
                if (!IOModel.is_open()) {
                    throw std::string("File missing/corrupted.\n");
                }
            }
            catch(std::string errmsg) {
                std::cout << errmsg << "\n";
                return 0;
            }
            size_t dimensions = 0;
            std::string *traverse = new std::string[10000]; // Assumed max.
            while (IOModel >> traverse[dimensions]) {
                if (traverse[dimensions] == "---") {
                    break;
                }
                else if (dimensions >= 10000) {
                    std::cout << "Slow down buddy, matrix too big.\n";
                    return 0;
                }
                dimensions++;
            }
            Matrix A(dimensions, dimensions);
            Matrix I(dimensions, dimensions);
            Matrix d(dimensions, 1);
            float data = 0;
            size_t count = 0;
            while (IOModel >> data) {
                if (count == A.len) {
                    std::cout << "Error: sector count does not match given matrix.\n";
                    std::cout << "Aborting required output calculation.\n";
                    delete [] traverse;
                    return 0;
                }
                A.M[count] = data;
                count++;
            }
            IOModel.clear();
            while (IOModel >> traverse[dimensions]) {
                if (traverse[dimensions] == "--") {
                    break;
                }
            }
            count = 0;
            while (IOModel >> data) {
                if (count == d.len) {
                    std::cout << "Error: sector count does not match given demand.\n";
                    std::cout << "Aborting required output calculation.\n";
                    delete [] traverse;
                    return 0;
                }
                d.M[count] = data;
                count++;
            }
            init_identity(I);
            Matrix outputVector(dimensions, 1);
            try {
                outputVector = ((I - A).inverse()) * d;
            }
            catch(std::string errmsg) {
                std::cout << RED << errmsg << "\n";
                std::cout << "Inversion aborted, fix your shit. (input file)\n" << RESET;
                IOModel.close();
                delete [] traverse;
                continue;
            }
            IOModel.close();
            std::cout << "Resources needed for data in: " << argv[argNumber] << ":\n\n";
            std::cout << WHITE << "===========================================\n" << RESET;
            for (size_t i = 0; i < outputVector.len; i++) {
                std::cout << std::setfill(' ') << std::setw(15) << traverse[i] << ": " WHITE
                << BOLDON << outputVector.M[i] << BOLDOFF << RESET << " units.\n";
            }
            std::cout << WHITE << "===========================================\n\n" << RESET;
            delete [] traverse;
            argNumber++;
        }
    }
    return 0;
}