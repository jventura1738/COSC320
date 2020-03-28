// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: main.cpp 03/26/20

#include <iostream>
#include <fstream>
#include "jspace.h"
#include "chain.h"

// Function to load the txt database into
// the Dictionary hash table.
void loadDatabase();

int main() {

	chain c;
	c.prepend("Justin");
	c.prepend("Jacob");
	std::cout << c.head->data << "\n";

	return 0;
}

void loadDatabase() {

	std::cout << "gamers\n";

}