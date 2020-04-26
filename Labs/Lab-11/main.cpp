// Justin Ventura Lab-11
// COSC320 with Dr. Joe Anderson

// My graph class.
#include "Graph.h"

int main() {
	
	// TESTING BEGINS HERE
	Graph<int> g1;

	/*
	 * Graph g1 (let * denote self loop)
	 * 1 - 2 - 3
	 * |   | / |
	 * 4   5 - 6*
	 *
	*/

	std::cout << "                  - GRAPH G1 -               \n\n";
	std::cout << "                   1 - 2 - 3                 \n";
	std::cout << "                   |   | / |                 \n";
	std::cout << "                   4   5 - 6*                \n";
	std::cout << "\n            (* denotes self loop)          \n";
	std::cout << "\n===========================================\n";

	// Create the graph.
	g1.addVertex(1);
	g1.addVertex(2);
	g1.addVertex(3);
	g1.addVertex(4);
	g1.addVertex(5);
	g1.addVertex(6);
	g1.addEdge(1, 2);
	g1.addEdge(1, 4);
	g1.addEdge(3, 2);
	g1.addEdge(3, 5);
	g1.addEdge(3, 6);
	g1.addEdge(5, 2);
	g1.addEdge(5, 6);
	g1.addEdge(6, 6);
	
	g1.printGraph(true);

	std::cout << "\nPrinting G1 BFS...\n";
	g1.printBFS(1);

	Graph<int> g2;

	std::cout << "\n===========================================\n";
	std::cout << "                  - GRAPH G2 -               \n\n";
	std::cout << "                 1 - 2 - 3 - 4               \n";
	std::cout << "                 |   | /   /                 \n";
	std::cout << "                 5   6 - 7                   \n";
	std::cout << "\n===========================================\n";

	// Create the graph.
	g2.addVertex(1);
	g2.addVertex(2);
	g2.addVertex(3);
	g2.addVertex(4);
	g2.addVertex(5);
	g2.addVertex(6);
	g2.addVertex(7);
	g2.addEdge(1, 5);
	g2.addEdge(1, 2);
	g2.addEdge(2, 2);
	g2.addEdge(2, 6);
	g2.addEdge(3, 6);
	g2.addEdge(3, 4);
	g2.addEdge(4, 7);
	g2.addEdge(6, 7);

	g2.printGraph(true);

	std::cout << "\nPrinting G2 BFS...\n";
	g2.printBFS(1);

	return 0;

}

// End of main.cpp