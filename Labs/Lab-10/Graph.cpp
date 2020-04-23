// Justin Ventura COSC320
// Lab-10: Graph.cpp

#include "Graph.h"
#include <limits>

// Enumeration for coloring vertices in the BFS print function.
// White: default color for the vertex.
// Gray:  after we visit the vertex, but not yet its neighbors.
// Black: after we visit the vertex and its neighbors.
enum color_t { WHITE = 0, GRAY, BLACK };

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

	//std::cout << "Graph Constructed.\n";

}

// Copy Constructor.
template <typename T>
Graph<T>::Graph(const Graph<T> & old_graph) {

	//std::cout << "Copyboi\n";
	this->vertices = old_graph.vertices;

}

// Destructor.
template <typename T>
Graph<T>::~Graph() {

	//std::cout << "Salute\n";

}

// Overloaded Assignment Operator.
template <typename T>
void Graph<T>::operator=(const Graph<T> & old_graph) {

	this->vertices = old_graph.vertices;

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
void Graph<T>::addVertex(const T & vtx_val) {

	// Be sure this is not a duplicate vertex.
	auto search = this->vertices.find(vtx_val);

	// If it is not, add to the graph.
	if (search == this->vertices.end()) {

		std::vector<T> n_list;
		this->vertices.insert({vtx_val, n_list});

	}
	// Otherwise, throw an std::string error.
	else {

		throw std::string("ERROR [addVertex]: duplicate vertex.\n");

	}

}

// Add an edge between the two vertices with values v1 & v2.
template <typename T>
void Graph<T>::addEdge(const T & v1, const T & v2) {

	// Check that these vertices exist.
	auto search1 = this->vertices.find(v1);
	auto search2 = this->vertices.find(v2);

	// If they do not, throw an std::string error.
	if (search1 == this->vertices.end() || search2 == this->vertices.end()) {

		throw std::string("ERROR [addEdge]: one or more vertices not found.\n");

	}
	
	// If they do, create the edge between the two.
	else {

		bool addLoop = true;
		for (auto iter = this->vertices[v1].begin(); iter != this->vertices[v1].end(); iter++) {

			if (*iter == v1) {

				addLoop = false;

			}

		}

		// For non self-loops.
		if (v1 != v2) {

			this->vertices[v1].push_back(v2);
			this->vertices[v2].push_back(v1);

		}

		// For self-loops.
		else if (addLoop){

			this->vertices[v1].push_back(v1);

		}

		// If there is already a self-loop, throw an error.
		else {

			throw std::string("ERROR [addEdge]: self loop already exists.\n");

		}

	}

}

// Add an edge between the two vertices with values v1 & v2.
template <typename T>
void Graph<T>::forceAddEdge(const T & v1, const T & v2) {

	// Check that these vertices exist.
	auto search1 = this->vertices.find(v1);
	auto search2 = this->vertices.find(v2);

	// If v1 is not in the graph, force it in.
	if (search1 == this->vertices.end()) {

		this->addVertex(v1);

	}

	// If v2 is not in the graph, force it in.
	if (search2 == this->vertices.end()) {

		this->addVertex(v2);

	}

	// Put an edge between the two.
	this->vertices[v1].push_back(v2);
	this->vertices[v2].push_back(v1);

}

// Print the graph in an adjacency list form.
template <typename T>
void Graph<T>::printGraph(const bool & best_format) const {

	// Print in a nice format :)
	if (best_format) {

		std::cout << "\n         ADJACENCY LIST FOR GRAPH        \n";
		std::cout << "===========================================\n";
		std::cout << "Vertex : [ <neighbor1>, ... , <neighborN> ]\n";
		std::cout << "\n";

	}
	// Print the vertex.
	for (auto g_trv = this->vertices.begin(); g_trv != this->vertices.end(); g_trv++) {

		std::cout << g_trv->first << " : [ ";

		// Print its neighbors.
		for (auto n_trv = g_trv->second.begin(); n_trv != g_trv->second.end(); n_trv++) {

			if ((n_trv + 1) != g_trv->second.end()) {

				std::cout << *n_trv << ", ";

			}
			else {

				std::cout << *n_trv << " ]";

			}

		}

		std::cout << "\n";

	}

	if (best_format)std::cout << "\n===========================================\n";

}

// Print the graph by vertices in BFS order.
template <typename T>
void Graph<T>::printBFS(const T & root_vtx) const {

	// Track the colors for each vertex.
	std::map<T, color_t> color;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		color.insert({iter->first, WHITE});

	}

	// Track the parents for each vertex.
	std::map<T, T> parent;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		parent.insert({iter->first, NULL});

	}

	// Track the distance of each vertex.
	std::map<T, int> distance;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		distance.insert({iter->first, INT_MAX});

	}

	// Queue for all the gray vertices.
	std::queue<T> Q;

	// Begin the algorithm.	
	color[root_vtx] = GRAY;
	distance[root_vtx] = 0;
	Q.push(root_vtx);

	while(!Q.empty) {

		T u = Q.front();
		Q.pop();

		// Each pair (u, v) in E;
		for (auto v = this->vertices[u]; v != this->vertices[u].end(); v++) {

			if (color[*v] == WHITE) {

				color[*v] = GRAY;
				distance[*v] = distance[u] + 1;
				parent[*v] = u;
				Q.push(*v);

			}

			color[u] = BLACK;

		}

	}

}

// End of Graph.cpp