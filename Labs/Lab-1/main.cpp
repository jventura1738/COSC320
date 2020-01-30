// Justin Ventura COSC320
// Joe Anderson Lab 1

// My timer class from COSC220
#include "timer.h"
#include <iostream>

int swap(int&, int&);
bool isSorted(int*, int&);
long bubbleSort(int*, int&);
long selectionSort(int*, int&);
long insertionSort(int*, int&);
int* generate_array(int order, bool dup);

// 1 = random
// 2 = descending
// 3 = ascending

// true = duplicates
// false = no duppies

int main() {

    return 0;
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
    }
    return true;
}
long bubbleSort(int* arr, int n) {
    long count = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; i++) {
            if (arr[j] > arr[j+1]) {
                count++;
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
long selectionSort(int* arr, int n) {
    long count = 0;
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[min])
            min = j;
        count++;
        swap(arr[min], arr[i]);
    }
}
long insertionSort(int* arr, int n) {
    long count = 0;
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
}
int* generate_array(int order, bool dup, int n) {
    int *arr = new int[n];
    if (dup) {
        int temp = 1;
        int temp2 = ((n % (n / 7)) - (3 * order + 1));
        for (int i = 0; i < n; i++) {
            arr[i] = temp;
            if (i % temp2 == 0) {
                temp++;
            }
        }
    }
}
