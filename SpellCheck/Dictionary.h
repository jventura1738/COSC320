// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: Dictionary.h 03/26/20

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <cmath.h>
#include "chain.h"

class Dictionary {
private:

	// Array of pointers to the chains.
	chain * table;

	// Corresponding bucket size tracker array
	// to the table.
	unsigned * chainlength;

	// Size of the table.
	unsigned T_SIZE;

	// Private method to hash a string to an
	// unsigned long integer.
	size_t _hash(std::string & word);

public:
	/*
	 * Constructors and Destructors for proper
	 * management of resources.
	*/

	// Default/Main constructor.
	Dictionary(unsigned dictionarysize);

	// Copy Constructor.
	Dictionary(const Dictionary & dict);

	// Destructor.
	~Dictionary();

	/*
	 * Other necessary methods & operator
	 * overloads for the Dictionary API.
	*/

	// Insert a word into the hash table O(1).
	void insert(std::string & word);

	// Assignment operator overload.
	Dictionary & operator=(const Dictionary & dict);

	/*
	 * Methods to calculate the statistics necessary
	 * as mentioned in the prompt.
	*/



};

#endif
