// Justin Ventura COSC320
// Joe Anderson (heap.cpp)
// Lab-5

#include "heapq.h"
#include <cmath>

// Private member to increase key.
template <typename T>
void HeapQ<T>::increase_key(int i, int k) {
	
	// already in correct position of the tree.
	if (this->arr[i].key > k) return;

	// going up the tree.
	this->arr[i].key = k;
	while (i != 0 && this->arr[i].key > this->arr[i/2].key) {

		HeapObj temp = this->arr[i];
		this->arr[i] = this->arr[i/2];
		this->arr[i/2] = temp;
		i = i/2;

	}
}

// Push back Private method.
template <typename T>
void HeapQ<T>::push_back(int & value) {

	HeapObj * arr2 = new HeapQ[this->length++];

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
    if (l <= this->heap_size && this->arr[l].data > this->arr[i].data) {
        max = l;
    }
    else {
        max = i;
    }
    if (r <= this->heap_size && this->arr[r].data > this->arr[max].data) {
        max = r;
    }
    if (max != i) {

		HeapObj temp = this->arr[i];
		this->arr[i] = this->arr[max];
		this->arr[max] = temp;
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

template <typename T>
void HeapQ<T>::enqueue(T d, int priority) {

	this->arr[++this->heap_size - 1].data = d;
	this->arr[this->heap_size - 1].key = (-1);
	increase_key(this->heap_size - 1, priority);

}

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
        //std::cout << "row start: " << row_start << std::endl;
        std::cout << std::endl;
        row_start = (2 * row_start) + 1;
    }
}