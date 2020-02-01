// Justin Ventura COSC320
// Joe Anderson Lab 1

// My timer class from COSC220
#include "timer.h"
#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <algorithm>

void printarr(int*, int);
int swap(int&, int&);
bool isSorted(int*, int);
size_t bubbleSort(int*, int);
size_t selectionSort(int*, int);
size_t insertionSort(int*, int);
int* generate_array(int order, bool dup, int n);
size_t runsort (size_t (*sort)(int*, int), int* arr, int n);

int main() {
    Timer timer;
    int *arr;
    int n = 100;
    std::cout << "----- Bubble Sort (trash) -----\n";

    std::cout << "\nTRIAL ONE: 100 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL TWO: 1000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL THREE: 10000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL FOUR: 100000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n = 100;

    std::cout << "----- Selection Sort -----\n";
    std::cout << "\nTRIAL ONE: 100 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL TWO: 1000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL THREE: 10000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL FOUR: 100000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n = 100;

    std::cout << "----- Insertion Sort -----\n\n";
    std::cout << "\nTRIAL ONE: 100 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL TWO: 1000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL THREE: 10000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL FOUR: 100000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }
    n *= 10;
    std::cout << "\nTRIAL FIVE: 1000000 elements.\n";
    for (int i = 0; i < 6; i++) {
        size_t numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        std::cout << "# swaps: " << numswaps << "\n\n";
        if (!isSorted(arr, n)) std::cout << "L\n";
        delete [] arr;
    }

    return 0;
}

void printarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
int swap(int &a, int &b) {
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
size_t bubbleSort(int* arr, int n) {
    size_t count = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                count++;
                swapped = true;
            }
        }
    if (!swapped)
        break;
    }
    return count;
}
size_t selectionSort(int* arr, int n) {
    size_t count = 0;
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[min])
            min = j;
        count++;
        swap(arr[min], arr[i]);
    }
    return count;
}
size_t insertionSort(int* arr, int n) {
    size_t count = 0;
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= temp) {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return count;
}

// 0 = random
// 1 = descending
// 2 = ascending
// true = duplicates
// false = no duppies
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
        case 0:
            {
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
size_t runsort (size_t (*sort)(int*, int), int* arr, int n) {
    size_t numswaps = sort(arr, n);
    return numswaps;
}
