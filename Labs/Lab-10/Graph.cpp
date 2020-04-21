// Justin Ventura COSC320
// Lab-10: Graph.cpp

#include "Graph.h"

/*
 * =========================================================
 *
 * (DE)CONSTRUCTORS FOR MEMORY MANAGEMENT
 *
 * Default Constructor, Copy Constructor, Destructor,
 * Overloaded Assignment Operator.
 *
 * =========================================================
*/

// Default Constructor.
template <typename T>
Graph<T>::Graph() {

	std::cout << "Gamers\n";

}

// Copy Constructor.
template <typename T>
Graph<T>::Graph(const Graph<T> & old_graph) {

	std::cout << "Copyboi\n";

}

// Destructor.
template <typename T>
Graph<T>::~Graph() {

	std::cout << "Salute\n";

}

// Overloaded Assignment Operator.
template <typename T>
void Graph<T>::operator=(const Graph<T> & old_graph) {

	std::cout << "Copyboi 2\n";

}

/*
 * =========================================================
 *
 * MEMBER FUNCTIONS FOR THE GRAPH CLASS
 * 
 * Functions to: add a vertex to the graph,
 *               add an edge between two vertices,
 *               print the graph in adjacnecy list form,
 *               and print the graph vertices in BFS order.
 * 
 * =========================================================
*/ 

// Add a vertex to the graph with the integer value of vtx_val.
template <typename T>
void Graph<T>::addVertex(const T & vtx_val);

// Add an edge between the two vertices with values v1 & v2.
template <typename T>
void Graph<T>::addEdge(const T & v1, const T & v2);

// Print the graph in an adjacency list form.
template <typename T>
void Graph<T>::printGraph() const;

// Print the graph by vertices in BFS order.
template <typename T>
void Graph<T>::printBFS(const T & root_vtx) const;

// End of Graph.cpp