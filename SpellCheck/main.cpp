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

// EXTRA CREDIT: function to ask the user if
// they wish to add a suggestion to the file
// dictionary.
void extraCreditDictUpdate(char * filename);

// EXTRA CREDIT: function to put all mispelled
// words in the dictionary.
void extraCreditDictUpdate(std::string * words, bool * fix, unsigned numWords, char * filename);

// Prints all mispelled words.
void printMispelled(std::string * words, bool * fix, unsigned len);

// Function which returns a chain containing all suggestions for the given
// words.
chain correctionResults(Dictionary & dict, std::string & word);

// Show all suggestions.
chain showSuggestions(Dictionary & dict, char * filename, std::string * words, bool * fix, unsigned len);

// Function to load the txt database into
// the Dictionary hash table.
void loadDatabase(std::ifstream & txtfile, Dictionary & dict);

// Parse the entered string to make a viable pool
// for suggestions. Returns the total number of
// substrings parsed.
std::string * parseSetup(std::string * unparsable, unsigned & numWords);

// Function that returns a boolean to whether or not
// a word in the passed array needs correction.
bool * needsCorrection(Dictionary & dict, std::string * words, unsigned len);

// Prepends new suggestions to the chain.
void repChar(chain * list, Dictionary & dict, std::string & word);

// Prepends new suggestions to the chain.
void addChar(chain * list, Dictionary & dict, std::string & word);

// Prepends new suggestions to the chain.
void remChar(chain * list, Dictionary & dict, std::string & word);

// Prepends new suggestions to the chain.
void swpChar(chain * list, Dictionary & dict, std::string & word);

// Global variables for my convenience
unsigned suggestionscnt = 0;
unsigned incorrectWords = 0;
unsigned extraCreditCount = 0;

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
	std::cout << "---------------------------------------------------\n";

	unsigned numWords = 0;
	std::string * words = parseSetup(&unparsable, numWords);
	bool * needsSuggestion = needsCorrection(dict, words, numWords);
	extraCreditHighlight(words, needsSuggestion, numWords);
	chain extraCredit = showSuggestions(dict, argv[1], words, needsSuggestion, numWords);

	std::cout << "---------------------------------------------------\n";
	std::cout << "\nAdd mispelled words to the dictionary?\n";
	std::cout << "(1) yes (0) no\n";
	int update = jspace::binaryChoice();
	if (update) {

		extraCreditDictUpdate(words, needsSuggestion, numWords, argv[1]);

	}
	else {

		std::cout << "\n---------------------------------------------------\n";
		std::cout << "\nWould you like to add words to the dictionary instead?\n";
		std::cout << "(1) yes (0) no\n";
		update = jspace::binaryChoice();
		if (update) {

			extraCreditDictUpdate(argv[1]);

		}

	} 

	std::cout << "\nThanks for using Justin's Spell Checker!\n";


	delete [] words;
	delete [] needsSuggestion;

	return 0;

}


// EXTRA CREDIT HIGHLIGHT INCORRECT WORDS.
void extraCreditHighlight(std::string * words, bool * fix, unsigned len) {

	std::cout << "\n";

	for (unsigned i = 0; i < len; i++) {

		// if (!fix[i]) {

		// 	std::cout << words[i] << " ";

		// }
		// else {

			std::cout << FORERED << words[i] << RESET << " ";
			incorrectWords++;

		// }

	}

	std::cout << "\n";

}

// EXTRA CREDIT: function to ask the user if
// they wish to add a suggestion to the file
// dictionary.
void extraCreditDictUpdate(char * filename) {

	std::cout << "---------------------------------------------------\n";
	std::cout << "Enter each word you would like to add to the dictionary:\n";
	std::cout << "          (separated by spaces, no *'s)            \n\n";
	std::cout << "--> ";

	unsigned wordCount = 0;
	std::string parsable;
	std::cin.ignore(INT32_MAX, '\n');
	std::getline(std::cin, parsable);
	std::string * words = parseSetup(&parsable, wordCount);

	std::ofstream outfile;
	outfile.open(filename, std::ios_base::app);

	for (unsigned i = 0; i < wordCount; i++) {

		outfile << words[i] << "\n";

	}

	std::cout << "\nWords successfully added!\n";
	outfile.close();
	delete [] words;

}

