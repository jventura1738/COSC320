// Justin Ventura COSC320
// Lab-11: Graph.cpp

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

template <typename T>
void Graph<T>::_DFSvisit(int u, std::map<int, color_t> & color, std::map<int, int> & parent, const bool & print) {

	this->time++;
	this->disc_times[u] = this->time;
	color[u] = GRAY;
	for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++) {

		if (color[*v] == WHITE) {

			parent[*v] = u;
			this->_DFSvisit(*v, color, parent, print);

		}
		if (color[*v] == GRAY) {

			this->isDAG = false;

		}

	}
	if (print) std::cout << this->vertices_alias[u] << " ";
	color[u] = BLACK;
	this->time++;
	this->fin_times[u] = this->time;

}

template <typename T>
void Graph<T>::_SCCDFS(std::vector<std::pair<int, int>> & list) {

	std::map<int, color_t> color;
	for (auto u = this->vertices.begin(); u != this->vertices.end(); u++) {

		color.insert({u->first, WHITE});

	}
	std::cout << "\n===========================================\n";
	std::cout <<   "    STRONGLY CONNECTED COMPONENT GROUPS    \n";
	std::cout << "\n";
	int i = 0;
	for (auto u = list.begin(); u != list.end(); u++) {

		std::cout << "Group " << (++i) << ": ";
		if (color[u->second] == WHITE) {

			this->_SCCvisit(u->second, color);

		}
		std::cout << "\n";

	}

}

