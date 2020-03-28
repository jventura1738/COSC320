// Justin Ventura COSC320-002
// Project 2: Spell Check
// File: chain.cpp  03/26/20

#include "chain.h"

// Constructor.
chain::chain() {

	std::cout << "chain constructed.\n";
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
	insert->next = head;
	if (this->head) {

		this->head->prev = insert;

	}
	head = insert;

}

// Append function.
void chain::append(const std::string & word) {

	link * insert = new link(word);
	link * cursor = this->head;
	if (!cursor) {

		head = insert;
		return;

	}
	while(cursor->next) {

		cursor = cursor->next;

	}
	cursor->next = insert;
	insert->prev = cursor;

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
