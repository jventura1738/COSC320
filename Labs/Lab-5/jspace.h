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

	// Takes a double, and applies the functional floor.
	int floor(const double & quant);

	// Takes a double, and applies the functional ceiling.
	int ceil(const double & quant);

	// Reverses an array (meant for ascending arrays).
	template <typename T>
	void reverse(T * arr, int length);

	// Merge sort method for stable sorting.
	// Overload any comparison operators to
	// be sure the sort is defined properly.
	template <typename T>
	void sort(T * array, size_t length);
	template <typename T>
	void merge_sort(T *, int, int);
	template <typename T>
	void merge(T *, int, int, int);

}

#include "jspace.cpp"
#endif