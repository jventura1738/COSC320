#include "heapq.h"
#include "jspace.h"
#include <iostream>

int main() {

    int qsize = 16;
    HeapQ<int> pqueue(qsize);

    for (int i = 0; i < 14; i++) {

        pqueue.enqueue(i, i);

    }
    pqueue.print_queue(0, 5);
    pqueue.enqueue(55, 1);
    std::cout << "current heap size: " << pqueue.heap_size << "\n";
    std::cout << "current length: " << pqueue.length << "\n";
    pqueue.print_queue(0, 5);
    pqueue.enqueue(66, 1);
    std::cout << "current heap size: " << pqueue.heap_size << "\n";
    std::cout << "current length: " << pqueue.length << "\n";
    pqueue.print_queue(0, 5);
    pqueue.enqueue(77, 77);
    std::cout << "current heap size: " << pqueue.heap_size << "\n";
    std::cout << "current length: " << pqueue.length << "\n";

    pqueue.print_queue(0, 5);

    return 0;
}