// Justin Ventura COSC320
// Lab-2 Dr. Joe Anderson

#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <algorithm>
#include "timer.h"

// print the given array.
void printarr(int*, int);
// swap two integers by reference.
void swap (int&, int&);
// checks if array is sorted.
bool isSorted(int*, int);
// chooses pivot position in the array.
int partition (int*, int, int, size_t&);
// calls partition to sort the array.
void quick_sort(int*, int, int, size_t&);
// recursive merging.
void merge(int*, int, int, int, size_t&);
// calls merge to sort the array.
void merge_sort(int*, int, int, size_t&);
// generate an array.
// 0 = random
// 1 = descending
// 2 = ascending
// true = duplicates
// false = no duppies
int* generate_array(int, bool, int);

int main () {
    Timer timer;
    int *arr;
    int n = 100, trials = 1;
    for (int i = 0; i < 6; i++) {
        std::cout << "===== Quick Sort =====\n";
        std::cout << "Array size: " << n << "\n";
        std::cout << "Duppies: " << (i % 2 == 0) << "\n";
        if (i % 3 == 0) {
            std::cout << "Order: random.\n";
        }
        else if (i % 3 == 1) {
            std::cout << "Order: backwards.\n";
        }
        else {
            std::cout << "Order: pre-sorted.\n";
        }
        size_t comps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        quick_sort(arr, 0, (n - 1), comps);
        timer.end_timer();
        timer.display_time();
        std::cout << "# of comparisons: " << comps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
        if (i == 5) {
            n *= 10;
            i = 0;
        }
        if (trials == 4) {
            break;
        }
    }

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
int partition  (int* arr, int start, int end, size_t& comp) {
    int piv = arr[end];
    int loc = (start - 1);
    for (int j = start; j <= end - 1; j++) {

        comp++; // compison count
        if (arr[j] < piv) {
            loc++;
            swap(arr[loc], arr[j]);
        }
    }
    swap(arr[loc + 1], arr[end]); // insert pivot.
    return (loc + 1);
}
void quick_sort(int* arr, int start, int end, size_t& comp) {
    if (start < end) {
        // getting location for pivot.
        int piv = partition(arr, start, end, comp);

        // sort before and after the partition.
        quick_sort(arr, start, piv - 1, comp);
        quick_sort(arr, piv + 1, end, comp);
    }
}
void merge(int *arr, int leftmost, int mid, int rightmost, size_t& comp) {
    // size of leftmost and right sub-arrays
    int sub1 = mid - leftmost + 1;
    int sub2 = rightmost - mid;
    int i, j, k;
    // create the subarrays.
    int *subArr1 = new int[sub1], 
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
void merge_sort(int *array, int start, int end, size_t& comp) {
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
