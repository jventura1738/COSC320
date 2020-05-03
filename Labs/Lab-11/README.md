# COSC320 Lab-11 [Graphs]

by Justin Ventura for Dr. Anderson

## Questions to Answer:

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed.

This was once again a very interesting lab.  The algorithms were followed as demonstrated in lecture, and I have a ton of output which you can use to check for correctness.  There are two .txt files, but you may use your own but must follow this format:

- must all be positive integers for the sake of clean file handling.
- line 1: 0 for undirected, 1 for directed.
- next line: each node in whatever order you want the node added.
- a line with a '-' to mark the end of the nodes. (do not include the quotes)
- each line after will correspond to each node and end with a -1 to mark the end of said node's neighbors.
- sample below:

0

1 2 3 4

'-'

2 3 -1

4 -1

2 4 -1

1 -1

Next, there is the extra credit.  You can check the code and outputs to show that the templated graph works as intended for 20pts.

### B) What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the graph? Be sure to vary the parameters enough to use the observations to answer the next questions!

- Depth First Search complexity: O(|V| + |E|) where V denotes the set of nodes and E denotes the set of edges.  The best case occurs with a smaller |E|, while the worst case occurs with a larger |E|.
- Topological Sort complexity: O(|V| + |E|) where V denotes the set of nodes and E denotes the set of edges.  This is the same as DFS since it is very similar, however you could say the complexity is O(|V| + |E| + |V|log|V|) since the algorithm sorts the nodes before reversing them after gathering finish times.
- Strongly Connected Components Algorithm complexity: once again: O(|V| + |E|) since it uses a variation of DFS.  But further more we could once again say O(|V| + |E| + |V|log|V|) since, just like the previous algorithm, we sort and reverse the finish times map (converted to list).

### C) How could the code be improved in terms of usability, efficiency, and robustness?

Most of the code is pretty good, I am not sure how it could be improved so far.  However, I did originally template my class in a very inefficient way, but I did fix it to make things more memory efficient.
