// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: Dictionary.cpp 03/26/20

#include "Dictionary.h"

// Default/Main constructor.
Dictionary::Dictionary(unsigned dictionarysize) {

	this->table = new chain[dictionarysize];
	this->chainlength = new unsigned[dictionarysize];
	this->T_SIZE = dictionarysize;

	for (unsigned i = 0; i < this->T_SIZE; i++) {
		this->chainlength[i] = 0;
	}

}

// Copy Constructor.
Dictionary::Dictionary(const Dictionary & dict) {

	this->table = new chain[dict.T_SIZE];
	this->chainlength = new unsigned[dict.T_SIZE];
	this->T_SIZE = dict.T_SIZE;

	for (unsigned i = 0; i < this->T_SIZE; i++) {
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


size_t Dictionary::_hash(std::string & word) const {

	size_t i = 0;
	size_t sum4hash = 0;
	// Generated from my python script
	const size_t PRIME1 = 1299709;
	const size_t PRIME2 = 10007;
	while(word[i]) {

		sum4hash += (size_t(word[i]) * (PRIME1 - (i * sizeof(word) + 1)));
		i++;

	}
	// Stop copying my code, buddy.
	return (sum4hash * PRIME1) % PRIME2;

}

// Insert a word into the hash table O(1).
void Dictionary::inscribe(std::string & word) {

	unsigned hashval = _hash(word);
	this->table[hashval].prepend(word);
	this->chainlength[hashval]++;

}

// Checks if a given word is in the dictionary.
bool Dictionary::inDictionary(std::string & word) const {

	chain::link * cursor = this->table[_hash(word)].head;
	
	while (cursor) {

		if (cursor->data == word) {

			return true;

		}

		cursor = cursor->next;

	}

	return false;

}

// Assignment operator overload.
Dictionary & Dictionary::operator=(const Dictionary & dict) {

	delete [] this->table;
	delete [] this->chainlength;

	this->table = new chain[dict.T_SIZE];
	this->chainlength = new unsigned[dict.T_SIZE];
	this->T_SIZE = dict.T_SIZE;

	for (unsigned i = 0; i < this->T_SIZE; i++) {
		this->table[i] = dict.table[i];
		this->chainlength[i] = dict.chainlength[i];
	}

	return *this;
}

unsigned Dictionary::_totalWords() const {

	unsigned total = 0;
	for (unsigned i = 0; i < this->T_SIZE; i++) {
		total += this->chainlength[i];
	}
	return total;

}
unsigned Dictionary::_largestBucket() const {

	unsigned largest = 0;
	for (unsigned i = 1; i < this->T_SIZE; i++) {

		if (this->chainlength[i] > this->chainlength[largest]) {
			largest = i;
		}

	}
	return this->chainlength[largest];

}
unsigned Dictionary::_smallestBucket() const {

	// To ensure we only check used buckets.
	unsigned smallest = 0;
	while (this->chainlength[smallest] == 0) {
		smallest++;
	}

	for (unsigned i = 0; i < this->T_SIZE; i++) {

		if (this->chainlength[i] < this->chainlength[smallest] && this->chainlength[i] != 0) {
			smallest = i;
		}

	}
	return this->chainlength[smallest];

}

unsigned Dictionary::_usedBuckets() const {

	unsigned used = 0;
	for (unsigned i = 0; i < this->T_SIZE; i++) {

		if (this->chainlength[i] > 0) {
			used++;
		}

	}
	return used;

}
float Dictionary::_avgBucketSize() const {

	float avg = 0;
	for (unsigned i = 0; i < this->T_SIZE; i++) {

		avg += this->chainlength[i];

	}
	return (avg /= static_cast<float>(this->T_SIZE));

}

void Dictionary::printStats() const {

	std::cout << "Total words = " << this->_totalWords() << ".\n";
	std::cout << "Biggest bucket size = " << this->_largestBucket() << ".\n";
	std::cout << "Smallest bucket size = " << this->_smallestBucket() << ".\n";
	std::cout << "Total number of buckets = " << this->T_SIZE << ".\n";
	std::cout << "Number of used buckets = " << this->_usedBuckets() << ".\n";
	std::cout << "Average number of nodes in each bucket = " << this->_avgBucketSize() << ".\n"; 

}
