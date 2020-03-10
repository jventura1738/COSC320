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
#include "datalist.h"
#include <iomanip>
#include <cmath>

// Colors to be cool.
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define WHITE   "\033[37m"      /* White */
#define BOLDON  "\e[1m"
#define BOLDOFF "\e[0m"

int main (int argc, char *argv[]) {

    if (argc != 2) {
        // Should be in the form: ./IOModel <filename.txt>
        std::cout << RED << "2 arguments expected, " << argc << " arguments recieved.\n" << RESET;
        return 0;
    }
    else {
        std::ifstream IOModel(argv[1]);
        try {
            if (!IOModel.is_open()) {
                throw std::string("File missing/corrupted.\n")
            }
        }
        catch(std::string errmsg) {
            std::cout << errmsg << "\n";
            return 0;
        }
        std::string *
        size_t dimensions = 0;
        while (IOModel >> traverse) {
            if (traverse == "---") {
                break;
            }
            dimensions++;
        }
        float data = 0;
        while (IOModel >> data) {
            
        }
    }

    return 0;
}