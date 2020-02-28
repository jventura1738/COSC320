// Justin Ventura COSC320
// Joe Anderson (heap.h)
// Lab-5

#ifndef HEAPQ_H
#define HEAPQ_H

template <typename T>
class HeapQ {
private:

	// change arr[i].key to k.
	void increase_key(int & i, int & k);

	// expand the array if necessary.
	void push_back(int & value);

public:

	// Heap Object structure.
	struct HeapObj {

		T data;		// data value.
		int key;	// data priority.

	};

	// Heap Members.
	HeapObj<T> * arr;       // pointer to priority queue
	int length;			    // length of the array
	int heap_size;	        // size of the valid heap

	// Main Constructor.
	// You may pass in a STATIC array. If dynamically allocated, delete after.
	// Throws std::string if the array incorrect dimensions are given.
	HeapQ(const T * data, const int & n);

	// Destructor.
	~Heap() {
		//std::cout << "Heap Destroyed.\n";
		delete [] arr;
	}

	// Load data into the heap.
	void load_data(const T * data, const int & n);

};

#include "heapq.cpp"

#endif