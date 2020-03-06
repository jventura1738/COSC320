// Justin Ventura COSC320
// Dr. Anderson Lab-6: main.cpp
#include <iostream>
#include "heap.h"
#include "heapq.h"
#include "timer.h"
#include "jspace.h"
#include <time.h>
#include <random>
#include <chrono>

// For terminal colors and affects.
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define MAGENTA "\033[35m"      /* Magenta */
#define WHITE   "\033[37m"      /* White */
#define BLACK   "\033[30m"      /* Black */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define CYAN    "\033[36m"      /* Cyan */
#define BOLDON  "\e[1m"
#define BOLDOFF "\e[0m"

int partition (int * arr, int start, int end) {
    int piv = arr[end];
    int loc = (start - 1);
    for (int j = start; j <= end - 1; j++) {

        if (arr[j] < piv) {
            loc++;
            jspace::swap(&arr[loc], &arr[j]);
        }
    }
    jspace::swap(&arr[loc + 1], &arr[end]); // insert pivot.
    return (loc + 1);
}
void rand_quick_sort(int * arr, int start, int end) {
    if (start < end) {
        // getting location for pivot.
        int random = (start + (rand() % (end - start)));
        jspace::swap(&arr[random], &arr[end]);
        int piv = partition(arr, start, end);

        // sort before and after the partition.
        rand_quick_sort(arr, start, piv - 1);
        rand_quick_sort(arr, piv + 1, end);
    }
}
void quick_sort(int * arr, int start, int end) {
    if (start < end) {
        // getting location for pivot.
        int piv = partition(arr, start, end);

        // sort before and after the partition.
        quick_sort(arr, start, piv - 1);
        quick_sort(arr, piv + 1, end);
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
      merge_sort(array, start, mid);
      merge_sort(array, mid + 1, end);

      // merge the two arrays together.
      merge(array, start, mid, end);
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

        jspace::swap(&A->arr[i], &A->arr[max]);
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
        jspace::swap(&A->arr[0], &A->arr[A->heap_size]);
        A->heap_size -= 1;
        // We moved one of the smaller elements to the root, so we have to clean up
        MaxHeapify(A, 0);

    }

}

template <typename T>
void shuffle(T * arr, int length) {
    
    // create the bound for random keys, and set up priority queue.
    int bound = pow(length, 3);
    HeapQ<T> pqueue(length);

    // assign the random keys to each value in the array.
    for (int i = 0; i < length; i++) {

        pqueue.enqueue(arr[i], (rand() % bound) + 1);

    }

    // randomly select the elements by priority.
    for (int i = 0; i < length; i++) {

        arr[i] = pqueue.dequeue();

    }

}

template <typename T>
void random_swaps(T * arr, int length) {

    // indices to be made random.
    int j, k;

    for (int i = 0; i < length; i++) {

        j = (rand() % length);
        k = (rand() % length);
        jspace::swap(&arr[j], &arr[k]);

    }

}

template <typename T>
size_t hire_assistant(T * pool, size_t poolsize) {

    // count total rehires.
    size_t hires = 1;
    T curr = pool[0];

    for (int i = 1; i < poolsize; i++) {

        // if this candidate is better than our
        // current assistant, replace our curr
        // with this candidate.
        if (pool[i] > curr) {

            curr = pool[i];
            hires++;

        }

    }

    return hires;

}

