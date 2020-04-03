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

// EXTRA CREDIT HIGHLIGHT INCORRECT WORDS.
void extraCreditHighlight(std::string * words, bool * fix, unsigned len);

// Prints all mispelled words.
void printMispelled(std::string * words, bool * fix, unsigned len);

// Show all suggestions.
void showSuggestions(chain * suggestions, std::string * words, unsigned len);

// Function to load the txt database into
// the Dictionary hash table.
void loadDatabase(std::ifstream & txtfile, Dictionary & dict);

// Function that returns a boolean to whether or not
// a word in the passed array needs correction.
bool * needsCorrection(Dictionary & dict, std::string * words, unsigned len);

// Function which returns a chain containing all suggestions for the given
// words.
chain correctionResults(Dictionary & dict, std::string * words, bool * fix, unsigned len);

// Prepends new suggestions to the chain.
void repChar(chain * list, Dictionary & dict, std::string & word);

// Prepends new suggestions to the chain.
void addChar(chain * list, Dictionary & dict, std::string & word);

// Prepends new suggestions to the chain.
void remChar(chain * list, Dictionary & dict, std::string & word);

// Prepends new suggestions to the chain.
void swpChar(chain * list, Dictionary & dict, std::string & word);

unsigned suggestionscnt = 0;
unsigned incorrectWords = 0;

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
	std::cout << "---------------------------------------------------\n\n";

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

	bool * needsSuggestion = needsCorrection(dict, words, numWords);
	extraCreditHighlight(words, needsSuggestion, numWords);
	Timer timer;
	chain corrections = correctionResults(dict, words, needsSuggestion, numWords);
	timer.end_timer();

	std::cout << "\n---------------------------------------------------\n";
	std::cout << "\nThe following words are mispelled! \n";
	printMispelled(words, needsSuggestion, numWords);

	std::cout << "---------------------------------------------------\n";
	std::cout << "BRUH\n";
	showSuggestions(&corrections, words, numWords);

	// chain::link * cursor = corrections.head;
	// unsigned twoeditcount = 0;
	// while(cursor) {

	// 	if (cursor->data != "_SPACER-BOI_") {

	// 		twoeditcount++;

	// 	}
	// 	cursor = cursor->next;

	// }
	// std::cout << "BRUH2\n";
	// cursor = nullptr;
	// std::string * words2 = new std::string[twoeditcount];
	// bool * needsSuggestion2 = new bool[twoeditcount];

	// std::cout << "BEFORE\n";
	// chain::link * cursor2 = (corrections.head);
	// std::cout << "AFTER\n";
	// std::cout << "\nCURSOR: " << cursor->data << "\n";
	// unsigned idx = 0;
	// while(cursor2) {

	// 	if (cursor2->data != "_SPACER-BOI_") {

	// 		words2[idx] = cursor2->data;
	// 		needsSuggestion2[idx++] = true;

	// 	}
	// 	cursor2 = cursor2->next;

	// }

	// std::cout << "\n---------------------------------------------------\n";
	// for (unsigned i = 0; i < twoeditcount; i++) {

	// 	std::cout << words[i] << " ";

	// }
	// std::cout << "\n\n---------------------------------------------------\n";

	// timer.start_timer();
	// chain corrections2 = correctionResults(dict, words2, needsSuggestion2, twoeditcount);
	// timer.end_timer();

	// std::cout << "\n---------------------------------------------------\n";
	// std::cout << "\nThe following words are mispelled! \n";
	// printMispelled(words, needsSuggestion, numWords);

	// std::cout << "---------------------------------------------------\n";
	// showSuggestions(&corrections, words, numWords);
	// std::cout << "Two edit distances: \n";
	// std::cout << "\n---------------------------------------------------\n";
	// showSuggestions(&corrections2, words2, twoeditcount);

	std::cout << "\n---------------------------------------------------\n";
	std::cout << "Summary\n";
	std::cout << "---------------------------------------------------\n\n";
	std::cout << "Total mispelled words:   " << incorrectWords << "\n";
	std::cout << "Total suggestions found: " << suggestionscnt << "\n";


	// TODO 2 EDITS.

	delete [] words;
	//delete [] words2;
	delete [] needsSuggestion;
	return 0;

}


// EXTRA CREDIT HIGHLIGHT INCORRECT WORDS.
void extraCreditHighlight(std::string * words, bool * fix, unsigned len) {

	for (unsigned i = 0; i < len; i++) {

		if (!fix[i]) {

			std::cout << words[i] << " ";

		}
		else {

			std::cout << FORERED << words[i] << RESET << " ";
			incorrectWords++;

		}

	}

	std::cout << "\n";

}

