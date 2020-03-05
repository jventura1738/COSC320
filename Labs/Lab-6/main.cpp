// Justin Ventura COSC320
// Dr. Anderson Lab-6: main.cpp
#include <iostream>
#include "heap.h"
#include "timer.h"
#include "jspace.h"

int partition  (int * arr, int start, int end) {
    int piv = arr[end];
    int loc = (start - 1);
    for (int j = start; j <= end - 1; j++) {

        comp++; // comparison count
        if (arr[j] < piv) {
            loc++;
            swap(arr[loc], arr[j]);
        }
    }
    swap(arr[loc + 1], arr[end]); // insert pivot.
    return (loc + 1);
}
void quick_sort(int * arr, int start, int end) {
    if (start < end) {
        // getting location for pivot.
        int piv = partition(arr, start, end, comp);

        // sort before and after the partition.
        quick_sort(arr, start, piv - 1, comp);
        quick_sort(arr, piv + 1, end, comp);
    }
}
void merge(int * arr, int leftmost, int mid, int rightmost) {
    // size of leftmost and right sub-arrays
    int sub1 = mid - leftmost + 1;
    int sub2 = rightmost - mid;
    int i, j, k;
    // create the subarrays.
    int *subArr1 = new int[sub1];
    int *subArr2 = new int[sub2];

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
        comp++;
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
void merge_sort(int * array, int start, int end) {
   int mid;
   if(start < end) {
      mid = start + (end - start) / 2;
      // Sort first and second arrays recursively.
      merge_sort(array, start, mid, comp);
      merge_sort(array, mid + 1, end, comp);

      // merge the two arrays together.
      merge(array, start, mid, end, comp);
   }
}
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


int main () {

    return 0;

}