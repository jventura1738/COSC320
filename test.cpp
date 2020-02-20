#include <iostream>
#include <fstream>

int main () {

    std::ifstream inFile;
    int counter = 0, cursor, sum = 0;
    float avg = 0;

    inFile.open("numbers.txt");

    if (!inFile) {
        std::cout << "Error. File not opening.\n";
    }
    while (inFile >> cursor) {
        sum += cursor;
        counter++;
    }
    avg = float(sum)/counter;
    
    std::cout << "Numbers in file: " << counter << "\n";
    std::cout << "Running total: " << sum << "\n";
    std::cout << "Average: " << avg << "\n";

    return 0;
}