// Prints all mispelled words.
void printMispelled(std::string * words, bool * fix, unsigned len) {

	for (unsigned i = 0; i < len; i++) {

		if (fix[i]) {

			std::cout << words[i] << " ";

		}

	}

	std::cout << "\n\n";

}

// Show all suggestions.
void showSuggestions(chain * suggestions, std::string * words, unsigned len) {

	chain done;

	chain::link * cursor = suggestions->head;
	for (int i = 0; i < len; i++) {

		if (cursor->data == "_SPACER-BOI_") {

			cursor = cursor->next;
			continue;

		}
		else if (!done.inChain(words[i])){

			std::cout << "\nSuggestions for " << words[i] << ": ";
			while(cursor->data != "_SPACER-BOI_" && cursor->next) {

				std::cout << "*" <<  cursor->data << "* ";
				cursor = cursor->next;

			}
			i--;
			done.append(words[i]);

		}

	}

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

		if (!dict.inDictionary(words[i])) {

			arr[i] = true;

		}
		else {

			arr[i] = false;

		}

	}

	return arr;

}

chain correctionResults(Dictionary & dict, std::string * words, bool * fix, unsigned len) {

	chain corrections;

	for (unsigned i = 0; i < len; i++) {

		if(fix[i]) {

			unsigned tempboi = suggestionscnt;

			repChar(&corrections, dict, words[i]);
			addChar(&corrections, dict, words[i]);
			remChar(&corrections, dict, words[i]);
			swpChar(&corrections, dict, words[i]);

			if (suggestionscnt == tempboi) {

				corrections.append("No suggestions found.");

			}

		}

		corrections.append("_SPACER-BOI_");

	}

	return corrections;

}

// Prepends new suggestions to the chain.
void repChar(chain * list, Dictionary & dict, std::string & word) {

	// Replace one char of the word at a time.
	for (unsigned i = 0; i < word.length(); i++) {

		char temp = word[i];

		// Brute force the ascii table for matches [UPPER].
		for (unsigned j = 65; j <= 90; j++) {

			word[i] = j;
			if (dict.inDictionary(word)) {

				if (!list->inChain(word)) {

					suggestionscnt++;
					list->append(word);

				}

			}

		}
		// Brute force the ascii table for matches [lower].
		for (unsigned j = 97; j <= 122; j++) {

			word[i] = j;
			if (dict.inDictionary(word)) {

				if (!list->inChain(word)) {

					suggestionscnt++;
					list->append(word);

				}

			}

		}

		word[i] = temp;

	}

}

// Prepends new suggestions to the chain.
void addChar(chain * list, Dictionary & dict, std::string & word) {

	char dummy[word.length() + 1];
	unsigned k = 1;
	unsigned f = 0;
	dummy[0] = 'A';
	while(word[f]) {

		dummy[k++] = word[f++];

	}
	std::string dummy2(dummy, k);

	// Replace one char of the word at a time.
	for (unsigned i = 0; i < k; i++) {

		// Brute force the ascii table for matches [UPPER].
		for (unsigned j = 65; j <= 90; j++) {

			dummy2[i] = j;
			if (dict.inDictionary(dummy2)) {

				if (!list->inChain(dummy2)) {

					suggestionscnt++;
					list->append(dummy2);

				}

			}

		}
		// Brute force the ascii table for matches [lower].
		for (unsigned j = 97; j <= 122; j++) {

			dummy2[i] = j;
			if (dict.inDictionary(dummy2)) {

				if (!list->inChain(dummy2)) {

					suggestionscnt++;
					list->append(dummy2);

				}

			}

		}

		 if (i+1 != k) {

			jspace::swap(&dummy2[i], &dummy2[i+1]);

		}

	}

}

// Prepends new suggestions to the chain.
void remChar(chain * list, Dictionary & dict, std::string & word) {

	// Delete a char one at a time.
	for (unsigned i = 0; i < word.length(); i++) {

		char dummy[word.length() - 1];
		unsigned j = 0, k = 0;
		while(word[j]) {

			if (j != i) {

				dummy[k++] = word[j];

			}
			j++;

		}
		std::string dummy2(dummy, j-1);

		// Check if char removal worked.
		if (dict.inDictionary(dummy2)) {

			if (!list->inChain(dummy2)) {

				suggestionscnt++;
				list->append(dummy2);

			}

		}

	}

}

// Prepends new suggestions to the chain.
void swpChar(chain * list, Dictionary & dict, std::string & word) {

	for (unsigned i = 0; i < word.length(); i++) {

		std::string dummy = word;

		for (unsigned j = 0; j < word.length(); j++) {

			if (i == j) continue;

			jspace::swap(&dummy[i], &dummy[j]);

			if (dict.inDictionary(dummy)) {

				if (!list->inChain(dummy)) {

					suggestionscnt++;
					list->append(dummy);

				}

			}

		}

	}

}


