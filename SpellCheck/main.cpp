// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: main.cpp 03/26/20

#include <iostream>
#include <fstream>
#include <cctype>
#include "jspace.h"
#include "chain.h"
#include "Dictionary.h"
#include "timer.h"

// Function to load the txt database into
// the Dictionary hash table.
void loadDatabase(std::ifstream & txtfile, Dictionary & dict);

bool * needsCorrection(Dictionary & dict, std::string * words, unsigned len);

int main(int argc, char ** argv) {

	// Create the hash table with 10007 buckets.
	Dictionary dict(10007);

	// Incorrect arguments error.
	if (argc != 2) {

		std::cerr << "bro thats not epic, we need 2 arguments not " << argc << " arguments.\n";
		return -1;

	}
	else {

		// File stream for loading the database.
		std::ifstream infile(argv[1]);

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

		}

		infile.close();

	}
	std::string unparsable;
	std::cout << "\n---------------------------------------------------\n";
	std::cout << "Please enter some text: ";
	std::getline(std::cin, unparsable);

	// File tricks for parsing >:)
	std::ofstream outfile("temp.txt");
	outfile << unparsable;
	outfile.close();
	std::ifstream infile("temp.txt");
	std::string word;
	unsigned numWords = 0;

	// Count the words.
	while(infile >> word) {
		numWords++;
	}

	// Collect the words for correction.
	infile.clear();
	infile.seekg(0, std::ios::beg);
	std::string * words = new std::string[numWords];
	unsigned l = 0;
	while(infile >> word) {

		words[l++] = word;

	}

	// TODO: check for suggestions.
	bool * needsSuggestion = needsCorrection(dict, words, numWords);
	

	delete [] words;
	delete [] needsSuggestion;
	return 0;
}

void loadDatabase(std::ifstream & txtfile, Dictionary & dict) {

	std::string word;
	while(txtfile >> word) {

		dict.inscribe(word);

	}

}

bool * needsCorrection(Dictionary & dict, std::string * words, unsigned len) {

	bool * arr = new bool[len];

	if (!dict.inDictionary(words[0])) {

		words[0][0] = isupper(words[0][0]) ? tolower(words[0][0]) : toupper(words[0][0]);

		if (!dict.inDictionary(words[0])) {

			arr[0] = true;

		}
		else {

			arr[0] = false;

		}

		words[0][0] = isupper(words[0][0]) ? tolower(words[0][0]) : toupper(words[0][0]);

	}

	for (unsigned i = 1; i < len; i++) {

		std::cout << "i: " << i << "\n";

		if (!dict.inDictionary(words[i])) {

			arr[i] = true;

		}
		else {

			arr[i] = false;

		}

	}

	return arr;

}
