// Justin Ventura [SOURCE FILE]
// BASIC FUNCTIONS LIBRARY
// file: 'jspace.cpp'

#include "jspace.h"

/*
 * This file was created to cover very basic methods
 * and functions that I find useful for everyday
 * tasks. Things I shouldn't have to code more than
 * once.
 * - justin ventura
*/

namespace jspace {

	template <typename T>
	void swap(T * a, T * b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}

}