#include "heapq.h"
#include <iostream>

int main() {

    int qsize = 16;
    HeapQ<int> pqueue(qsize);

    for (int i = 0; i < 14; i++) {

        pqueue.enqueue(i, 1);

    }

    pqueue.enqueue(55, 2);
    pqueue.enqueue(66, 2);

    pqueue.print_queue(0, 4);

    return 0;
}