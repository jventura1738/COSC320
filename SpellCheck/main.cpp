// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: main.cpp 03/26/20

#include <iostream>
#include <fstream>
#include "jspace.h"
#include "chain.h"
#include "Dictionary.h"
#include "timer.h"

// Function to load the txt database into
// the Dictionary hash table.
void loadDatabase(std::ifstream & txtfile, Dictionary & dict);

int main(int argc, char ** argv) {

	// Incorrect arguments error.
	if (argc != 2) {

		std::cerr << "bro thats not epic, we need 2 arguments not " << argc << " arguments.\n";
		return -1;

	}
	else {

		// File stream for loading the database.
		std::ifstream infile(argv[1]);

		// Create the hash table with 10007 buckets.
		Dictionary dict(10007);

		// Timer object to time the operations.
		Timer timer;

		// Catch an error with the file opening process.
		if (!infile) {

			std::cerr << "bro the file didnt open. L\n";
			return -1;

		}
		else {

			std::cout << "Welcome to Spell Checker!\n";
			std::cout << "---------------------------------------------------\n";
			std::cout << "Loading the database...\n";
			std::cout << "---------------------------------------------------\n";

			timer.start_timer();
			loadDatabase(infile, dict);
			timer.end_timer();
			dict.printStats();
			timer.display_time();
			timer.reset_time();

			unsigned largest = dict._largestBucket();
			unsigned largeidx = 0;
			for (unsigned i = 1; i < 10007; i++) {

				if (dict.chainlength[i] > dict.chainlength[largeidx]) {
					largeidx = i;
				}

			}

			chain::link * curr = dict.table[largeidx].head;

			for (unsigned i = 0; i < largest; i++) {

				std::cout << curr->data << "\n";
				curr = curr->next;

			}

		}

	}

	return 0;
}

void loadDatabase(std::ifstream & txtfile, Dictionary & dict) {

	std::string word;
	while(txtfile >> word) {

		dict.inscribe(word);

	}

}