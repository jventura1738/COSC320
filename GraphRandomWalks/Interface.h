// Justin Ventura/Jacob Duncan COSC320
// Project 3: Interface.h

#include "Graph.h"
#include <set>

#ifndef INTERFACE_H
#define INTERFACE_H

// Step 1. Generate Graph - COMPLETE
// Step 2. Add Knight Piece
// Step 3. Display both

// TODO: Add color to the cells the Knight visited on its tour

/*
 * This function returns a vector of pairs of each possible
 * 'knight offset' which is just the numeric X & Y distances
 * from an origin such that (origin + offset) is a valid
 * knight move on a chess board.
 * 
 * - Justin Ventura & Jacob Duncan
*/
std::vector<std::pair<int, int>> knight_offsets();

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
std::set<std::pair<int, int>> twoD_pairs(int row, int col);

/*
 * A function to return whether or not a set of pairs contains
 * the given pair.  True if the pair exists in the set, false
 * otherwise.
 * 
 * - Justin Ventura
*/
bool setContains(std::set<std::pair<int, int>> S, std::pair<int, int> p);

/*
 * This function generates a chess board where every cell is a
 * vertex in the (8 x 8) graph 'chess board', and each edge is
 * a legal knight move from v1 to v2.  This is our prerequisite
 * to the 'Knight Random Walk.'
 * 
 * - Justin Ventura & Jacob Duncan
*/
Graph<std::string> generate_chess_board();

#endif