int main () {

    // Random
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    // use these to run trials.
    int cap = 10;
    bool hiring = true;
    int candidates = 1000;
    int hires1, hires2;
    int * group1, * group2;
    float group1avg = 0, group2avg = 0;
    float totalavg;

    while(hiring) {

        std::cout << YELLOW << "==========================================================\n"                        << RESET;
        std::cout << YELLOW << "10 Interviews for " << BOLDON << candidates << BOLDOFF << YELLOW << " applicants.\n" << RESET;
        std::cout << YELLOW << "Total number of replacement hires per interview session:   \n"                       << RESET;
        std::cout << YELLOW << "==========================================================\n\n"                      << RESET;

        for (int session = 1; session <= 20; session++) {

            // Shuffle the two different groups sent from company.
            group1 = jspace::generate_array(candidates);
            group2 = jspace::generate_array(candidates);
            shuffle(group1, candidates);
            random_swaps(group2, candidates);

            // Perform interviews and count number of hires.
            hires1 = hire_assistant(group1, candidates);
            hires2 = hire_assistant(group2, candidates);

            // Calculate the average of each group.
            group1avg += hires1;
            group2avg += hires2;

            // After interviewing, display number of hires.
            std::cout << CYAN  << "Pool " << session << ", group 1 hires: " << BOLDON << hires1 << BOLDOFF << RESET << "\n";
            std::cout << GREEN << "Pool " << session << ", group 2 hires: " << BOLDON << hires2 << BOLDOFF << RESET << "\n";

            // Discard current groups for the next.
            delete [] group1;
            delete [] group2;

        }

        // Finish calculating the average.
        std::cout << "\n";
        group1avg /= cap;
        group2avg /= cap;
        totalavg   = (group1avg + group2avg) / 2.0;

        // Report the average hires.
        std::cout << CYAN   << "Group 1 average hires: " << BOLDON << group1avg << BOLDOFF << RESET << "\n";
        std::cout << GREEN  << "Group 2 average hires: " << BOLDON << group2avg << BOLDOFF << RESET << "\n";
        std::cout << YELLOW << "Total average hires:   " << BOLDON << totalavg  << BOLDOFF << RESET << "\n";

        candidates += 1000;
        if (candidates == 10000) {

            hiring = false;

        }
        
        std::cout << "\n";

    }

    std::cout << YELLOW << "=======================================\n";
    std::cout << YELLOW << "SORT COMPARISONS: QS, RQS, MERGE, HEAP:\n";
    std::cout << YELLOW << "=======================================\n";
    std::cout << RESET;
    int trials = 10;
    Timer timer;
    int index = 0;
    double * qs_avg = new double[9];
    double * rqs_avg = new double[9];
    double * mrg_avg = new double[9];
    double * heap_avg = new double[9];

    for (int size = 50000; size <= 1000000; size += 50000) {

        qs_avg[index] = 0;
        rqs_avg[index] = 0;
        mrg_avg[index] = 0;
        heap_avg[index] = 0;

        for (int k = 1; k <= trials; k++) {

            int * arr_qs = jspace::generate_array(size);
            shuffle(arr_qs, size);
            int * arr_rqs = jspace::copy(arr_qs, size);
            int * arr_mrg = jspace::copy(arr_qs, size);
            int * arr_heap = jspace::copy(arr_qs, size);

            Heap<int> heap(arr_heap, size);

            timer.start_timer();
            quick_sort(arr_qs, 0, size - 1);
            timer.end_timer();
            qs_avg[index] += timer.get_time();
            timer.reset_time();
            if (!jspace::isSorted(arr_qs, size)) throw std::string("FIX YOUR SH*T\n");

            timer.start_timer();
            rand_quick_sort(arr_rqs, 0, size - 1);
            timer.end_timer();
            rqs_avg[index] += timer.get_time();
            timer.reset_time();
            if (!jspace::isSorted(arr_rqs, size)) throw std::string("FIX YOUR SH*T\n");

            timer.start_timer();
            merge_sort(arr_mrg, 0, size - 1);
            timer.end_timer();
            mrg_avg[index] += timer.get_time();
            timer.reset_time();
            if (!jspace::isSorted(arr_mrg, size)) throw std::string("FIX YOUR SH*T\n");

            timer.start_timer();
            HeapSort(&heap);
            timer.end_timer();
            heap_avg[index] += timer.get_time();
            timer.reset_time();
            if (!jspace::isSorted(heap.arr, size)) throw std::string("FIX YOUR SH*T\n");

            delete [] arr_qs;
            delete [] arr_rqs;
            delete [] arr_mrg;

        }

        qs_avg[index]   /= trials;
        rqs_avg[index]  /= trials;
        mrg_avg[index]  /= trials;
        heap_avg[index] /= trials;
        index++;

    }

    int n = 50000;

    for (int i = 0; i < 9; i++) {

        std::cout << CYAN << "Average time for QuickSort on " << n << " elements: ";
        std::cout << BOLDON << qs_avg[i] << "ms.\n" << BOLDOFF << RESET;

        std::cout << GREEN << "Average time for Randomized QuickSort on " << n << " elements: ";
        std::cout << BOLDON << rqs_avg[i] << "ms.\n" << BOLDOFF << RESET;

        std::cout << BLUE << "Average time for MergeSort on " << n << " elements: ";
        std::cout << BOLDON << mrg_avg[i] << "ms.\n" << BOLDOFF << RESET;

        std::cout << MAGENTA << "Average time for HeapSort on " << n << " elements: ";
        std::cout << BOLDON << heap_avg[i] << "ms.\n" << BOLDOFF << RESET;

        std::cout << YELLOW << "============================================\n" << RESET;

    }

    return 0;

}