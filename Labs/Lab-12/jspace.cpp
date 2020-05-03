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

	template <typename T>
	void print(T * arr, size_t length) {

		for (int i = 0; i < length; i++) {

			std::cout << arr[i] << " ";

		}

		std::cout << "\n";

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


	size_t * generate_array(size_t length) {

		size_t * arr = new size_t[length];
		for (int i = 0; i < length; i++) {

			arr[i] = i;

		}

		return arr;

	}

	template <typename T>
	T * copy(T * arr, size_t length) {

		T * newarr = new T[length];
		for (size_t i = 0; i < length; i++) {

			newarr[i] = arr[i];

		}

		return newarr;

	}

	template <typename T>
	bool isSorted(const T * arr, size_t length) {

		for (int i = 1; i < length; i++) {

			if (arr[i] < arr[i - 1]) {

				return false;

			}

		}

		return true;

	}

	bool binaryChoice() {
		
		int choice;
		std::cout << "---> ";
		std::cin >> choice;

		while (!std::cin.good() || (choice > 1 || choice < 0)) {

			std::cin.clear();
			std::cin.ignore(INT32_MAX, '\n');
			std::cout << "Invalid, re-enter ---> ";
			std::cin >> choice;

		}

		return (choice) ? true : false;

	}

	void printError(std::string errmsg) {

		std::cout << FORERED << "ERROR: " << errmsg << RESET << "\n";

	}

	void printEWarning(std::string warnmsg) {

		std::cout << FOREYEL << "ERROR: " << warnmsg << RESET << "\n";

	}

}