#include "heapq.h"
#include "jspace.h"
#include <iostream>
#include <algorithm>

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
    int arr[n];
    for (int i = 0; i < n; i++) {

        std::cout << "gamers\n";

    }



    return 0;
}