template <typename T>
void Graph<T>::_SCCvisit(int u, std::map<int, color_t> & color) {

	color[u] = GRAY;
	for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++) {

		if (color[*v] == WHITE) {

			this->_SCCvisit(*v, color);

		}

	}
	color[u] = BLACK;
	std::cout << this->vertices_alias[u] << " ";

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
		
		std::vector<T> n_list;
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

		bool addLoop = true;
		for (auto iter = this->vertices[index1].begin(); iter != this->vertices[index1].end(); iter++) {

			if (*iter == index1) {

				addLoop = false;

			}

		}

		// For non self-loops. UNDIRECTED
		if (index1 != index2 && this->g_type == UNDIRECTED) {

			this->vertices[index1].push_back(index2);
			this->vertices[index2].push_back(index1);

		}

		// For non self-loops. DIRECTED
		else if (index1 != index2 && this->g_type == DIRECTED) {

			this->vertices[index1].push_back(index2);

		}

		// For self-loops.
		else if (addLoop){

			this->vertices[index1].push_back(index1);

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

	// Integer indices.
	int index1 = _idxOf(v1);
	int index2 = _idxOf(v2);

	// Check that these vertices exist.
	auto search1 = this->vertices.find(index1);
	auto search2 = this->vertices.find(index2);

	// If v1 is not in the graph, force it in.
	if (search1 == this->vertices.end()) {

		std::cout << "WARNING [forceAddEdge]: forcing " << v1 << " into graph\n";
		this->addVertex(index1);

	}

	// If v2 is not in the graph, force it in.
	if (search2 == this->vertices.end()) {

		std::cout << "WARNING [forceAddEdge]: forcing " << v2 << " into graph\n";
		this->addVertex(index2);

	}

	// Give a warning if the edge already exists.
	if (!this->_addEdge(index1, index2)) {

		std::cout << "WARNING [forceAddEdge]: adding additional edge.\n";

	}

	// For self loops.
	bool addLoop = true;
	for (auto iter = this->vertices[index1].begin(); iter != this->vertices[index1].end(); iter++) {

		if (*iter == index1) {

			addLoop = false;

		}

	}

	// For non self-loops. UNDIRECTED
	if (index1 != index2 && this->g_type == UNDIRECTED) {

		this->vertices[index1].push_back(index2);
		this->vertices[index2].push_back(index1);

	}

	// For non self-loops. DIRECTED
	else if (index1 != index2 && this->g_type == DIRECTED) {

		this->vertices[index1].push_back(index2);

	}

	// For self-loops.
	else if (addLoop){

		this->vertices[index1].push_back(index1);

	}

	// If there is already a self-loop, give a warning.
	else {

		std::cout << "WARNING [forceAddEdge]: adding additional self-loop.\n";
		this->vertices[index1].push_back(index1);

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

	if (this->empty()) std::cout << "LIST EMPTY!\n";
	
	// Print the vertex.
	for (auto g_trv = this->vertices.begin(); g_trv != this->vertices.end(); g_trv++) {

		std::cout << this->vertices_alias[g_trv->first] << " : [ ";

		for (auto n_trv = g_trv->second.begin(); n_trv != g_trv->second.end(); n_trv++) {

			if (g_trv->second.empty()) {

				std::cout << " ]";

			}
			else if ((n_trv + 1) != g_trv->second.end()) {

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

// Print the graph by vertices in BFS order.
template <typename T>
void Graph<T>::printBFS(const T & root_vtx) {

	if (this->empty) return;
	std::cout << "\n     BREADTH FIRST SEARCH ORDER PRINT      \n";

	// Root index.
	int index = _idxOf(root_vtx);

	// Track the colors for each vertex.
	std::map<int, color_t> color;
	std::map<int, int> parent;
	std::map<int, int> distance;
	for (auto iter = this->vertices.begin(); iter != this->vertices.end(); iter++) {

		color.insert({iter->first, WHITE});
		parent.insert({iter->first, -999999999});
		distance.insert({iter->first, 999999999});

	}

	// Queue for all the gray vertices.
	std::queue<int> Q;

	// Begin the algorithm.	
	color[index] = GRAY;
	distance[index] = 0;
	Q.push(index);
	std::cout << "BFS Ordering rooted at: " << Q.front() << " -> " << Q.front() << " ";

	while(!Q.empty()) {

		int u = Q.front();
		Q.pop();
		int i = 0;

		// Each pair (u, v) in E;
		for (auto v = this->vertices[u].begin(); v != this->vertices[u].end(); v++, i++) {

			if (color[*v] == WHITE) {

				color[*v] = GRAY;
				distance[*v] = distance[u] + 1;
				parent[*v] = u;
				Q.push(*v);
				std::cout << this->vertices_alias[i] << " ";

			}

			color[u] = BLACK;

		}

	}

	std::cout << "\n\n";

}

template <typename T>
void Graph<T>::DFS(const bool & print) {

	if (this->empty()) return;

	// Maps for tracking data in algorithm.
	std::map<int, color_t> color;
	std::map<int, int> parent;

	if (print) std::cout << "\n      DEPTH FIRST SEARCH ORDER PRINT      \n";

	// Set the maps.
	for (auto u = this->vertices.begin(); u != this->vertices.end(); u++) {

		color.insert({u->first, WHITE});
		parent.insert({u->first, -999999999});

	}
	this->time = 0;

	// Begin the DFS algorithm.
	for (auto u = this->vertices.begin(); u != this->vertices.end(); u++) {

		if (color[u->first] == WHITE) {

			this->_DFSvisit(u->first, color, parent, print);

		}

	}

	std::cout << "\n";

}

template <typename T> 
void Graph<T>::topSortPrint() {

	// First perform a DFS to gather timings.
	this->DFS();

	// Check for required graphs.
	if (!this->isDAG) {

		throw std::string("ERROR [topSortPrint] requires: a Directed & Acyclic Graph.\n");

	}
	// Use a std::vector of std::pairs in order to easily sort and reverse.
	std::vector<std::pair<int, int>> list;

	// Gather the finish times.
	for (auto t = this->fin_times.begin(); t != this->fin_times.end(); t++) {

		list.push_back({t->second, t->first});

	}

	// Sort then reverse the list.
	std::sort(list.begin(), list.end());
	std::reverse(list.begin(), list.end());

	std::cout << "    A TOPOLOGICAL SORT ORDERING     \n";
	std::cout << "--> ";
	for (auto i = list.begin(); i != list.end(); i++) {

		if (i + 1 != list.end()) {

			std::cout << this->vertices_alias[i->first] << "'s time: " << i->second << ", ";

		}
		else {

			std::cout << this->vertices_alias[i->first] << "'s time: " << i->second << ". ";

		}

	}
	std::cout << "\n";

}

template<typename T>
void Graph<T>::SCCprint() {

	// Prerequisites for this algorithm.
	if (this->g_type != DIRECTED) {

		throw std::string("ERROR [SCCprint] requires: a Directed Graph.\n");

	}
	this->DFS();
	Graph<T> copy = *this;

	// Make another pair vector like in DFS.
	std::vector<std::pair<int, int>> list;

	// Gather the finish times.
	for (auto t = this->fin_times.begin(); t != this->fin_times.end(); t++) {

		list.push_back({t->second, t->first});

	}
	std::sort(list.begin(), list.end());
	std::reverse(list.begin(), list.end());

	// Taking advantage of copy for the transpose.
	copy._SCCDFS(list);
}

// Returns what type of graph this is.
template <typename T>
GRAPH_TYPE Graph<T>::getType() const {

	return this->g_type;

}

template <typename T>
bool Graph<T>::empty() const {

	return this->vertices.empty();

}

// End of Graph.cpp