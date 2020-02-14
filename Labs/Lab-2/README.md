# COSC320: Lab - 2 [Dr. Anderson]

Justin Ventura (README FILE)

## Questions to answer.


### A) What is the theoretical time complexity of your sorting algorithms (best and worst case), in terms of the array size?


1) Quick Sort: best case complexity is O(nlogn), worst case complexity is O(n^2) with n being the size of the array.  I believe the further away the pivot is from the middle of the array, the worst the complexity becomes.  So, the best case is when the pivot divides the array in half (when the array is in a more random order).  The worst case occurs when the array is already say in order, or in reverse order.


2) Merge Sort: best and worst case complexity is O(nlogn) where n is the size of the array.  This is because regardless of the order and size of said array, merge sort will always divide the array in half all the way down til each sub array reaches size 1. Looking at the table and graph provided, the growth remains to be steady at O(nlogn) for each size and order of the array.


### B) How does the absolute timing scale with the number of elements in the array? The size of the elements? Can you use the data collected to rectify this with the theoretical time complexity?


The timing scales just about right with the theoretical time complexities with respect to the number of elements.  With the data collected, it appears that the best and worst cases of quicksort began to show as the arrays became large.  Merge sort on the other hand, remained quite fast throughout the testing, growing just about O(nlogn).  I would say with the data collected, these sorts were quite close in growth with respect to the # of elements in the array to the time complexities.  (Note the graph linked to my data collected for various cases that will be attached to observe the trends in timing, and the table includes actual numbers with comparisons)  So overall, according to the data included, the data seems to match up with the theoretical time complexities.


### C) How do the algorithms perform in different cases? What is the best and worst case, according to your own test results?


As already mentioned, quick sort performed the worst when the array was already sorted or in reverse order, and performed best when the array was in a random order.  As for merge sort, regardless of the order, the times were roughly the same (per a specific n), as expected.  It did seem to slightly favor ascending arrays as far as absolute timing goes, but the asymptotic growth remained steady as per the graphed data.


### D) Do your observations confirm the difference in the best and worst case for Quicksort? How does Mergesort handle these cases?


Oh lord yes they do, the pre-sorted and backwards arrays were vastly worse during the quicksort trials than any other case.  The duplicates made it even worse (at least from the data I collected).  Merge sort barely seemed to be affected by the cases that made quicksort tremble.  (Again, observe the graph & table to see the evidence via empirical data)


### E) How do this algorithms compare to your implementation of Bubble sort from Lab 1?


They make bubble sort look like a joke.  However, quick sort was embarassing with it's worst cases, almost reminded me of the stupid sorts.  Merge sort in all cases and Quick Sort best cases demolished every sort from Lab1 by far.


### F) How could the code be improved in terms of usability, efficiency, and robustness?


I did some searching online and apparently choosing a random pivot for quicksort would make it's timing a little bit better.  I've been working on trying to implement that myself, but it won't be done in time for when this lab is due.
