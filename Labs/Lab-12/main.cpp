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

int main(int argc, char ** argv) {

	if (argc > 2) {

		jspace::printError("expected 1 or 2 arguments, more than that provided.");
		std::cout << "[Total arguments given: " << argc << " ]\n";
		return 0;

	}
	else {

		Graph<int> G1 = generateGraph(argv[1]);
		
		try {

			G1.adjList();
			std::cout << "\nApprox vertex cover...\n";
			G1.printVertexCover();
			std::cout << "\nApprox vertex cover[rand]..\n";
			G1.randVertexCover();
			std::cout << "\nTrue minimum vertex cover...\n";
			G1.minVertexCover();

		}
		catch(std::string err) {

			std::cout << err << '\n';

		}

		Graph<int> G2;
		G2.addVertex(0);
		try {

			G2.adjList();
			std::cout << "\nApprox vertex cover...\n";
			G2.printVertexCover();
			std::cout << "\nApprox vertex cover[rand]..\n";
			G2.randVertexCover();
			std::cout << "\nTrue minimum vertex cover...\n";
			G2.minVertexCover();

		}
		catch(std::string err) {

			std::cout << err << '\n';

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

// End of main.cpp