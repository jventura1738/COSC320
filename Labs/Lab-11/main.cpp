// Justin Ventura Lab-11
// COSC320 with Dr. Joe Anderson

// My graph class.
#include "Graph.h"

// My jspace namespace.
#include "jspace.h"

// This function will take the data from the file
// and make a graph out of it.  This graph MUST
// be an intger graph for simplicity.
// Returns: the graph from the file.
Graph<int> generateGraph(char ** filename);

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
			if (choice) G1 = generateGraph(argv);

		}

		if (!G1.empty()) {

			//G1 = randomGraph();

		}		

		

	}

	return 0;

}

Graph<int> generateGraph(char ** filename) {



}

// End of main.cpp