// Justin Ventura
// QuickSort

#include <iostream>

void swap (int&, int&);
int partition (int*, int, int);
void quickSort(int*, int, int);

int main () {

    return 0;
}

void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition (int* arr, int high, int low) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
