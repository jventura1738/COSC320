// Justin Ventura [SOURCE FILE]
// BASIC FUNCTIONS LIBRARY
// file: 'jspace.cpp'

#include "jspace.h"

/*
 * This file was created to cover very basic methods
 * and functions that I find useful for everyday
 * tasks. Things I shouldn't have to code more than
 * once.
 * - justin ventura
*/

namespace jspace {

	template <typename T>
	void swap(T * a, T * b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	int floor(const double & quant) {
		
		return (int(quant));

	}

	int ceil(const double & quant) {

		int result = int(quant);
		if (quant == float(result)) {
			return result;
		}
		return (result + 1);

	}

	template <typename T>
	void reverse(T * arr, int length) {

		int i, j = length - 1;
		for (int i = 0; i < (length/2); i++, j--) {

			swap(&arr[i], &arr[j]);

		}

	}

	template <typename T>
	void sort(T * array, size_t length) {

		merge_sort(array, 0, length);

	}

	template <typename T>
	void merge(T * arr, int leftmost, int mid, int rightmost) {
		// size of leftmost and right sub-arrays
		int sub1 = mid - leftmost + 1;
		int sub2 = rightmost - mid;
		int i, j, k;
		// create the subarrays.
		T *subArr1 = new T[sub1];
		T *subArr2 = new T[sub2];

		// fill leftmost and rightmost sub-arrays
		for(i = 0; i < sub1; i++)
			subArr1[i] = arr[leftmost + i];

		for(j = 0; j < sub2; j++)
			subArr2[j] = arr[mid + 1 + j];

		i = 0; 
		j = 0; 
		k = leftmost;

		// merge temp arrays to real array
		while(i < sub1 && j < sub2) {
			if(subArr1[i] <= subArr2[j]) {
				arr[k++] = subArr1[i++];
			}
			else {
				arr[k++] = subArr2[j++];
			}
		}
		while(i < sub1) { // for extra elements in leftmost array
			arr[k++] = subArr1[i++];
		}
		while(j < sub2) { // for extra elements in rightmost array
			arr[k++] = subArr2[j++];
		}

		delete [] subArr1;
		delete [] subArr2;
	}

	template <typename T>
	void merge_sort(T * array, int start, int end) {
		int mid;
		if(start < end) {
			mid = start + (end - start) / 2;
			// Sort first and second arrays recursively.
			merge_sort(array, start, mid);
			merge_sort(array, mid + 1, end);

			// merge the two arrays together.
			merge(array, start, mid, end);
		}
	}


}