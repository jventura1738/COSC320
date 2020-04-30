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
Graph<int> randomGraph(int & numvertices, bool isDirected);

int main(int argc, char ** argv) {

	if (argc > 2) {

		jspace::printError("expected 1 or 2 arguments, more than that provided.");
		std::cout << "[Exceeded amount given: " << argc << " ]\n";
		return 0;

	}
	else {

		std::cout << "======================================================\n";
		Graph<int> G1;
		if (argc == 2) {

			std::cout << "Would you like to use the graph passed as an argument?\n";
			int choice = jspace::binaryChoice();
			if (choice) G1 = generateGraph(argv[1]);

		}
		G1.printGraph(true);

		// if (!G1.empty()) {

		// 	G1 = randomGraph();

		// }		

		

	}

	return 0;

}

Graph<int> generateGraph(char * filename) {

	std::ifstream infile(filename);
	if (!infile) {

		throw std::string("File did not open.");

	}
	else {

		int isDirected;
		infile >> isDirected;
		Graph<int> G1((isDirected) ? DIRECTED : UNDIRECTED);
		std::vector<int> vect;
		int read = 0, i = 0;
		std::cout << "bruh\n";
		while (true) {
			
			//infile >> read;
			G1.addVertex(read);
			vect.push_back(read);
			std::cout << "Vertex added.\n";
			if (!infile) break;

		}
		infile.clear();
		while (infile >> read) {

			std::cout << read << "\n";
			if (read == -1) {

				i++;
				continue;

			}
			G1.addEdge(vect[i], read);

		}

		return G1;

	}

}

// End of main.cpp