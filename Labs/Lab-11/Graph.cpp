// Justin Ventura COSC320
// Lab-11: Graph.cpp

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

	this->g_type = UNDIRECTED;

}

// Main Constructor.
template <typename T>
Graph<T>::Graph(const GRAPH_TYPE & type) {

	this->g_type = type;

}

// Copy Constructor.
template <typename T>
Graph<T>::Graph(const Graph<T> & old_graph) {

	this->g_type = old_graph.g_type;
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

	this->g_type = old_graph.g_type;
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

// Add a vertex to the graph with the value of vtx_val.
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

// Helper for addEdge().  Returns false if an edge exists
// between v1 & v2 already, true otherwise.
template <typename T>
bool Graph<T>::_addEdge(const T & v1, const T & v2) const {

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

	// Check that these vertices exist.
	auto search1 = this->vertices.find(v1);
	auto search2 = this->vertices.find(v2);

	// If they do not, throw an std::string error.
	if (search1 == this->vertices.end() || search2 == this->vertices.end()) {

		throw std::string("ERROR [addEdge]: one or more vertices not found.\n");

	}

	// Make sure the edge does not already exist.
	else if (this->_addEdge(v1, v2)) {

		throw std::string("ERROR [addEdge]: edge already exists.\n");

	}
	
	// If this is a valid network, create the edge between the two.
	else {

		bool addLoop = true;
		for (auto iter = this->vertices[v1].begin(); iter != this->vertices[v1].end(); iter++) {

			if (*iter == v1) {

				addLoop = false;

			}

		}

		// For non self-loops. UNDIRECTED
		if (v1 != v2 && this->g_type == UNDIRECTED) {

			this->vertices[v1].push_back(v2);
			this->vertices[v2].push_back(v1);

		}

		// For non self-loops. DIRECTED
		else if (v1 != v2 && this->g_type == DIRECTED) {

			this->vertices[v1].push_back(v2);

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

	if (best_format) std::cout << "\n===========================================\n";

}

// Print the graph by vertices in BFS order.
template <typename T>
void Graph<T>::printBFS(const T & root_vtx) {

	// Track the colors for each vertex.
	std::map<T, color_t> color;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		color.insert({iter->first, WHITE});

	}

	// Track the parents for each vertex.
	std::map<T, T> parent;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		parent.insert({iter->first, -999});

	}

	// Track the distance of each vertex.
	std::map<T, int> distance;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		distance.insert({iter->first, 999999999999});

	}

	// Queue for all the gray vertices.
	std::queue<T> Q;

	// Begin the algorithm.	
	color[root_vtx] = GRAY;
	distance[root_vtx] = 0;
	Q.push(root_vtx);

	while(!Q.empty()) {

		T u = Q.front();
		Q.pop();

		// Each pair (u, v) in E;
		for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++) {

			if (color[*v] == WHITE) {

				color[*v] = GRAY;
				distance[*v] = distance[u] + 1;
				parent[*v] = u;
				Q.push(*v);

			}

			color[u] = BLACK;

		}

	}

	// Begin the BFS order printing...
	auto c = color.begin();
	auto p = parent.begin();
	auto d = distance.begin();
	std::cout << "\n     BREADTH FIRST SEARCH ORDER PRINT      \n";
	std::cout << "            (Rooted at: " << root_vtx << ")  \n";
	std::cout << "      (WHITE = 0, GRAY = 1, BLACK = 2).      \n";
	std::cout << "\n===========================================\n";
	while (c != color.end()) {

		std::cout << "\n               - Step -                \n\n";
		std::cout << "Vertex discovered: " << c->first << "\n";
		std::cout << "Its parent: " << p->second << "\n";
		std::cout << "Its Current color: " << c->second << "\n";
		std::cout << "Its Distance from root: " << d->second << "\n";
		std::cout << "\n";
		c++;
		p++;
		d++;

	}

}

// Returns what type of graph this is.
template <typename T>
GRAPH_TYPE Graph<T>::getType() {

	return this->g_type;

}

// End of Graph.cpp