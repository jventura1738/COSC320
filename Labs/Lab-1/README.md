# COSC320-002: Lab 1 [Dr. Joe Anderson]
Justin Ventura
(who's joe?)

## Questions to Answer.

### (a) What is the theoretical time complexity of your sorting algorithms (best and worst case), in terms of the array size?
Let the size of the array be n. 

i) Bubble Sort: [best case] O(n), [worst case], O(n^2)

ii) Selection Sort: [best case] O(n^2), [worst case], O(n^2)

iii) Insertion Sort: [best case] O(n), [worst case], O(n^2)

### (b) How does the absolute timing scale with the number of elements in the array? The size of the elements? Can you use the data collected to rectify this with the theoretical time complexity?

The actual timing clearly gets longer as the array size increases.  In terms of timing, the growth of time cost with respect to the number of elements in the array grows at the rate given in the time complexities.  For example, let n be the size of an array: as n goes from 100 to 100000, bubble sort's performance decreases at a polynomial rate (specifically n^2).  The data supports this, therefore the theoretical time complexities and actual empirical results are consistent.

### (c) Aggregate your data into a graph of the complexity for the various array sizes, for example with a spreadsheet program like LibreOffice Calc or Microsoft Word.

Data collected and documented on Google Sheets.

### (d) How do the algorithms perform in different cases? What is the best and worst case, according to your own test results?

i) Bubble sort obviously performs at its best when an array is presorted.  

### (e) How could the code be improved in terms of usability, efficiency, and robustness?
