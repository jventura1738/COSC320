// Justin Ventura COSC320
// Joe Anderson (heap.cpp)
// Lab-5

#include "heapq.h"

// Main Constructor.
template <typename T>
HeapQ<T>::HeapQ(const T * data, const int & n) : length(n), heap_size(0) {

	if (n < 1) {

		throw std::string("ERROR: Array length must be >= 1.\n");

	}
	// prevent seg faults.
	else if ((*(&arr + 1) - arr) != n){

		throw std::string("ERROR: passed dimensions do not match actual dimensions.\n");

	}
	// copy given array to heap array.
	this->arr = new HeapObj<T>[n];

	for (int i = 0; i < n; i++) {

		this->arr[i].data = data[i];

	}
}

template <typename T>
void HeapQ<T>::load_data(const T *data, const int & n) {
      if (n != this->length) {
          std::cout << "NOTE: length changed.\n";
          this->length = n;
		  delete [] this->arr;
		  this->arr = new T[this->length];
      }
      else if (this->length == -1){
      	this->arr = new T[n];
      }
      for (int i = 0; i < this->length; i++) {
          this->arr[i] = data[i];
      }
  }
