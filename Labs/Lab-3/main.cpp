// Justin Ventura COSC320
// Lab-2 Dr. Joe Anderson

#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
//#include <bits/stdc++.h>
#include "timer.h"
#include "heap.h"

// print the given array.
void printarr(int*, int);
// swap two integers by reference.
void swap (int&, int&);
// checks if array is sorted.
bool isSorted(int*, int);
// generate an array.
// 0 = random
// 1 = descending
// 2 = ascending
// true = duplicates
// false = no duppies
int* generate_array(int, bool, int);

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

template <typename T>
void BuildMaxHeap(Heap<T> *A) {
    A->heap_size = A->length - 1;
    for (int i = (A->length/2) - 1; i >= 0; i--) {
        MaxHeapify(A, i);
    }
}

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

template <typename T>
void print_heap(Heap<T> *A) {
    if (A->length < 1) {
        std::cout << "Empty Heap.\n";
        return;
    }
    int buffer = 2, i, track = 1;
    std::cout << A->arr[0] << "\n";

    for (i = 1; i < A->length; i++, track++) {
        std::cout << A->arr[i] << " ";
        if (track == buffer) {
            std::cout << "\n";
            buffer = buffer * 2;
            track = 0;
        }
    }
    while (track <= buffer) {
        std::cout << "* ";
        track++;
    }
    std::cout << "\n";
}

int main () {
    Timer timer;
    int arr[8];
    int n, order, temp;
    bool dups;
    size_t comps = 0;

    int size = 8;
    arr[0] = 4;
    arr[1] = 8;
    arr[2] = 1;
    arr[3] = 10;
    arr[4] = 7;
    arr[5] = -4;
    arr[6] = 0;
    arr[7] = 3;
    Heap<int> test(arr, size);

    for (int i = 0; i < 8; i++) {
        std::cout << test.arr[i] << " ";
    }
    std::cout << "\n";
    BuildMaxHeap(&test);
    print_heap(&test);
    std::cout << "\n";
    HeapSort(&test);
    for (int i = 0; i < 8; i++) {
        std::cout << test.arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

void printarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
bool isSorted(int* arr, int n) {
    int i = 0;
    while (i < n - 1) {
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
