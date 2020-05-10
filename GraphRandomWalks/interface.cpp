// Justin Ventura/Jacob Duncan COSC320
// Project 3: Interface.cpp

#include "Interface.h"

/*
 * This function returns a vector of pairs of each possible
 * 'knight offset' which is just the numeric X & Y distances
 * from an origin such that (origin + offset) is a valid
 * knight move on a chess board.
 * 
 * - Justin Ventura & Jacob Duncan
*/
std::vector<std::pair<int, int>> knight_offsets() {

  // All possible moves
  int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
  int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

  std::vector<std::pair<int, int>> offsets;

  for (int i = 0; i < 8; i++) {

    offsets.push_back({X[i], Y[i]});

  }

  // Return total possible offset vector
  return offsets;

}
/*
 * A function which can be used to return the set of all possible
 * pairs of co-ordinates in a (r x c) graph.  Note that this
 * function originates at (0, 0), not (1, 1).
 * 
 * Example, take a (2 x 2) graph, and let S be the set of pairs:
 * S = {(0,0), (0,1), (1,0), (1,1)}
 * 
 * - Justin Ventura
*/
std::set<std::pair<int, int>> twoD_pairs(int row, int col) {

  std::set<std::pair<int, int>> S;
  for (int i = 0; i < row; i++) {

    for (int j = 0; j < col; j++) {

      S.insert({i, j});

    }

  }
  return S;

}

/*
 * A function to return whether or not a set of pairs contains
 * the given pair.  True if the pair exists in the set, false
 * otherwise.
 * 
 * - Justin Ventura
*/
bool setContains(std::set<std::pair<int, int>> S, std::pair<int, int> p) {

  for (auto i = S.begin(); i != S.end(); i++) {

    if (*i == p) return true;
  
  }
  return false;

}

/*
 * This function generates a chess board where every cell is a
 * vertex in the (8 x 8) graph 'chess board', and each edge is
 * a legal knight move from v1 to v2.  This is our prerequisite
 * to the 'Knight Random Walk.'
 * 
 * - Justin Ventura & Jacob Duncan
*/
Graph<std::string> generate_chess_board() {

  // We create an undirected graph as a chess board which
  // will be set up with all possible knight moves at the
  // the given vertex, then the graph is returned.
  Graph<std::string> chessBoard(UNDIRECTED);
  {
    // This is in its own scope to save memory.
    std::string xCoord[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    std::string yCoord[] = {"1", "2", "3", "4", "5", "6", "7", "8"};

    // Generates Board with 2 Char Values for each cell
    for(int i = 0; i < 8; i++) {

      for (int j = 0; j < 8; j++) {

      std::string coordinates = "";
      coordinates += xCoord[j];
      coordinates += yCoord[i];
      chessBoard.addVertex(coordinates);
      
      } 

    }

  }

  // These are used to ensure that the board is set up correctly.
  std::vector<std::pair<int, int>> offsets = knight_offsets();
  std::set<std::pair<int, int>> orderedPairs = twoD_pairs(8, 8);

  /*
    * Here is the algorithm for setting up the board with all possible
    * knight moves.  In our algorithm, we go vertex by vertex (each is
    * a cell on the chess board) adding an edge between each in vertex
    * in the graph, and every other vertex which would result in a valid
    * knight move.  We used the board as a 1D vector, so we had to use
    * some interesting conversions to make it possible.
    * 
    * This took us 3 hours all because we were missing on term in an 
    * expression.  Noted: don't code while tired.
    * 
    * - Justin Ventura & Jacob Duncan
  */

  // Double for-loop to get each vertex in the graph.
  for (int i = 0; i < 8; i++) {

    // (8 x 8) = 64 vertices.
    for (int j = 0; j < 8; j++) {
        
      // Here we check for every possible move, adding only legal ones.
      for (auto v = offsets.begin(); v != offsets.end(); v++) {

        // Keep track for representing 2D board as a 1D vector.
        int index = i * 8 + j; 

        // Here is 'offset' for a knight move from some origin.
        int offset = (v->second * 8 + v->first); 

        try {

          // This pair is the 2D version of the 1D representation of 
          // (index + offset) or 'knight move'. 
          std::pair<int, int> p = {i + v->second, j + v->first};

          // Using the above pair, we check that this pair representing
          // a move is indeed a valid move on chess board.
          if (setContains(orderedPairs, p)) {

              // If so, add the edge.
              chessBoard.addEdge(chessBoard.vertices_alias[index], chessBoard.vertices_alias[index + offset]);

          }      

        }
        catch(std::string s){

            continue;

        }

      }

    }

  }

  // Return the properly generated chess board.
  return chessBoard;

}

