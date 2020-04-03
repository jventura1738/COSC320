// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: chain.h 03/26/20

#include <iostream>

#ifndef CHAIN_H
#define CHAIN_H

// Chain class for hash table.
class chain {
public:

	// Link in the chain.
	struct link {
	public:
		std::string data;
		link * next;
		link * prev;

		// Constructor.
		link() {
			this->next = nullptr;
			this->prev = nullptr;
		}

		// Constructor.
		link(std::string s) {
			data = s;
			this->next = nullptr;
			this->prev = nullptr;
		}

		// Copy Constructor.
		link(link & l) {
			this->data = l.data;
			this->next = l.next;
			this->prev = l.prev;
		}

	};

	// Head of the chain.
	link * head;

	/*
	 * Chain class constructor(s) and
	 * destructors for dynamic memory
	 * management.
	*/

	// Chain constructor.
	chain();
	// Chain copy constructor.
	chain(const chain & obj);
	// Destructor.
	~chain();

	/*
	 * Necessary member functions for
	 * the chain class.
	*/

	// Method to insert a word at front.
	void prepend(const std::string word);

	// Method to insert a word at back.
	void append(const std::string & word);

	// Method to check if a word is a link.
	bool inChain(const std::string word);

	// Method to print the chain from head to end;
	void print();

	// Overloaded assignment operator.
	chain & operator=(const chain & obj);

};

#endif
