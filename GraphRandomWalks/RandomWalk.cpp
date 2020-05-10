// Justin Ventura/Jacob Duncan COSC320
// Project 3: RandomWalk.cpp

// External libraries/headers.
#include <iostream>
#include <fstream>     // For printing to a file.
#include <random>      // The walks will be... random.
#include <chrono>      // Timing the walks.
#include <iomanip>     // set precision of output
#include "Graph.h"     // Justin's Modified Graph class.
#include "Interface.h" // Our Interface header.

// Colors for the terminal.
#define RESET    "\x1B[0m"  // Set all colors back to normal.
#define FORERED  "\x1B[31m" // Red
#define FOREGRN  "\x1B[32m" // Green
#define FOREYEL  "\x1B[33m" // Yellow

// Global variables for running tests.
std::string ORIGIN = "A1";

/*
 * This function will simulate the random walk by creating
 * a vector of integers which will correspond to the cells
 * that the knight has jumped to.  This vector iterated
 * from begin() to end() will be in the order that the
 * knight has walked.  This walk will end once the knight
 * has returned to its origin.
 * 
 * - Justin Ventura & Jacob Duncan
*/
std::vector<int> randomWalk(Graph<std::string> & Board);

/*
  * Function that will return the average steps
  * of all the trials simulated 
  * aiming to get near the 160 marker that most have already
  * achieved, need to find how many TRIALS it will take
  * for us to get that number
  * we found that it takes around 200 - 250 Trials
  *
  * - Jacob Duncan & Justin Ventura
*/
unsigned int getAverageSteps(unsigned int, unsigned int);

/*
 * This function simply prompts the user for how many trials
 * of the random walk they would like to run.
 * 
 * - Justin Ventura
*/
unsigned int promptNumTrials();

/*
 * Input a file which you would like the data to be sent to.
 * (file will be reset as it is opened)
 * The statistics included are:
 * 
 * - The total trials ran (TRIALS entered by user).
 * - The total time of all trials.
 * - The average steps of all walks.
 * - The lowest number of steps in a walk.
 * - The highest number of steps in a walk.
 * - Number of steps per trial.
*/
int main (int argc, char ** argv) {

  // Initialize the chess board for the random walk starting
  // the knight at A1.
  Graph<std::string> ChessBoard = generate_chess_board();
  ChessBoard.setKnightLocation(ORIGIN);

  // Number of trials given by the user.
  unsigned int TRIALS = promptNumTrials();

  // For statistical data.
  int stepsCounter = 0;
  typedef std::chrono::high_resolution_clock Clock;
  auto start = std::chrono::system_clock::now(); // starts time

  if (argc == 2) {

    // Get file passed in on command line
    std::ofstream outputFile(argv[1]);

    if (!outputFile) {

      std::cerr << "[ERROR] File did not open.\n";
      std::cerr << "Terminating program.\n";
      exit(1);

    }

    // Fill the users file with the console output
    // Run random walk trials.
    for (unsigned i = 0; i < TRIALS; i++) {

      // Perform the random walk.
      std::vector<int> walkPath = randomWalk(ChessBoard);
      
      outputFile << "Walk path for trial " << (i+1) 
      << "/" << TRIALS << ": " << "[" << ORIGIN << "] ";

      for (auto j = walkPath.begin(); j != walkPath.end(); j++) {

        if(ChessBoard.vertices_alias[*j] == ChessBoard.vertices_alias[*(walkPath.end() - 1)]) {

          // Print green if origin
          outputFile << "[" << ChessBoard.vertices_alias[*j] << "]" << std::endl;

        }
        else {

          // Print red if not origin (in walk)
          outputFile << ChessBoard.vertices_alias[*j] << " ";

        }

      }
      outputFile << "------------------------\n";
      outputFile << "Total steps in walk: " << walkPath.size();
      stepsCounter += walkPath.size();
      outputFile << "\n------------------------\n";
      outputFile << std::endl;
    }

    auto end = std::chrono::system_clock::now(); // ends time
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(4);
    outputFile << "==> Trials Took: " << elapsed_seconds.count() << "s" << std::endl;
    outputFile << "==> Average Steps: " << getAverageSteps(TRIALS, stepsCounter) << std::endl;
    return 0;

  }

  else if (argc < 1 || argc > 2){

    std::cout << argc << " arguments were given.\n";
    std::cout << "[ERROR] Number of arguments must be 1 or 2.\n";
    exit(1);
  }
  else {

    // Run random walk trials.
    for (unsigned i = 0; i < TRIALS; i++) {

      // Perform the random walk.
      std::vector<int> walkPath = randomWalk(ChessBoard);
      
      std::cout << FOREYEL << "Walk path for trial " << RESET << FOREGRN << (i+1) 
      << "/" << TRIALS << RESET << ": " << "[" << FOREGRN << ORIGIN << RESET << "] ";

      for (auto j = walkPath.begin(); j != walkPath.end(); j++) {

        if(ChessBoard.vertices_alias[*j] == ChessBoard.vertices_alias[*(walkPath.end() - 1)]) {

          // Print green if origin
          std::cout << "[" << FOREGRN << ChessBoard.vertices_alias[*j] << RESET << "]" << std::endl;

        }
        else {

          // Print red if not origin (in walk)
          std::cout << FORERED << ChessBoard.vertices_alias[*j] << RESET << " ";

        }

      }
      std::cout << FOREYEL << "------------------------\n";
      std::cout << "Total steps in walk: " << RESET << FOREGRN << walkPath.size() << RESET << FOREYEL;
      stepsCounter += walkPath.size();
      std::cout << "\n------------------------\n" << RESET;
      std::cout << std::endl;
    }

    auto end = std::chrono::system_clock::now(); // ends time
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double>elapsed_seconds = end-start;
    std::cout << std::setprecision(4);
    std::cout << "==> Trials Took: " << FOREGRN << elapsed_seconds.count() << "s" << RESET << std::endl;
    std::cout << "==> Average Steps: " << FOREGRN << getAverageSteps(TRIALS, stepsCounter) << RESET << std::endl;
    return 0;

    }

}

