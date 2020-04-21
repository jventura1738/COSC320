// Justin Ventura COSC320
// Lab-10: Graph.h

#ifndef GRAPH_H
#define GRAPH_H

// Use these for various things.
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <map>

// Graph Class (Undirected)
template <class T>
class Graph {
private:

	// The map from an integer (a specific vertex's value) to the
	// said vertex's neighbors values.
	std::map<T, std::vector<T>> vertices;

public:

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

	// Default Constructor for the Graph class.
	Graph();

	// Copy Constructor for the Graph class.
	Graph(const Graph<T> & old_graph);

	// Destructor for the Graph class.
	~Graph();

	// Overloaded Assignment Operator for the Graph Class.
	void operator=(const Graph<T> & old_graph);

	/*
	 * =========================================================
	 *
	 * MEMBER FUNCTIONS FOR THE GRAPH CLASS
	 * 
	 * Functions to: add a vertex to the graph,
	 *               add an edge between two vertices,
	 *               print the graph in adjacency list form,
	 *               and print the graph vertices in BFS order.
	 * 
	 * =========================================================
	*/ 

	// Add a vertex to the graph with the integer value of vtx_val.
	void addVertex(const T & vtx_val);

	// Add an edge between the two vertices with values v1 & v2.
	void addEdge(const T & v1, const T & v2);

	// Print the graph in an adjacency list form.
	void printGraph() const;

	// Print the graph by vertices in BFS order.
	void printBFS(const T & root_vtx) const;

};

#include "Graph.cpp"

#endif