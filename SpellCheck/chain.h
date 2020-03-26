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
		link(std::string s) {
			data = s;
		}

	};

	// Head of the chain.
	link * head;

	// Chain constructor.
	chain();

	// Chain copy constructor.
	chain();

	// Destructor.
	~chain();


};

#endif
