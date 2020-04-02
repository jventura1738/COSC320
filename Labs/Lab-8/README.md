# COSC320 Lab-8

by Justin Ventura

Dr. Joe Anderson

## Questions to answer:

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed.

Well a lot of the material was review, however I did make a lot of improvement over my old COSC220 tree work.  I was able to make the code work as intended and demonstrated this in the main.

### B) What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree? Be sure to vary the parameters enough to use the observations to answer the next questions!

- Insert Worst-Case: O(n) where n is the # of nodes.  This is because if you were to insert n elements in descending order, you would have a left skew (right if in ascending order) with O(n). Insert Best-Case: O(logn) where n is # nodes because at best, you would have to traverse the tree logn times considering this is a binary tree, where at best the height of the tree is logn.

- Delete Best, Worst-Case: O(logn), O(n) where n is #nodes in tree for the same reasons as mentioned above.  These two functions are quite similar.

- Search Best, Worst-Case: O(logn), O(n) for the same reasons above.  Once again, at best you would search log2(n) where n is # of nodes in the tree.  At worst, you would traverse to the end of, essentially, a linked list.

### C) Use timing tools to study the cost of each of the data structure algorithms. For example, time how long it takes to insert, find, delete 1000, 2000, 3000, etc. elements and calculate the time per operation. Look for how the time scales with the size of the tree. Does the data align with the theoretical guarantees?

Yes these match.  The most notable timings were the fully skewed trees (linked lists) with linear growth.

### D) How could the code be improved in terms of usability, efficiency, and robustness?

Three words: Red Black Trees. :)
