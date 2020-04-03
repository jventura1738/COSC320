// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: Dictionary.h 03/26/20

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "chain.h"

class Dictionary {
private:

	// Size of the table.
	unsigned T_SIZE;

	/*
	 * Private methods to calculate the statistics
	 * necessary as mentioned in the prompt.
	*/

	unsigned _totalWords()     const;
	unsigned _smallestBucket() const;
	unsigned _usedBuckets()    const;
	float    _avgBucketSize()  const;
	unsigned _totalBuckets()   const {
		return this->T_SIZE;
	}

public:

	// Private method to hash a string to an
	// unsigned long integer.
	size_t _hash(std::string & word) const;

	// Hash test.
	size_t hash(char * word) const;

	// Array of pointers to the chains.
	chain * table;

	// Corresponding bucket size tracker array
	// to the table.
	unsigned * chainlength;

	unsigned _largestBucket()  const;

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
	void inscribe(std::string & word);

	// Checks if a given word is in the dictionary.
	bool inDictionary(std::string & word) const;

	// Assignment operator overload.
	Dictionary & operator=(const Dictionary & dict);

	// Method to print the stats as prompted
	// in the project instructions.
	void printStats() const;

};

#endif