/*
 * This function will simulate the random walk by creating
 * a vector of integers which will correspond to the cells
 * that the knight has jumped to.  This vector iterated
 * from begin() to end() will be in the order that the
 * knight has walked.  This walk will end once the knight
 * has returned to its origin.
 * 
 * - Justin Ventura & Jacob Duncan
*/
std::vector<int> randomWalk(Graph<std::string> & Board) {

  // This vector will contain the path from the start of the
  // walk to the end.
  std::vector<int> path;

  // Random number be like:
  unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed1);
  std::uniform_real_distribution<double> distribution(0,2);
  int walk = distribution(generator);

  // First step in the walk.
  std::string walkTo = (walk) ? "B3" : "C2";
  Board.setKnightLocation(walkTo);
  path.push_back(Board._idxOf(walkTo)); 

  // Random walking begins.
  while (Board.getKnightCell() != ORIGIN) {

    // Get a pool of legal moves to randomly choose from.
    std::vector<std::string> legalMoves;
    for (auto v = Board.vertices[Board._idxOf(Board.getKnightCell())].begin(); v != Board.vertices[Board._idxOf(Board.getKnightCell())].end(); v++) {

      legalMoves.push_back(Board.vertices_alias[*v]);

    }

    // Choose a new location to walk to.
    std::uniform_real_distribution<double> distribution2(0, legalMoves.size());
    walk = distribution2(generator);

    // Walk to the new location.
    Board.setKnightLocation(legalMoves[walk]);
    path.push_back(Board._idxOf(Board.getKnightCell())); 

  }

  // This contains a string of walk moves.
  return path;

}

unsigned int getAverageSteps(unsigned int trials, unsigned int totalSteps){
    return totalSteps / trials;
}

/*
 * This function simply prompts the user for how many trials
 * of the random walk they would like to run.
 * 
 * - Justin Ventura
*/
unsigned int promptNumTrials() {

  std::cout << "How many random walk trials to be run?\n";
  std::cout << "--> ";
  unsigned int trials;
  std::cin >> trials;
  while (!std::cin.good() || (trials <= 0)) {

    std::cin.clear();
    std::cin.ignore(INT32_MAX, '\n');
    std::cout << "Invalid, re-enter ---> ";
    std::cin >> trials;

  }
  
  return trials;
  
}