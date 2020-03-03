// Justin Ventura COSC320
// Joe Anderson (heap.cpp)
// Lab-5

#include "heapq.h"
#include "jspace.h"
#include <cmath>

// Private member to increase key.
template <typename T>
void HeapQ<T>::increase_key(int i, int k) {
	
	// already in correct position of the tree.
	if (this->arr[i].key > k) return;

	// going up the tree.
	this->arr[i].key = k;
	while (i != 0 && this->arr[i].key > this->arr[i/2].key) {

		jspace::swap(&this->arr[i], &this->arr[i/2]);
		i = i/2;

	}
}

// Push back Private method.
template <typename T>
void HeapQ<T>::push_back() {

	HeapObj * arr2 = new HeapObj[this->length++];

	for (int i = 0; i < this->length - 1; i++) {
		arr2[i].data = this->arr[i].data;
		arr2[i].key = this->arr[i].key;
	}

	delete [] this->arr;
	this->arr = arr2;

}

// Private function to maintain the max heap.
template <typename T>
void HeapQ<T>::max_heapify(int & i) {
    int l = 2 * i;
    int r = ((2 * i) + 1);
    int max;
    if (l <= this->heap_size && this->arr[l].key > this->arr[i].key) {
        max = l;
    }
    else {
        max = i;
    }
    if (r <= this->heap_size && this->arr[r].key > this->arr[max].key) {
        max = r;
    }
    if (max != i) {

   	jspace::swap(&this->arr[i], &this->arr[max])
    max_heapify(max);

    }
}

// Main Constructor.
template <typename T>
HeapQ<T>::HeapQ(const int & n) : length(n), heap_size(0) {

	// cannot make array of negative size.
	if (n < 1) {

		std::cout << "incorrect length.\n";
		throw std::string("ERROR: Array length must be >= 1.\n");

	}

	// create the priority queue of the given size.
	this->arr = new HeapObj[n];

}

// Dequeue or "Extract-Max."
template <typename T>
T & HeapQ<T>::dequeue() {

	// bounds check
	if (this->heap_size < 1) {

		throw std::string("Queue is currently empty.\n");

	}

	T temp = this->arr[0].data;
	this->arr[0] = this->arr[this->heap_size - 1];
	this->heapsize--;
	max_heapify(0);
	return temp;

}

// Enqueue method.  If priority queue is full, the method
// will attempt to expand the queue via push_back. This
// assumes there is enough dynamic memory to do so.
// Throws std::string exception for negative priorities.
template <typename T>
void HeapQ<T>::enqueue(T d, int priority) {

	if (priority < 0) {

		throw std::string("ERROR: Priority must be positive.\n");

	}
	else if (this->heap_size == this->length - 1) {

		// push back the new data.
		this->push_back();

	}

	this->arr[++this->heap_size].data = d;
	this->arr[this->heap_size].key = -1;
	this->increase_key(this->heap_size, priority);

}

// Method to print the queue as a max heap.
template <typename T>
void HeapQ<T>::print_queue(int i, int d) {

    if (this->length < 1) {
        
		throw std::string("Heap is empty.\n");

    }

    std::cout << this->arr[i].data << "\n";

    int row_start = (2 * i) + 1;

    // keep track of the level.
    for (int k = 2; k <= d; k++) {

        for (int l = row_start; l < (row_start + pow(2, k-1)); l++) {

            if (l >= this->length || l >= this->heap_size) {
                std::cout << "* ";
            }
            // for incomplete levels of the tree.
            else {
                std::cout << this->arr[l].data << " ";
            }

        }
        std::cout << std::endl;
        row_start = (2 * row_start) + 1;
    }
}