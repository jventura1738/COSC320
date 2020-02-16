# COSC320 Lab-3 for Dr. Joe Anderson

by Justin Ventura

## Questions to Answer:

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed.

To summarize: I first made a heap structure that used an array to hold the data, then in lecture we talked about how the indexing for the heaps left and right child nodes: 2i & 2i+1 respectively.  Onces the heaps were fully operational, I worked on creating the MaxHeapify(A) function which would be called multiple times in the next function: BuildMaxHeap(A).  In order to get the MaxHeapify to work, I had to do numerous tests on the indexing due to seg faulting.  This was caused by errors in my heap_size.  After I fixed that, I was able to apply BuildMaxHeap(A) and MaxHeapify(A) to sort the array.


### B) What is the theoretical time complexity of your sorting algorithm (best and worst case), in terms of the array size?

Letting n be the size of the given array; Best and Worst case: O(nlogn).  Heap sort calls both BuildMaxHeap and MaxHeapify with complexities O(nlogn) and O(logn) respectively.  As demonstrated in lecture, BuildMaxHeap boils down to be O(n) with a more detailed analyzation.  Heap Sort will call MaxHeapify roughly (n-1) times where n is the size of the array.  So with this in mind we can safely say that HeapSort(A) is O(nlogn).

### C) Test your sorting algorithm on different size and types of arrays, as you did with labs 1 and 2. Be sure to vary the parameters enough to use the observations to answer the next questions!

I tested with large arrays, small arrays, duplicates, no duplicates, random order, descending order, ascending order, template types, etc.

### D) How does the absolute timing scale with the number of elements in the array? The size of the elements? Use the data collected to rectify this with the theoretical time complexity, e.g. what non-asymptotic function of n mostly closely matches the timings that you observe as n grows?

The absolute timing scales pretty well with the # of elements in the array (call it 'n').  I did however notice that the growth seems slightly more linear than nlogn in my datasets & analysis.  //TODO: test time of doubles.  As n grows, it closely matched nlogn best, as it was more of a linear growth, but still not exactly linear.

### E) Aggregate your data into a graph of the complexity for the various array sizes, for example with a spreadsheet program like LibreOffice Calc or Microsoft Word.

Graphs & Tables are included in the Lab Report and uploaded to this folder.

### F) How does the sort perform in different cases? What is the best and worst case, according to your own test results?

The sort was definitely very quick for nearly every case, but it definitely seemed that randomly arranged arrays were in the subset of worse cases.  Ascending and Descending orders barely differed from each other, but definitely performed better than the randomly shuffled arrays.  Although I have little evidence to confirm this, it appeared that occasionally the arrays with less duplicates performed worse.  This was true for many cases but not all, so I cannot make any conclustions on this observation.

### G) How could the code be improved in terms of usability, efficiency, and robustness?

Good question, I dont think there is.
