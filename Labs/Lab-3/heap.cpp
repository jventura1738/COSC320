// Justin Ventura COSC320
// Joe Anderson (heap.cpp)

#include "heap.h"

// Main Constructor.
template <typename T>
Heap<T>::Heap(T* data, int& n) : length(n), heap_size(0) {
	if (n < 1) {
		std::cout << "ERROR: array size < 1. [-1]\n";
		this->length = -1;
	}
	//std::cout << "Heap Created with given array.\n";

	// copy given array to heap array.
	this->arr = new T[n];
	for (int i = 0; i < n; i++) {
		this->arr[i] = data[i];
	}
}

template <typename T>
void Heap<T>::load_data(T *data, int n) {
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
