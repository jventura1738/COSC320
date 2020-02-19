// Justin Ventura COSC320
// Lab-3 Dr. Joe Anderson
// 02/16/20

#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
// not compatible on mac for some reason.
//#include <bits/stdc++.h>
#include "timer.h"
#include "heap.h"

// print the given array.
template <typename T>
void printarr(T*, int);
// swap two integers by reference.
template <typename T>
void swap (T&, T&);
// checks if array is sorted.
template <typename T>
bool isSorted(T*, int);
// generate an array.
// 0 = random
// 1 = descending
// 2 = ascending
// true = duplicates
// false = no duppies
int* generate_array(int, bool, int);

// Max Heapify.  This function will be used
// To "heapify" part of a tree given an index
// i.  It will recurse down the tree in case
// of breaking the properties of a "Max Heap."
// Complexity: O(logn) with pessimism.
template <typename T>
void MaxHeapify(Heap<T>* A, int i) {
    int l = 2 * i;
    int r = ((2 * i) + 1);
    int max;
    if (l <= A->heap_size && A->arr[l] > A->arr[i]) {
        max = l;
    }
    else {
        max = i;
    }
    if (r <= A->heap_size && A->arr[r] > A->arr[max]) {
        max = r;
    }
    if (max != i) {
        swap(A->arr[i], A->arr[max]);
        MaxHeapify(A, max);
    }
}

// Build Max-Heap.  This will call Max Heapify
// to create a "Max Heap" out of the Heap obj
// passed into the function.
// Complexity: O(n * logn).
template <typename T>
void BuildMaxHeap(Heap<T> *A) {
    A->heap_size = A->length - 1;
    // length/2 is already floored, so we can
    // subtract 1 from the result safely.
    for (int i = (A->length/2) - 1; i >= 0; i--) {
        MaxHeapify(A, i);
    }
}

// Take advantage of the Max Heap structure
// to sort an array.  Pass in any ordered heap
// and it will be sorted.he first
// Complexity: (nlogn).
template <typename T>
void HeapSort(Heap<T> *A) {
    BuildMaxHeap(A);
    for (int i = A->length - 1; i >= 1; i--) {
        // We know A[i] is the largest among A[1,...,i], so move it
        // to the back, and consider it removed from the heap
        swap(A->arr[0], A->arr[A->heap_size]);
        A->heap_size -= 1;
        // We moved one of the smaller elements to the root, so we have to clean up
        MaxHeapify(A, 0);
    }
}

// Print the heap.  A is the heap, i is the
// root index to begin the (sub) tree, and
// d is the depth down from the root (root
// is the first from d)
template <typename T>
void print_heap(Heap<T> *A, int i, int d) {
    if (A->length < 1) {
        std::cout << "Empty Heap.\n";
        return;
    }
    std::cout << A->arr[i] << "\n";
    int row_start = (2 * i) + 1;

    for (int k = 2; k <= d; k++) {

        for (int l = row_start; l < (row_start + pow(2, k-1)); l++) {

            if (l >= A->length) {
                std::cout << "* ";
            }
            else {
                std::cout << A->arr[l] << " ";
            }

        }
        //std::cout << "row start: " << row_start << std::endl;
        std::cout << std::endl;
        row_start = (2 * row_start) + 1;
    }
}

/*
 * Lab-3, COSC320-002 for Joe Anderson
 * Coder: Justin Ventura
 *
 * INFO: below is the main for the lab
 * which will used the templated heap
 * sort to sort various data.
*/

