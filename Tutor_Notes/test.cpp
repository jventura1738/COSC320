// Justin Ventura tutoring file
#include <iostream>
#include <fstream>
#include <cmath>

// Reads in binary numbers from file.
void binarynums(std::ifstream &);

int binToDec(char arr[], int length);

int main() {

	char letters[4] = {'A', 'B', 'C', 'D'};

	std::cout << letters[2] << "\n";

	std::ifstream infile;
	infile.open("BinaryNums.txt");

	binarynums(infile);

	infile.close();

	return 0;

}

void binarynums(std::ifstream & infile) {

	while (!infile.eof()) {

		int seqnum;
		infile >> seqnum;
		char binary[seqnum];
		bool isValid = true;

		for (int i = 0; i < seqnum; i++) {

			infile >> binary[i];
			if (binary[i] != '0' || binary[i] != '1') {

				isValid = false;

			}

		}

		if (isValid) {

			int decimalval = binToDec(binary, seqnum);
			std::cout << "Decimal val of " << binary << " is " << decimalval << "\n";

		}
		else {

			std::cout << binary << " is not a valid binary number.\n";

		}


	}

}

int binToDec(char arr[], int length) {

	int power = 0;
	int decimalval = 0;
	for (int i = length - 1; i >= 0; i--) {

		if (arr[i] == '0') {

			power++;

		}
		else {

			decimalval += pow(2, power);
			power++;

		}

	}

	return decimalval;

}
