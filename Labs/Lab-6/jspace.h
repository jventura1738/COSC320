// Justin Ventura [HEADER]
// BASIC FUNCTIONS LIBRARY
// file: 'jspace.h'

#ifndef JSPACE_H
#define JSPACE_H

/*
 * This file was created to cover very basic tasks
 * and functions that I find useful for everyday
 * tasks. Things I shouldn't have to code more than
 * once.
 * - justin ventura
*/

namespace jspace {

	// Function to swap to values passed by reference.
	// Overload any assignment operators if necessary.
	template <typename T>
	void swap(T * a, T * b);

	// Function to print an array.  Be sure to overload
	// any ostream operators.
	template <typename T>
	void print(T * arr, size_t length);

	// Takes a double, and applies the functional floor.
	int floor(const double & quant);

	// Takes a double, and applies the functional ceiling.
	int ceil(const double & quant);

	// Reverses an array (meant for ascending arrays).
	template <typename T>
	void reverse(T * arr, int length);

	// Merge sort function for stable sorting.
	// Overload any comparison operators to
	// be sure the sort is defined properly.
	template <typename T>
	void sort(T * array, size_t length);
	template <typename T>
	void merge_sort(T *, int, int);
	template <typename T>
	void merge(T *, int, int, int);

	// Generate an array which will be dynamically allocated.
	int * generate_array(size_t length);

}

#include "jspace.cpp"
#endif