int main () {
    Timer timer;
    int n = 32;
    int *data = new int[n];
    for (int i = 0; i < n; i++) {
        data[i] = i;
    }

    // test print
    Heap<int> test(data, n);
    print_heap(&test, 0, 6);

    // double *data2 = new double[n];
    //
    // data = generate_array(0, 0, n);
    // for (int i = 0; i < n; i++) {
    //     data2[i13 14 15 16 17 18 19 20 r] = double(data[i]);
    // }
    //
    // Heap<int> A(data, n);
    // Heap<double> B(data2, n);
    //
    // timer.start_timer();
    // HeapSort(&A);
    // timer.end_timer();
    // timer.display_time();
    // timer.reset_time();
    //
    // timer.start_timer();
    // HeapSort(&B);
    // timer.end_timer();
    // timer.display_time();
    // timer.reset_time();
    //
    // n = 20000000;
    // delete [] data;
    // delete [] data2;
    //
    // data2 = new double[n];
    //
    // data = generate_array(0, 0, n);
    // for (int i = 0; i < n; i++) {
    //     data2[i] = double(data[i]);
    // }
    //
    // A.load_data(data, n);
    // B.load_data(data2, n);
    //
    // timer.start_timer();
    // HeapSort(&A);
    // timer.end_timer();
    // timer.display_time();
    // timer.reset_time();
    //
    // timer.start_timer();
    // HeapSort(&B);
    // timer.end_timer();
    // timer.display_time();
    // timer.reset_time();

    // Size range: 50K - 150K
    // std::cout << "--- HEAPSORT DATA ---\n\n";
    // while (n <= 1000000) {
    //     // Create the necessary int array and store
    //     // it into a heap structure.
    //     int order = 0, duppies = 0;
    //     std::cout << "\n==============================\n";
    //     std::cout << "Trials for # elements = " << n << ":\n";
    //     std::cout << "==============================\n";
    //     if (n != 250000) delete [] data;
    //     data = generate_array(order++, duppies, n);
    //     Heap<int> tester(data, n);
    //
    //     // begin trials:
    //
    //     std::cout << "Array with randoms & no duppies: \n";
    //     timer.start_timer();
    //     HeapSort(&tester);
    //     timer.end_timer();
    //     timer.display_time();
    //     timer.reset_time();
    //
    //     if (!isSorted(tester.arr, n)) {
    //         std::cout << "WARNING: heap unsorted.\n";
    //         return 0;
    //     }
    //
    //     delete [] data;
    //     data = generate_array(order++, duppies, n);
    //     tester.load_data(data, n);
    //
    //     std::cout << "Array backwards & no duppies: \n";
    //     timer.start_timer();
    //     HeapSort(&tester);
    //     timer.end_timer();
    //     timer.display_time();
    //     timer.reset_time();
    //
    //     if (!isSorted(tester.arr, n)) {
    //         std::cout << "WARNING: heap unsorted.\n";
    //         return 0;
    //     }
    //
    //     delete [] data;
    //     data = generate_array(order, duppies++, n);
    //     tester.load_data(data, n);
    //
    //     std::cout << "Array pre-sorted & no duppies: \n";
    //     timer.start_timer();
    //     HeapSort(&tester);
    //     timer.end_timer();
    //     timer.display_time();
    //     timer.reset_time();
    //
    //     // now test with duplicates.
    //     std::cout << "\n";
    //     order = 0;
    //
    //     delete [] data;
    //     data = generate_array(order++, duppies, n);
    //     tester.load_data(data, n);
    //
    //     std::cout << "Array with randoms & duppies: \n";
    //     timer.start_timer();
    //     HeapSort(&tester);
    //     timer.end_timer();
    //     timer.display_time();
    //     timer.reset_time();
    //
    //     if (!isSorted(tester.arr, n)) {
    //         std::cout << "WARNING: heap unsorted.\n";
    //         return 0;
    //     }
    //
    //     delete [] data;
    //     data = generate_array(order++, duppies, n);
    //     tester.load_data(data, n);
    //
    //     std::cout << "Array backwards & duppies: \n";
    //     timer.start_timer();
    //     HeapSort(&tester);
    //     timer.end_timer();
    //     timer.display_time();
    //     timer.reset_time();
    //
    //     if (!isSorted(tester.arr, n)) {
    //         std::cout << "WARNING: heap unsorted.\n";
    //         return 0;
    //     }
    //
    //     delete [] data;
    //     data = generate_array(order, duppies, n);
    //     tester.load_data(data, n);
    //
    //     std::cout << "Array pre-sorted & duppies: \n";
    //     timer.start_timer();
    //     HeapSort(&tester);
    //     timer.end_timer();
    //     timer.display_time();
    //     timer.reset_time();
    //
    //     // increment for multiple trials
    //     std::cout << "\n\n";
    //     if (n == 1000000) delete [] data;
    //     n += 250000;
    // }
    //
    // std::cout << "Testing complete.\n";
    // return 0;
}

template <typename T>
void printarr(T* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
bool isSorted(T* arr, int n) {
    int i = 0;
    while (i < n - 1) {
        // my pointer understanding high ;)
        if (*(arr + i) > *(arr + (i + 1))) {
            return false;
        }
        i++;
    }
    return true;
}
int* generate_array(int order, bool dup, int n) {
    int *arr = new int[n];
    // creates the array with duplicates.
    if (dup) {
        int j = 1;
        for (int i = 0; i < n; i++) {
            arr[i] = j;
            if (i % 2 == 0) {
                j++;
            }
        }
    }
    // otherwise make the array normally.
    else {
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
    }
    // now decide the order
    switch (order) {
        // random.
        case 0: {
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                std::shuffle(arr, arr + n, std::default_random_engine(seed));
            }
            break;
        // descending.
        case 1:
            std::reverse(arr, arr + n);
    }
    return arr;
}
