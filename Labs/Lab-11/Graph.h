// Justin Ventura COSC320
// Lab-11: Graph.h

#ifndef GRAPH_H
#define GRAPH_H

// Use these for various things.
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <map>

enum GRAPH_TYPE {UNDIRECTED = 0, DIRECTED};

// Graph Class (Undirected)
template <class T>
class Graph {
private:

	// The map from an integer (a specific vertex's value) to the
	// said vertex's neighbors values.
	std::map<int, std::vector<int>> vertices;

	// The underlying vector to the keys in the map from 0 - n
	// respectively to the vertices map where n = # of nodes.
	std::vector<T> vertices_alias;

	// Keeps track of what type of graph this is.
	GRAPH_TYPE g_type;

	// Keeps track of the timing for DFS.
	int time;

	/*
	 * =========================================================
	 * 
	 * PRIVATE METHODS TO BE CALLED FROM PUBLICS.
	 *
	 * _addEdge()  -> Helper for addEdge: returns whether the
	 * edge can be added or not (true if edge not found.)
	 *
	 * _idxOf(val) -> Gets the index of val.
	 * 
	 * _isDAG() -> determines whether or not this graph is a DAG.
	 *
	 * =========================================================
	*/

	// Helper for addEdge().  Returns false if an edge exists
	// between v1 & v2 already, true otherwise.
	bool _addEdge(const T & v1, const T & v2) const;

	// Returns the index of the given value.
	int _idxOf(const T & val);

	bool _isDAG() const { return true; }

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

	// Default Constructor for the Graph class. Graph will be
	// an undirected graph by default.
	Graph();

	// Main Constructor. Pass enum for graph type.
	Graph(const GRAPH_TYPE & type);

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
	// If the vertex is already in the graph, throws std::string.
	void addVertex(const T & vtx_val);

	// Add an edge between the two vertices with values v1 & v2.
	// Directed version: from v1 to v2.
	// If either vertices are not found, throws an std::string.
	// Also throws an std::string for multiple self-loops.
	// Also throws an std::string for duplicate edges.
	void addEdge(const T & v1, const T & v2);

	// Add an edge between the two vertices with values v1 & v2.
	// If either vertices are not found, creates them.
	void forceAddEdge(const T & v1, const T & v2);

	// Print the graph in an adjacency list form.
	// Throws and std::string if the graph is empty.
	void printGraph(const bool & best_format) const;

	// Print the graph by vertices in BFS order.
	// Throws and std::string if the graph is empty.
	void printBFS(const T & root_vtx);

	// Returns what type of graph this is.
	GRAPH_TYPE getType() const;

	// Returns true for an empty graph, false otherwise.
	bool empty() const;

	// Returns true if this graph is Directed & Acyclic.
	bool isDAG() const;

};

#include "Graph.cpp"

#endif
// End of Graph.h