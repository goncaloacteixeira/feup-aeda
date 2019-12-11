#ifndef MAZE_H
#define MAZE_H

#include "disjointSets.h"

class Maze {
    DisjointSets maze;
    int nrows=0;
    int ncols=0;
    vector<pair<int,int>> noWalls;
    vector<int> getNeighbours(int x) const;
public:
    Maze(int rows, int cols);
    void buildRandomMaze();
    DisjointSets getSets() const;
    void printMaze() const;
};

#endif
