// Justin Ventura/Jacob Duncan COSC320
// Project 3 (Justin's Lab-11 modified)

#include "Graph.h"
#include <algorithm>

template <typename T>
int Graph<T>::_idxOf(const T & val) {

	// Empty graph.
	if (this->vertices_alias.empty()) return -1;

	// This is the index.
	int index = 0;

	// Iterate through the vector.
	auto j = vertices_alias.begin();
	while (*j != val) {

		// Increment the index & iterator.
		index++;
		j++;

		// If element is not in list, return -1.
		if (j == vertices_alias.end()) {

			return -1;

		}

	}

	return index;

}

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

	this->g_type = UNDIRECTED;
	this->time = 0;
	this->isDAG = false;

}

// Main Constructor.
template <typename T>
Graph<T>::Graph(const GRAPH_TYPE & type) {

	this->g_type = type;
	this->time = 0;
	this->isDAG = (type == DIRECTED) ? true : false;

}

// Copy Constructor.
template <typename T>
Graph<T>::Graph(const Graph<T> & old_graph) {

	this->g_type = old_graph.g_type;
	this->vertices = old_graph.vertices;
	this->vertices_alias = old_graph.vertices_alias;
	this->time = old_graph.time;
	this->isDAG = old_graph.isDAG;

}

// Destructor.
template <typename T>
Graph<T>::~Graph() {

	//std::cout << "Salute\n";

}

// Overloaded Assignment Operator.
template <typename T>
void Graph<T>::operator=(const Graph<T> & old_graph) {

	this->g_type = old_graph.g_type;
	this->vertices = old_graph.vertices;
	this->vertices_alias = old_graph.vertices_alias;
	this->time = old_graph.time;
	this->isDAG = old_graph.isDAG;

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
 *               & various others...
 * 
 * =========================================================
*/ 

// Add a vertex to the graph with the value of vtx_val.
template <typename T>
void Graph<T>::addVertex(const T & vtx_val) {

	// If it is not, add to the graph.
	if (_idxOf(vtx_val) == -1) {
		
		std::vector<int> n_list;
		this->vertices.insert({this->vertices.size(), n_list});
		this->vertices_alias.push_back(vtx_val);
		// std::cout << "Inserted: " << vtx_val << ".\n";

	}

	// Otherwise, throw an std::string error.
	else {

		throw std::string("ERROR [addVertex]: duplicate vertex.\n");

	}

}

// Helper for addEdge().  Returns false if an edge exists
// between v1 & v2 already, true otherwise.
template <typename T>
bool Graph<T>::_addEdge(const int & v1, const int & v2) {

	// Find the vertex's adjacency list.
	auto search = this->vertices.find(v1);

	// Check to make sure no edge already exists.
	for (auto iter = search->second.begin(); iter != search->second.end(); iter++) {

		if (*iter == v2) {

			return false;

		}

	}
	
	return true;

}

// Add an edge between the two vertices with values v1 & v2.
// Directed version: from v1 to v2.
template <typename T>
void Graph<T>::addEdge(const T & v1, const T & v2) {

	if (this->empty()) return;
	else if (v1 == v2) return;

	// Index indices.
	int index1 = _idxOf(v1);
	int index2 = _idxOf(v2);

	// Check that these vertices exist.
	auto search1 = this->vertices.find(index1);
	auto search2 = this->vertices.find(index2);

	// If they do not, throw an std::string error.
	if (search1 == this->vertices.end() || search2 == this->vertices.end()) {

		throw std::string("ERROR [addEdge]: one or more vertices not found.\n");

	}

	// Make sure the edge does not already exist.
	else if (!this->_addEdge(index1, index2)) {

		throw std::string("ERROR [addEdge]: edge already exists.\n");

	}
	
	// If this is a valid network, create the edge between the two.
	else {

		// For non self-loops. UNDIRECTED
		if (index1 != index2 && this->g_type == UNDIRECTED) {

			this->vertices[index1].push_back(index2);
			this->vertices[index2].push_back(index1);

		}

		// For non self-loops. DIRECTED
		else if (index1 != index2 && this->g_type == DIRECTED) {

			this->vertices[index1].push_back(index2);

		}

		// If there is already a self-loop, throw an error.
		else {

			throw std::string("ERROR [addEdge]: self loop already exists.\n");

		}

	}

}

// Print the graph in an adjacency list form.
template <typename T>
void Graph<T>::adjList(const bool & best_format) const {

	// Print in a nice format :)
	if (best_format) {

		std::cout << "\n         ADJACENCY LIST FOR GRAPH        \n";
		std::cout << "===========================================\n";
		std::cout << "Vertex : [ <neighbor1>, ... , <neighborN> ]\n";
		std::cout << "\n";

	}

	if (this->empty()) std::cout << "ADJACENCY LIST EMPTY!\n";
	
	// Print the vertex.
	for (auto g_trv = this->vertices.begin(); g_trv != this->vertices.end(); g_trv++) {

		std::cout << this->vertices_alias[g_trv->first] << " : [ ";

		if (g_trv->second.empty()) {

				std::cout << "<none> ]";

		}

		for (auto n_trv = g_trv->second.begin(); n_trv != g_trv->second.end(); n_trv++) {

			
			if ((n_trv + 1) != g_trv->second.end()) {

				std::cout << this->vertices_alias[*n_trv] << ", ";

			}
			else {

				std::cout << this->vertices_alias[*n_trv] << " ]";

			}

		}
		std::cout << "\n";

	}
	std::cout << "\n";

	if (best_format) std::cout << "\n===========================================\n";

}

// Functions to return what cell/index the knight is at.
template <typename T>
std::string Graph<T>::getKnightCell() const {

	return this->knight_location;

}

template <typename T>
int Graph<T>::getKnightIndex() const {

	return this->_idxOf(this->knight_location);

}

// Set the knights location
template <typename T>
void Graph<T>::setKnightLocation(const std::string & cell) {

	this->knight_location = cell;

}

template <typename T>
bool Graph<T>::empty() const {

	return this->vertices.empty();

}

// End of Graph.cpp