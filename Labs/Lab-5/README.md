# COSC320 Lab-5 [Joe Anderson]

by Justin Ventura

## Questions to answer:

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed.

I modified my max heap to essentially act like a priority queue in the sense that the max of the heap is the item with highest priority.  Then I tested it to make sure it acts as intended.

### B) What is the theoretical time complexity of your algorithms (best and worst case), in terms of the input size? Be sure to vary the parameters enough to use the observations to answer the next questions!

### C) How does the absolute timing of different algorithms scale with the input? Use the data collected to rectify this with the theoretical time complexity, e.g. what non-asymptotic function of n mostly closely matches the timings that you observe as n grows?

### D) Describe 2-3 different larger application areas where a priority queue would be helpful. Explain and give some justification why it would be a better choice than other data structures.

1) The first application could be an application/program that involves some sort of bid-ask system (for example, StockX).  The reason this could be better than other data structures is because for a seller, the highest bid deserves the highest priority, and for a buyer the lowest ask would be in their highest priority.  With these priorities in mind, the program could keep track of two different queues: buyers and sellers.  This way buyers and sellers can be presented with their respective priorities through some sort of interface.  For example, when the highest bidder's bid is matched to the lowest ask of a seller (this assumes everyone would act in the most efficient manner; a seller would not pick a bid lower than the highest bid and a buyer would not pick an ask above the lowest ask, etc), then both queues would "dequeue," and the next highest bid & lowest ask will become the new highest priorities.  If there is a new highest bid, then it would become the highest priority, and same applies for lowest ask. This would be the ideal data structure for this application since keeping track of a defined highest priority is what it does best.


2) Another application could be a queue of tasks which need to be done, but there would be some tasks involved that are more important than others.  The priority queue would be advantageuous over other data structures since this task queue would not necessarily be pre-determined; random tasks may be assigned at random times.  For example we could have the following scenario:  Quack N. Bush is in charge of managing the computer lab at a unviersity.  People can report issues, file maintenence requests, and other things as well.  Since there is only one Quack N. Bush, the reports may add up in a queue.  This is where the priority comes in, some tasks could be less impactful on productivity or just be less severe than another problem.  For example, suppose Quack is working on reloading a printer's paper tray.  Then three reports pop-up on his task-list: monthly keyboard inspection, a student needs a password reset for their linux account, or three dumb sophomores in the lab attempted to 'sudo install cmatrix' but were denied with the message 'jventura3 is not in the sudoers file.  This incident will be reported.'  Obviously, the keyboard inspection and stupidity of the three sophomores would be of lower priority than the freshman needing a linux password.  This is just one example but there could be many more tasks that would involve some sort of priority depending on the severity of the report.

### E) How could the code be improved in terms of usability, efficiency, and robustness?

The interface for my priority queue is not the best.
