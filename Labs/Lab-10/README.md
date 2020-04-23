# COSC320 Lab-10

by Justin Ventura for JTA @ SU.

## Questions to Answer

### A) Summarize your approach to the problem, and how your code addresses the abstractions needed.

This was by far my favorite lab.  Graph theory has always interested me since I took Discrete Mathematics.  In order to make the graph class, I simply used a map from type to vector<type>.  Then for the add vertex/edge function I modified the map in order to make it clear which vertices were connected (thus also resulting in an easy adjacency list derivation).  The Breadth First Search Algorithm was mostly followed from the algorithm on the prompt with modifications where needed.

### B) What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree? Be sure to vary the parameters enough to use the observations to answer the next questions!

- AddVertex(v): Adding the vertex itself to the map is constant O(1), but since I check for duplicates, this makes the worst case potentially the O(n) where n is the number of vertices in the map.  Summary: best->O(1), worst->O(n).
- AddEdge(v1, v2): If we ignore the extra testing added for assuming the user may violate the rules in place (vertices v1 & v2 must exist in the graph!), then we really have a best and worst case of O(1).
- BreadthFirstSearch(r): Completing this algorithm rooted at r, using an adjacency list, letting V = {vertices}, and E = {edges}, we will have a time complexity of O(|V| + |E|).  What this simply means is that depending on which is larger, |V| or |E|, that is what will dominate the complexity (best & worst case).  This makes sense because in the algorithm, the for loop will run as many times as there are nodes connected to u (current discovered node).  All of the 'white' nodes connected to u will be added to the queue which will then result in more for loop iterations.  Each connection the white nodes is an edge, and each of those nodes in a vertex.

### C) How could the code be improved in terms of usability, efficiency, and robustness?

I persononlly think that this code is pretty good.  I do enjoy graph theory and plan to use this to make a Graph Class with children classes for say 'simple graphs,' 'multigraphs,' etc. via inheritance & polymorphism.  This will be fun.
