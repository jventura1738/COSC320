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
#include <set>

// Enumeration for coloring vertices in the BFS print function.
// White: default color for the vertex.
// Gray:  after we visit the vertex, but not yet its neighbors.
// Black: after we visit the vertex and its neighbors.
enum color_t { WHITE = 0, GRAY, BLACK };

// Enumeration for the type of graph.
// UNDIRECTED: standard graph with no specific direction.
// DIRECTED: a graph where direction from vertices v1 to v2
// is not the same as vertices v2 to v1.
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

	// Maps to keep track of each vertex's discovery and finish
	// time as calculated in DFS.
	std::map<int, int> disc_times;
	std::map<int, int> fin_times;

	// Keeps track of what type of graph this is.
	GRAPH_TYPE g_type;

	// Keeps track of the timing for DFS.
	int time;

	// Boolean for if the graph is Directed & Acyclic or not.
	bool isDAG;

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
	 * _DFSvisit() -> performs the DFS visit from DFS.
	 *
	 * =========================================================
	*/

	// Helper for addEdge().  Returns false if an edge exists
	// between v1 & v2 already, true otherwise.
	bool _addEdge(const int & v1, const int & v2);

	// Returns the index of the given value.
	int _idxOf(const T & val);

	// Helper for performing DFS visits.
	void _DFSvisit(int u, std::map<int, color_t> & color, std::map<int, int> & parent,
	const bool & print);

	// Modified DFS for the Strongly Connected Components Algorithm.
	void _SCCDFS(std::vector<std::pair<int, int>> & list);

	// Modified DFS visit for the Strongly Connected Components Algorithm.
	void _SCCvisit(int u, std::map<int, color_t> & color);

	// Private function which returns true if given subset of vertices
	// is a vertex cover, and false otherwise.
	bool _isVertexCover(std::set<int> & S) const;

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
	void adjList(const bool & best_format = true) const;

	// Print the graph by vertices in BFS order.
	// Throws and std::string if the graph is empty.
	void printBFS(const T & root_vtx);

	// Performs a DFS, boolean decides whether or not
	// the function should print.
	void DFS(const bool & print = false);

	// Perform a topological sort then report the ordering.
	void topSortPrint();

	// Performs the Strongly Connected Components Algorithm
	// and prints the SCC.
	void SCCprint();

	// Returns what type of graph this is.
	GRAPH_TYPE getType() const;

	// Returns true for an empty graph, false otherwise.
	bool empty() const;

	// Print Vertex Cover
	void printVertexCover();

	// Prints Vertex Cover with random edge choice.
	void randVertexCover();

	// Brute force minimum vertex cover.
	void minVertexCover() const;

};

#include "Graph.cpp"

#endif
// End of Graph.h