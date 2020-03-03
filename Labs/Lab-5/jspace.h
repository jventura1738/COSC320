// Justin Ventura [HEADER]
// BASIC FUNCTIONS LIBRARY
// file: 'jspace.h'

#ifndef JSPACE_H
#define JSPACE_H

/*
 * This file was created to cover very basic methods
 * and functions that I find useful for everyday
 * tasks. Things I shouldn't have to code more than
 * once.
 * - justin ventura
*/

namespace jspace {

	// Method to swap to values passed by reference.
	// Overload any assignment operators if necessary.
	template <typename T>
	void swap(T * a, T * b);

}

#include "jspace.cpp"
#endif