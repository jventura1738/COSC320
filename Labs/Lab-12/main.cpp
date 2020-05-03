// Justin Ventura Lab-11
// COSC320 with Dr. Joe Anderson

// My graph class.
#include "Graph.h"

// My jspace namespace.
#include "jspace.h"

// Libraries needed.
#include <iostream>
#include <fstream>

// This function will take the data from the file
// and make a graph out of it.  This graph MUST
// be an intger graph for simplicity.
// Returns: the graph from the file.
// Check README.md for formatting.
Graph<int> generateGraph(char * filename);

// This function will create a random graph with
// the number of vertices passed as a parameter.
// Also takes a parameter for whether or not the
// graph will be directed.
Graph<int> randomGraph(int & numvertices, const bool & isDirected);

// Returns a graph for the demo.
Graph<int> demoGraph(bool & isDirected);

int main(int argc, char ** argv) {

	if (argc > 2) {

		jspace::printError("expected 1 or 2 arguments, more than that provided.");
		std::cout << "[Total arguments given: " << argc << " ]\n";
		return 0;

	}
	else {

		std::cout << "======================================================\n";
		Graph<int> G1;
		if (argc == 2) {

			std::cout << "Would you like to use the graph passed as an argument?\n";
			int choice = jspace::binaryChoice();
			if (choice) G1 = generateGraph(argv[1]);
			std::cout << "Here are the stats from .txt based graph: \n";
			G1.adjList();
			G1.DFS(true);
			try {

				std::cout << "Attempting a Topological sort...\n";
				G1.topSortPrint();

			}
			catch (std::string err) {

				std::cout << err;

			}
			try {

				std::cout << "Attempting SCC Algorithm...\n";
				G1.SCCprint();

			}
			catch (std::string err) {

				std::cout << err;

			}

			bool isDirected = true;
			Graph<int> G2 = demoGraph(isDirected);

			std::cout << "\n===========================================\n";
			std::cout << "Demo random directed graph.\n";
			G2.adjList();
			G2.DFS(true);
			try {

				std::cout << "Attempting a Topological sort...\n";
				G2.topSortPrint();

			}
			catch (std::string err) {

				std::cout << err;

			}
			try {

				std::cout << "Attempting SCC Algorithm...\n";
				G2.SCCprint();

			}
			catch (std::string err) {

				std::cout << err;

			}

			isDirected = false;
			Graph<int> G3 = demoGraph(isDirected);

			std::cout << "\n===========================================\n";
			std::cout << "Demo random undirected graph.\n";
			G3.adjList();
			G3.DFS(true);
			try {

				std::cout << "Attempting a Topological sort...\n";
				G3.topSortPrint();

			}
			catch (std::string err) {

				std::cout << err;

			}
			try {

				std::cout << "Attempting SCC Algorithm...\n";
				G3.SCCprint();

			}
			catch (std::string err) {

				std::cout << err;

			}

			std::cout << "\n===========================================\n";
			std::cout << "TEMPLATE TEST (on std::string).\n";
			std::cout << "Simulate a basic network with 5 nodes.\n";

			Graph<std::string> Network(DIRECTED);
			Network.addVertex("Justin's Node");
			Network.addVertex("Blaine's Node");
			Network.addVertex("Jacob's Node");
			Network.addVertex("Ian's Node");
			Network.addVertex("Anderson's Node");

			Network.addEdge("Justin's Node", "Blaine's Node");
			Network.addEdge("Blaine's Node", "Justin's Node");
			Network.addEdge("Justin's Node", "Ian's Node");
			Network.addEdge("Anderson's Node", "Blaine's Node");
			Network.addEdge("Anderson's Node", "Jacob's Node");
			Network.addEdge("Anderson's Node", "Ian's Node");
			Network.addEdge("Ian's Node", "Justin's Node");
			Network.addEdge("Jacob's Node", "Justin's Node");

			Network.adjList();
			Network.DFS(true);

			try {

				std::cout << "Attempting a Topological sort...\n";
				Network.topSortPrint();

			}
			catch (std::string err) {

				std::cout << err;

			}
			try {

				std::cout << "Attempting SCC Algorithm...";
				Network.SCCprint();

			}
			catch (std::string err) {

				std::cout << err;

			}

		}	

	}

	return 0;

}

Graph<int> generateGraph(char * filename) {

	std::ifstream infile(filename);
	if (!infile) {

		throw std::string("File did not open.");

	}
	else {

		std::cout << "Creating graph from: '" << filename << "'.\n";
		int isDirected;
		infile >> isDirected;
		Graph<int> G1((isDirected) ? DIRECTED : UNDIRECTED);
		std::vector<int> vect;
		int read = 0, i = 0;
		while (infile >> read) {
			
			try {

				G1.addVertex(read);

			}
			catch(std::string err) {

				std::cout << err;
				std::cout << "Vertex ignored: " << read << "\n";

			}
			
			vect.push_back(read);

		}
		infile.clear();
		while (infile >> read) {

			if (read == -1) {

				i++;
				continue;

			}
			try {

				G1.addEdge(vect[i], read);

			}
			catch (std::string err) {

				std::cout << err;
				std::cout << "Edge: (" << vect[i] << ", " << read << ") ignored.\n";

			}
			

		}

		return G1;

	}

}

// Does nothing for now, not required for the lab.
Graph<int> randomGraph(int & numVertices, const bool & isDirected) {

	return Graph<int>(DIRECTED);

}

Graph<int> demoGraph(bool & isDirected) {

	if (isDirected) {

		Graph<int> G1(DIRECTED);
		G1.addVertex(1);
		G1.addVertex(2);
		G1.addVertex(3);
		G1.addVertex(4);
		G1.addVertex(5);

		G1.addEdge(1, 2);
		G1.addEdge(2, 3);
		G1.addEdge(3, 4);
		G1.addEdge(5, 3);
		G1.addEdge(5, 4);
		return G1;

	}
	else {

		Graph<int> G1(UNDIRECTED);
		G1.addVertex(1);
		G1.addVertex(2);
		G1.addVertex(3);
		G1.addVertex(4);
		G1.addEdge(1, 2);
		G1.addEdge(2, 3);
		G1.addEdge(3, 1);
		G1.addEdge(2, 4);
		return G1;

	}

}
// End of main.cpp