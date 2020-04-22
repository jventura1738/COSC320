// Justin Ventura Lab-10
// COSC320 with Dr. Joe Anderson

// My graph class.
#include "Graph.h"

int main() {
	
	// TESTING BEGINS HERE
	Graph<int> g1;

	/*
	 * Graph g1 (let * denote self loop)
	 * 1 - 2 - 3
	 * | \ |   |
	 * 4   5 - 6*
	 *
	*/

	g1.addVertex(1);
	g1.addVertex(2);
	g1.addVertex(3);
	g1.addVertex(4);
	g1.addVertex(5);
	g1.addVertex(6);
	g1.addEdge(1, 2);
	g1.addEdge(1, 4);
	g1.addEdge(1, 5);
	g1.addEdge(3, 2);
	g1.addEdge(3, 6);
	g1.addEdge(5, 2);
	g1.addEdge(5, 6);
	g1.addEdge(6, 6);
	

	g1.printGraph(true);

	return 0;
}