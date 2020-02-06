// Justin Ventura COSC320
// Lab-2 Dr. Joe Anderson

#include <iostream>

// swap two integers by reference.
void swap (int&, int&);
// chooses pivot position in the array.
int partition (int*, int, int);
// calls partition to sort the array.
void quickSort(int*, int, int);
// recursive merging.
void merge(int*, int, int, int);
// calls merge to sort the array.
void merge_sort(int*, int, int);

int main () {

    return 0;
}

void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition (int* arr, int start, int end) {
    int piv = arr[end];
    int loc = (end - 1);
    for (int j = start; j <= end - 1; j++) {

        if (arr[j] < piv) {
            loc++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]); // insert pivot.
    return (i + 1);
}
void quickSort(int* arr, int start, int end) {
    if (start < end)
    {
        // getting location for pivot.
        int piv = partition(arr, start, end);

        // sort before and after the partition.
        quickSort(arr, start, piv);
        quickSort(arr, piv + 1, end);
    }
}
void merge(int *arr, int leftmost, int mid, int rightmost) {
    // size of left and right sub-arrays
    int sub1 = mid - leftmost + 1;
    int sub2 = rightmost - mid;
    in i, j, k;
    // create the subarrays.
    int subArr1[sub1], subArr2[sub2];

    // fill left and right sub-arrays
    for(i = 0; i < sub1; i++)
        subArr1[i] = array[left + i];

    for(j = 0; j < sub2; j++)
        subArr2[j] = array[mid + 1 + j];

    i = 0; j = 0; k = left;
    // merge temp arrays to real array
    while(i < sub1 && j < sub2) {
        if(subArr1[i] <= subArr2[j]) {
            array[k] = subArr1[i];
            i++;
        }
        else {
            array[k] = subArr2[j];
            j++;
        }
        k++;
    }
    while(i < sub1) { // extra element in left array
        array[k] = subArr1[i];
        i++;
        k++;
    }
    while(j < sub2) { // extra element in right array
        array[k] = subArr2[j];
        j++;
        k++;
    }
}
void merge_sort(int *array, int start, int end) {
   int mid;
   if(start < end)
   {
      mid = start + (end - start) / 2;
      // Sort first and second arrays recursively.
      merge_sort(array, start, mid);
      merge_sort(array, mid + 1, end);
      // merge the two arrays together.
      merge(array, start, mid, end);
   }
}
