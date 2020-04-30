#include<iomanip>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<iostream>

// define this to compile in debug mode
//#define DEBUG

/*
 *  File: gridai.cpp
 *
 *  Protype of basic BFS-driven pathfinding to simulate monsters chasing a player
 *  through a grid-based world.
 *
 */


// represent world entities
enum grid_t {
  wall, floor, player, monster
};

// for laziness in streaming
std::ostream& operator<<(std::ostream& os, const grid_t g){
  switch(g){
    case wall:
      os << "@";
      break;
    case floor:
      os << " ";
      break;
    case player:
      os << "P";
      break;
    case monster:
      os << "M";
      break;
  }
  return os;
}

enum color_t{
  white, gray, black
};

class GameGrid {
  private:
    int height;
    int width;
    std::vector<std::vector<grid_t> > cells;   // map matrix
    std::pair<int, int> player;               // player coords
    std::vector<std::pair<int,int> > monsters; // set of monster coordinates
    std::map<std::pair<int,int>, int> d;

  public:
    // keep in mind: 0,0 is top-left. the y-axis is flipped so that
    // increasing y-coordinate is further down the screen
    GameGrid(){
      height = 10;
      width = 20;

      initCells();

      // player at top-left
      player.first = 1;
      player.second = 1;

      // start one monster at the bottom-right
      monsters.push_back(std::pair<int,int>(height-2, width-2));
    }

    // set up the grid map
    void initCells(){
      // put walls around the edge and open floor in the center
      for(int i=0; i<height; i++){
        cells.push_back(std::vector<grid_t>());
        for(int j=0; j<width; j++){
          if(i>0 && i<height-1 && j>0 && j<width-1){
            cells[i].push_back(floor);
          } else {
            cells[i].push_back(wall);
          }
        }
      }

      // hard-code a rectangle of walls to force monsters
      // to re-route around them
      cells[5][5] = wall;
      cells[5][6] = wall;
      cells[6][5] = wall;
      cells[6][6] = wall;
    }

    // take keyboard input and update situation accordingly.
    // then render the result
    void handle(char c){
      movePlayer(c);
      moveMonsters();
      render();
    }

    // redraw the current situation.
    // This is not efficient: use a full buffer/flush mechanism.
    // Best way to use ncurses or existing "nice" rendering library.
    // But this preserves logical clarity over efficiency.
    void render(){
      system("clear");
      for(auto row=0; row<height; row++){
        for(auto col=0; col<width; col++){
          if( std::make_pair(row,col) == player ){
            // draw player
            std::cout << grid_t::player;
          } else if (std::find(monsters.begin(), monsters.end(), std::make_pair(row,col)) != monsters.end()) {
            // draw monster
            std::cout << grid_t::monster;
          } else {
            // draw world
#ifdef DEBUG
            // output in base-62 to keep spacing consistent
            int c = '0' + d[std::make_pair(row,col)];
            c = c > '9' ? c + ('A' - '9' - 1) : c; // don't overflow into weird symbols
            std::cout << char(c);
#else
            std::cout << cells[row][col];
#endif
          }
        }
        std::cout << std::endl;
      }
    }

    // wasd movement wrt the board layout
    // no bounds checking here(!)
    void movePlayer(char dir){
      switch(dir){
        case 'w':
          if(player.first > 1){
            player.first--;
          }
          break;
        case 'a':
          if(player.second > 1){
            player.second--;
          }
          break;
        case 's':
          if(player.first < height-1){
            player.first++;
          }
          break;
        case 'd':
          if(player.second < width-1){
            player.second++;
          }
          break;
      }
    }

    /*
     * unleash the hounds.
     *
     * BFS from the player to the monsters. When a path is found, the
     * monster moves to the node closest to the player (in manhattan distance).
     *
     */
    void moveMonsters(){
      //std::map<std::pair<int,int>, std::pair<int,int>> p; // could be used but not needed
      std::map<std::pair<int,int>, color_t> colors;
      std::queue<std::pair<int,int>> Q;

      d.clear(); // start fresh

      for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
          colors[std::make_pair(i,j)] = white;
        }
      }

      // only one for now
      // will be the start of bfs
      std::pair<int,int> monster = monsters[0];
      std::pair<int,int> tmp;

      d[player] = 0;

      Q.push(player);

      while(!Q.empty()){
        auto u = Q.front();
        Q.pop();
        // bias is introduced here by searching in a left->right, top->bottom way.
        // When there are multiple shortest paths, the monster will move north over
        // south, which may be further away in straight-line distance
        // To fix, better to use an actual list of edges (rather than abusing the
        // grid-structure) and prioritize edges by smallest euclidean distance to the
        // player. This would be essentially what is known as an "A*" (pronounced 
        // "ay star" search).
        for(int row=u.first-1; row<u.first+2; row++){
          for(int col=u.second-1; col<u.second+2; col++){
            tmp = std::make_pair(row, col);
            if( cells[row][col] != wall && u != tmp ){ // don't count walls
              if(colors[tmp] == white){ // if unexplored
                if( tmp == monster ){
                  // monster found a path to the player.
                  // Instead of using parent pointers, just move the monster there
                  // TODO: need to adapt this logic (don't just return) for more than one monster
                  monsters[0] = u;
                  return;
                }
                d[tmp] = d[u] + 1;
                colors[tmp] = gray;
                Q.push(tmp);
              }
            }
          }
        }
      }
    }
};

int main(){
  GameGrid g;
  char choice;
  g.render();
  while(true){
    std::cout << "Enter movement (wasd): ";
    std::cin >> choice;
    g.handle(choice);
  }
  return 0;
}