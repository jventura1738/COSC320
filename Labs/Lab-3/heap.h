// Justin Ventura COSC320
// Joe Anderson (heap.h)

#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap {
public:
	T* arr;					// underlying array
	int length;			// length of the array
	int heap_size;	// size of the valid heap

	// Default Constructor.
	Heap() : length(-1), heap_size(-1) {
		//std::cout << "Heap Created. [EMPTY]\n";
	}

	// Main Constructor.
	// PASS IN A DYNAMICALLY ALLOCATED ARRAY.
	Heap(T* data, int& n);

	// Destructor.
	~Heap() {
		//std::cout << "Heap Destroyed.\n";
		delete [] arr;
	}

	// Array-like access overload.
	int& operator[](int i) {
		return this->arr[i];
	}

	// Load data into the heap.
	void load_data(T *data, int n);

};

#include "heap.cpp"

#endif