// EXTRA CREDIT: function to put all mispelled
// words in the dictionary.
void extraCreditDictUpdate(std::string * words, bool * fix, unsigned numWords, char * filename) {

	std::ofstream outfile;
	outfile.open(filename, std::ios_base::app);

	for (unsigned i = 0; i < numWords; i++) {

		if (fix[i]) {

			outfile << words[i] << "\n";

		}

	}
	std::cout << "\nWords successfully added!\n";

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

// Collect correction results.
chain correctionResults(Dictionary & dict, std::string & word) {

	chain corrections;

	repChar(&corrections, dict, word);
	addChar(&corrections, dict, word);
	remChar(&corrections, dict, word);
	swpChar(&corrections, dict, word);

	return corrections;

}

// Show all suggestions.
chain showSuggestions(Dictionary & dict, char * filename, std::string * words, bool * fix, unsigned len) {

	Timer timer;
	chain done;
	chain extraCredit;
	unsigned twoeditcount = 0;
	timer.start_timer();
	for (unsigned i = 0; i < len; i++) {

		if (fix[i] && !done.inChain(words[i])) {

			chain corrections = correctionResults(dict, words[i]);
			chain::link * trav = corrections.head;
			while (trav) {

				done.prepend(trav->data);
				if (!extraCredit.inChain(trav->data)) {

					extraCredit.prepend(trav->data);
					extraCreditCount++;

				}
				twoeditcount++;
				trav = trav->next;

			}
			std::cout << "\n---------------------------------------------------\n";
			std::cout << "\nThe following word is mispelled: " << FORERED << words[i] << RESET << "\n";
			if (corrections.head) {

			std::cout << "Suggestions for: " << words[i] << "\n";
			corrections.print();
			std::cout << "\n";

			}
			else {

				std::cout << "No suggestions found in " << filename << ".\n";

			}

		}

	}
	std::string * words2 = new std::string[twoeditcount];
	chain::link * cursor = done.head;
	chain done2;
	unsigned idx = 0;
	while(cursor) {

		if (!done2.inChain(cursor->data)) {

			words2[idx] = cursor->data;
			done2.prepend(words2[idx]);
			idx++;

		}
		cursor = cursor->next;

	}
	cursor = nullptr;

	timer.end_timer();
	std::cout << "\n---------------------------------------------------\n";
	std::cout << "Would you like to see words within two edit distances?\n";
	std::cout << "There may be a lot: (1) yes (0) no.\n";
	short choice = jspace::binaryChoice();
	timer.start_timer();

	if (choice) {

		std::cout << "\n\n---------------------------------------------------\n";
		std::cout << "Here are all suggestions within 2 edit distances...\n\n";
		for (unsigned i = 0; i < idx; i++) {

			chain corrections = correctionResults(dict, words2[i]);
			if (corrections.head) {

				std::cout << "Suggestions for: " << FORERED << words2[i] << RESET << "\n";
				corrections.print();
				std::cout << "\n\n";

			}
			else {

				std::cout << "Suggestions for: " << FORERED << words2[i] << RESET << "\n";
				std::cout << "No suggestions found in " << filename << ".\n\n\n";

			}

		}

	}
	
	timer.end_timer();
	std::cout << "\n---------------------------------------------------\n";
	std::cout << "Summary:\n";
	std::cout << "---------------------------------------------------\n\n";
	std::cout << "Total mispelled words: " << incorrectWords << "\n";
	std::cout << "Total suggestions found: " << suggestionscnt << "\n";
	std::cout << "Total (user prompt time ignored) ";
	timer.display_time();
	timer.reset_time();
	delete [] words2;
	return extraCredit;

}

// Loads the txt database into the hash table.
void loadDatabase(std::ifstream & txtfile, Dictionary & dict) {

	std::string word;
	while(txtfile >> word) {

		dict.inscribe(word);

	}

}

// My sneaky parse ;)
std::string * parseSetup(std::string * unparsable, unsigned & numWords) {

	// File tricks for parsing >:)
	std::ofstream outfile("temp.txt");
	outfile << *unparsable;
	outfile.close();
	std::ifstream infile("temp.txt");
	std::string word;

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

	return words;

}

// Determins if a word needs correction. (excuses capitals in the first word)
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
					list->prepend(word);

				}

			}

		}
		// Brute force the ascii table for matches [lower].
		for (unsigned j = 97; j <= 122; j++) {

			word[i] = j;
			if (dict.inDictionary(word)) {

				if (!list->inChain(word)) {

					suggestionscnt++;
					list->prepend(word);

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
					list->prepend(dummy2);

				}

			}

		}
		// Brute force the ascii table for matches [lower].
		for (unsigned j = 97; j <= 122; j++) {

			dummy2[i] = j;
			if (dict.inDictionary(dummy2)) {

				if (!list->inChain(dummy2)) {

					suggestionscnt++;
					list->prepend(dummy2);

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
				list->prepend(dummy2);

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
					list->prepend(dummy);

				}

			}

		}

	}

}


