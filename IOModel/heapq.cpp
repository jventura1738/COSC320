// Justin Ventura COSC320
// Joe Anderson (heap.cpp)
// Lab-5

#include "heapq.h"
#include "jspace.h"
#include <cmath>

// Private member to increase key.
template <typename T>
void HeapQ<T>::increase_key(int i, int k) {
	
	// error, but no need to throw exception.
	if (this->arr[i].key > k) return;

	this->arr[i].key = k;

	// going up the tree.
	while (i > 0 && (this->arr[i].key > this->arr[jspace::ceil(i/2.0) - 1].key)) {

		jspace::swap(&this->arr[i], &this->arr[jspace::ceil(i/2.0) - 1]);
		i = jspace::ceil(i/2.0) - 1;

	}

}

// Push back Private method.
template <typename T>
void HeapQ<T>::push_back() {

	HeapObj * arr2 = new HeapObj[++this->length];

	for (int i = 0; i < this->length - 1; i++) {

		arr2[i].data = this->arr[i].data;
		arr2[i].key = this->arr[i].key;

	}

	delete [] this->arr;
	this->arr = arr2;

}

// Private function to maintain the max heap.
template <typename T>
void HeapQ<T>::max_heapify(int i) {

    int l = 2 * i + 1;
    int r = ((2 * i) + 2);
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

		jspace::swap(&this->arr[i], &this->arr[max]);
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
T HeapQ<T>::dequeue() {

	// bounds check
	if (this->heap_size < 1) {

		throw std::string("Queue is currently empty or broken.\n");

	}

	T temp = this->arr[0].data;
	this->arr[0].data = this->arr[this->heap_size - 1].data;
	this->arr[0].key = this->arr[this->heap_size - 1].key;
	this->heap_size--;
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
	else if (this->heap_size == this->length) {

		// push back the new data.
		this->push_back();

	}

	this->heap_size++;
	this->arr[this->heap_size - 1].data = d;
	this->arr[this->heap_size - 1].key = -1;
	this->increase_key(this->heap_size - 1, priority);

}

// Method to print the queue as a max heap.
template <typename T>
void HeapQ<T>::print_queue(int i, int d) {

    if (this->length < 1) {
        
			throw std::string("Heap is empty.\n");

    }

    std::cout << this->arr[i].data << "\n";

    // This will keep track of where the level (row) starts.
    int row_start = (2 * i) + 1;

    // This ensures that we print a partial tree, that is,
    // a sub-tree rooted at i, and with a depth d.
    for (int k = 2; k <= d; k++) {

    		// We only want the subtree.
        for (int l = row_start; l < (row_start + pow(2, k-1)); l++) {

        		// If part of the sub-tree is empty, print an asterisk.
            if (l >= this->length || l >= this->heap_size) {
                std::cout << "* ";
            }
            // for incomplete levels of the tree.
            else {
                std::cout << this->arr[l].data << " ";
            }

        }
				// Start the new level of the tree with a newline.
        std::cout << "\n";
        row_start = (2 * row_start) + 1;

    }

}