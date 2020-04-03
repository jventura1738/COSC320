// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: chain.cpp  03/26/20

#include "chain.h"

// Constructor.
chain::chain() {

	//std::cout << "chain constructed.\n";
	this->head = nullptr;

}

// Copy constructor.
chain::chain(const chain & obj) {

	link * cursor = obj.head;
	this->head = cursor;
	while(cursor) {

		this->append(cursor->data);
		cursor = cursor->next;

	}

}

// Destructor.
chain::~chain() {

	if (this->head) {

		while (this->head->next) {

			head = head->next;
			delete head->prev;

		}
		delete head;

	}

}

// Prepend function.
void chain::prepend(const std::string & word) {

	link * insert = new link(word);
	if (this->head) {

		this->head->prev = insert;
		insert->next = this->head;
		this->head = insert;

	}
	else {

		this->head = insert;
		return;

	}

}

// Append function.
void chain::append(const std::string & word) {

	link * insert = new link(word);
	if (!this->head) {

		this->head = insert;

	}
	else {

		link * cursor = this->head;
		while(cursor->next) {

			cursor = cursor->next;

		}

		cursor->next = insert;

	}

}

// Method to check if a word is a link.
bool chain::inChain(const std::string word) {

	std::cout << "bruh: " << word << "\n";

	if (!this->head) {

		return false;

	}
	link * cursor = this->head;
	while (cursor) {

		if (cursor->data == word) {

			return true;

		}

		cursor = cursor->next;

	}

	return false;

}

// Method to print the chain from head to end;
void chain::print() {

	link * cursor = this->head;
	while(cursor) {

		std::cout << "*" << cursor->data << "* ";
		cursor = cursor->next;

	}

}

// Assignment operator overload.
chain & chain::operator=(const chain & obj) {

	if (this->head) {

		while (this->head->next) {

			head = head->next;
			delete head->prev;

		}
		delete head;

	}

	link * cursor = obj.head;
	this->head = cursor;
	while(cursor) {

		this->append(cursor->data);
		cursor = cursor->next;

	}
	return *this;

}
