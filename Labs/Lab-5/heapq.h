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
	int length;			    		// length of the array
	int heap_size;	        // size of the valid heap

	// Main Constructor.
	// Pass in the size the queue should be initially.
	// Dynamically allocates the array of given size.
	HeapQ(const int & n);

	// Destructor.
	~Heap() {
		//std::cout << "Heap Destroyed.\n";
		delete [] arr;
	}

	// Peek at the top of the queue.
	const T & peek() const {

		return this->arr[0].data;

	}

	// Extract-Max to dequeue the highest priority data.
	T & dequeue() {

		return this->arr[0].data;

		// FINISH THIS
	}

};

#include "heapq.cpp"

#endif