# COSC320 Lab-7

by Justin Ventura

for Dr. Joe Anderson

## Questions to Answer

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed.

The hashes were all made with a decent bit of analysis on how to make a fast hash with little chance of collisions.  Of course collisions will be inevitable for most cases, so I tried to reduce them as I went along.  The extra credit made use of the memcpy function to make a function which could hash any datatype!

### B) Explain your string conversion functions, and compare how they distribute the hashes of various strings. + explanation for 2C in the lab prompt.

My first string hashing function used a cool algorithm I came up with which I think distributes the hashes nicely (ran a bunch of tests with no collisions, but this test cannot make any concrete conclusions as the number of test cases is technically infinite, but as I made the hash more complex I noticed less and less collisions).  This simply summed the ASCII value of each string position, and then multiplied that by its POSITION in the string in order to make string order matter (abc, cba, bac all have different hashes, and while this may not necessarily always hold, it is my attempt at making the hashes slightly more unique).  I can almost guarantee no one else in the class thought of this... :)  The second string hash is a slight modification of the first.  Both of them work decently well in my experience, but there is definitely room for improvement.

Explanation to 2C in the prompt: The given hash function makes sense because it follows the mathematical/theoretical definition of a hash function.  It takes a set A (of values) with theoretically infinite size (limited by bits in this case), then performs a few complex operations (multiplication method in this case) on the values, in which the results are then mapped to a sub-set of A which is typically of finite size (why the modulo is used).

### C) How could the code be improved in terms of usability, efficiency, and robustness?

There are many ways this could be improved.  I am very new to hashing, so my hashes are most likely to be considered sub-par in comparison to many other hashes out there.  I tried my best to make them work decently well, but I'm sure with time I should be able to come up with better hash functions (project tsk tsk).
