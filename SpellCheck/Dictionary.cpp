// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: Dictionary.cpp 03/26/20

#include "Dictionary.h"

// Default/Main constructor.
Dictionary::Dictionary(unsigned dictionarysize) {

	this->table = new chain[dictionarysize];
	this->chainlength = new unsigned[dictionarysize];
	this->T_SIZE = dictionarysize;

	for (unsigned i = 0; i < T_SIZE; i++) {
		this->chainlength[i] = 0;
	}

}

// Copy Constructor.
Dictionary::Dictionary(const Dictionary & dict) {

	this->table = new chain[dict.T_SIZE];
	this->chainlength = new unsigned[dict.T_SIZE];
	this->T_SIZE = dict.T_SIZE;

	for (unsigned i = 0; i < T_SIZE; i++) {
		this->table[i] = dict.table[i];
		this->chainlength[i] = dict.chainlength[i];
	}

}

// Destructor.
Dictionary::~Dictionary() {

	// std::cout << "Table destructed\n";
	delete [] table;
	delete [] chainlength;

}


size_t Dictionary::_hash(std::string & word) {

	size_t i = 0;
	size_t sum4hash = 0;
	// Generated from my python script
	const size_t PRIME1 = 1299709;
	const size_t PRIME2 = 10007;
	while(word[i]) {

		sum4hash += (size_t(word[i]) * (i+1));
		i++;

	}
	// Stop copying my code, buddy.
	return (sum4hash * PRIME1) % PRIME2;

}

// Insert a word into the hash table O(1).
void Dictionary::insert(std::string & word) {

	unsigned hashval = _hash(word);
	this->table[hashval].prepend(word);
	this->chainlength[hashval]++;

}

// Assignment operator overload.
Dictionary & Dictionary::operator=(const Dictionary & dict) {

	delete [] this->table;
	delete [] this->chainlength;

	this->table = new chain[dict.T_SIZE];
	this->chainlength = new unsigned[dict.T_SIZE];
	this->T_SIZE = dict.T_SIZE;

	for (unsigned i = 0; i < T_SIZE; i++) {
		this->table[i] = dict.table[i];
		this->chainlength[i] = dict.chainlength[i];
	}

	return *this;
}