#include "heapq.h"
#include "jspace.h"
#include <iostream>

int main() {

    int qsize = 16;
    HeapQ<int> pqueue(qsize);

    for (int i = 0; i < 14; i++) {

    		std::cout << "enqueuing...\n";
        pqueue.enqueue(i, i);
        pqueue.print_queue(0, 5);
        std::cout << "current heap size: " << pqueue.heap_size << "\n";

    }

    // pqueue.print_queue(0, 5);
    // std::cout << "current heap size: " << pqueue.heap_size << "\n";
    // std::cout << "current length: " << pqueue.length << "\n";
    // pqueue.enqueue(55, 1);
    // pqueue.print_queue(0, 5);
    // std::cout << "current heap size: " << pqueue.heap_size << "\n";
    // std::cout << "current length: " << pqueue.length << "\n";
    // pqueue.enqueue(66, 1);
    // pqueue.print_queue(0, 5);
    // std::cout << "current heap size: " << pqueue.heap_size << "\n";
    // std::cout << "current length: " << pqueue.length << "\n";
    // pqueue.enqueue(77, 77);
    // pqueue.print_queue(0, 5);
    // std::cout << "current heap size: " << pqueue.heap_size << "\n";
    // std::cout << "current length: " << pqueue.length << "\n";

    return 0;
}