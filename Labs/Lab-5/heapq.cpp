// Justin Ventura COSC320
// Joe Anderson (heap.cpp)
// Lab-5

#include "heapq.h"

// Main Constructor.
template <typename T>
HeapQ<T>::HeapQ(const int & n) : length(n), heap_size(0) {

	if (n < 1) {

		throw std::string("ERROR: Array length must be >= 1.\n");

	}
	// prevent seg faults.
	else if ((*(&arr + 1) - arr) != n){

		throw std::string("ERROR: passed dimensions do not match actual dimensions.\n");

	}

	// copy given array to heap array.
	this->arr = new HeapObj<T>[n];

}