// Justin Ventura/Jacob Duncan COSC320
// Project 3 (Justin's Lab-11 modified)

#ifndef GRAPH_H
#define GRAPH_H

// Use these for various things.
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <map>
#include <stdio.h>

// Enumeration for the type of graph.
// UNDIRECTED: standard graph with no specific direction.
// DIRECTED: a graph where direction from vertices v1 to v2
// is not the same as vertices v2 to v1.
enum GRAPH_TYPE {UNDIRECTED = 0, DIRECTED};

// Graph Class.
template <class T>
class Graph {
private:
	// Knight location tracker variable.
	std::string knight_location;

public:

	// The map from an integer (a specific vertex's value) to the
	// said vertex's neighbors values.
	std::map<int, std::vector<int> > vertices;

	// The underlying vector to the keys in the map from 0 - n
	// respectively to the vertices map where n = # of nodes.
	std::vector<T> vertices_alias;

	// Returns the index of the given value.
	int _idxOf(const T & val);

private:

	// Keeps track of what type of graph this is.
	GRAPH_TYPE g_type;

	/*
	 * =========================================================
	 * 
	 * PRIVATE FUNCTION TO BE CALLED FROM PUBLICS.
	 *
	 * _addEdge()  -> Helper for addEdge: returns whether the
	 * edge can be added or not (true if edge not found.)
	 *
	 * =========================================================
	*/

	// Helper for addEdge().  Returns false if an edge exists
	// between v1 & v2 already, true otherwise.
	bool _addEdge(const int & v1, const int & v2);

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
	 *               & other knight related functions.
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

	// Print the graph in an adjacency list form.
	// Throws and std::string if the graph is empty.
	void adjList(const bool & best_format = true) const;

	// Functions to return what cell/index the knight is at.
	std::string getKnightCell() const;
	int getKnightIndex() const;

	// Set the knights location
	void setKnightLocation(const std::string & cell);

	// Returns true for an empty graph, false otherwise.
	bool empty() const;

};

#include "Graph.cpp"

#endif
// End of Graph.h
