#include "heapq.h"
#include "jspace.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <random>
#include <chrono>

// EXTRA CREDIT PRIORITY RANDOMIZATION FUNCTION
template <typename T>
void shuffle_arr(T * arr, int length);

// EXTRA CREDIT RANDOM SWAPS FUNCTION
template <typename T>
void random_swaps(T * arr, int length);

int main() {

    int qsize = 16;
    HeapQ<int> pqueue(qsize);

    std::cout << "=== Priorities match values === \n";
    std::cout << "Created a priority queue with 16 total spaces.\n";

    for (int i = 0; i < 14; i++) {

    	std::cout << "enqueuing...\n";
        pqueue.enqueue(i, i);
        pqueue.print_queue(0, 5);

    }

    pqueue.enqueue(14, 14);
    pqueue.print_queue(0, 5);
    pqueue.enqueue(15, 15);
    pqueue.print_queue(0, 5);
    std::cout << "This will call push back.\n";
    pqueue.enqueue(16, 16);
    pqueue.print_queue(0, 5);

    std::cout << "Adding value: 999 with priority 999.\n";
    pqueue.enqueue(999, 999);
    pqueue.print_queue(0, 5);

    std::cout << "\n=== STRING TEST ===\n";
    std::cout << "Priority queue by age test. \n\n";
    std::cout << "List of names with ages:\n";
    std::string names[] = {"Justin Ventura", "Jacob Duncan", "Joe Anderson", "Ian Thomas",
    "Gabriel Corinthian", "Michael Mandulak", "Blaine Mason", "Zak Holliman"};
    int ages[] = {20, 19, 29, 20, 19, 18, 19, 21};
    HeapQ<std::string> pq(qsize);
    qsize = 8;
    for (int i = 0; i < qsize; i++) {

        std::cout << names[i] << " age: " << ages[i] << "\n";
        pq.enqueue(names[i], ages[i]);

    }

    std::cout << "\nTest peek (should print 'Joe Anderson'):\n";
    std::cout << pq.peek() << "\n\n";
    std::cout << "Now the lists will be re-ordered by age priority:\n";

    jspace::sort(ages, qsize);
    jspace::reverse(ages, qsize);

    for (int i = 0; i < qsize; i++) {

        names[i] = pq.dequeue();

    }

    for (int i = 0; i < qsize; i++) {

        std::cout << names[i] << " age: " << ages[i] << "\n";

    }

    std::cout << "\n===== EXTRA CREDIT =====\n";
    int n = 10;
    int arr1[n];
    int arr2[n];
    for (int i = 0; i < n; i++) {

        arr1[i] = i;
        arr2[i] = i;

    }
    std::cout << "Initial array:\n";
    jspace::print(arr1, n);

    // randomized priority algorithm.
    shuffle_arr(arr1, n);
    // random swaps algorithm.
    random_swaps(arr2, n);

    std::cout << "\nResulting array from random priorities:\n";
    jspace::print(arr1, n);

    std::cout << "Resulting array from random swaps:\n";
    jspace::print(arr2, n);

    return 0;
}

template <typename T>
void shuffle_arr(T * arr, int length) {

    // set up the random seed.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    
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

    // set up the random seed.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);

    // indices to be made random.
    int j, k;

    for (int i = 0; i < length; i++) {

        j = (rand() % length);
        k = (rand() % length);
        jspace::swap(&arr[j], &arr[k]);

    }

}