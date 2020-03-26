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
	size_t * generate_array(size_t length);

	// Create a deep copy of an array and return it.
	// RETURNS A DYNAMICALLY ALLOCATED ARRAY.
	template <typename T>
	T * copy(T * arr, size_t length);

	// Check if an array is sorted or not.  This assumes
	// that comparison operators are properly functional.
	template <typename T>
	bool isSorted(const T * arr, size_t length);

}

/* FOREGROUND */
// These codes set the actual text to the specified color
#define RESET    "\x1B[0m"  // Set all colors back to normal.
#define FOREBLK  "\x1B[30m" // Black
#define FORERED  "\x1B[31m" // Red
#define FOREGRN  "\x1B[32m" // Green
#define FOREYEL  "\x1B[33m" // Yellow
#define FOREBLU  "\x1B[34m" // Blue
#define FOREMAG  "\x1B[35m" // Magenta
#define FORECYN  "\x1B[36m" // Cyan
#define FOREWHT  "\x1B[37m" // White

/* BACKGROUND */
// These codes set the background color behind the text.
#define BACKBLK "\x1B[40m"
#define BACKRED "\x1B[41m"
#define BACKGRN "\x1B[42m"
#define BACKYEL "\x1B[43m"
#define BACKBLU "\x1B[44m"
#define BACKMAG "\x1B[45m"
#define BACKCYN "\x1B[46m"
#define BACKWHT "\x1B[47m"

// These will set the text color and then set it back to normal afterwards.
#define BLK(x) FOREBLK x RESETTEXT
#define RED(x) FORERED x RESETTEXT
#define GRN(x) FOREGRN x RESETTEXT
#define YEL(x) FOREYEL x RESETTEXT
#define BLU(x) FOREBLU x RESETTEXT
#define MAG(x) FOREMAG x RESETTEXT
#define CYN(x) FORECYN x RESETTEXT
#define WHT(x) FOREWHT x RESETTEXT

// Example usage: cout << BLU("This text's color is now blue!") << endl;

// These will set the text's background color then reset it back.
#define BackBLK(x) BACKBLK x RESETTEXT
#define BackRED(x) BACKRED x RESETTEXT
#define BackGRN(x) BACKGRN x RESETTEXT
#define BackYEL(x) BACKYEL x RESETTEXT
#define BackBLU(x) BACKBLU x RESETTEXT
#define BackMAG(x) BACKMAG x RESETTEXT
#define BackCYN(x) BACKCYN x RESETTEXT
#define BackWHT(x) BACKWHT x RESETTEXT

// Example usage: cout << BACKRED(FOREBLU("I am blue text on a red background!")) << endl;

#include "jspace.cpp"
#endif