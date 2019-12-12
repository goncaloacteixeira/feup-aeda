#include "maze.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <time.h>

using namespace std;

DisjointSets Maze::getSets() const {
    return maze;
}

void Maze::printMaze() const
{
    cout << endl;
    cout << setw(3) << " ";
    for (int j=0; j<ncols; j++) {
        cout << setw(6) << "______";
    }
    for (int i=0; i<nrows; i++) {
        cout << endl;
        cout << setw(3) << "|";
        for (int j=0; j<ncols-1; j++) {
            int val = i*nrows+j;
            cout << setw(3) << val<<setw(3);
            if (noWalls.empty() ||
                (find(noWalls.begin(),noWalls.end(),pair<int,int>(val,val+1)) == noWalls.end() &&
                 find(noWalls.begin(),noWalls.end(),pair<int,int>(val+1,val)) == noWalls.end())
                    )
                cout << "|";
            else
                cout <<" ";
        }
        int val = i*nrows+ncols-1;
        cout << setw(3) << val<<setw(3) << "|";
        cout <<endl;
        cout << setw(3) << " ";
        for (int j=0; j<ncols; j++) {
            int val = i*nrows+j;
            if (i<nrows-1) {
                if ( noWalls.empty() ||
                     (find(noWalls.begin(), noWalls.end(), pair<int, int>(val, val + ncols)) == noWalls.end()
                      && find(noWalls.begin(), noWalls.end(), pair<int, int>(val+ncols, val)) == noWalls.end())
                        )
                    cout << setw(6) << "______";
                else
                    cout << setw(6) << " ";
            } else
                cout << setw(6) << "______";
        }

    }
    cout <<endl << endl;
}



Maze::Maze(int rows, int cols) {
    this->ncols = cols;
    this->nrows = rows;
    this->maze = DisjointSets(cols*rows);

}

vector<int> Maze::getNeighbours(int x) const {
    vector<int> res;

    vector<vector<int>> table;
    pair<int,int> xy;
    int current = 0;
    for (int i = 0; i < nrows; i++) {
        vector<int> aux;
        for (int j = 0; j < ncols; j++) {
            if (current == x) {
                xy.first = i;
                xy.second = j;
            }
            aux.push_back(this->maze.find(current));
            current++;
        }
        table.push_back(aux);
    }


    if (xy.first == 0) {
        res.push_back(ncols+x);
    }
    else if (xy.first == nrows-1) {
        res.push_back(x-ncols);
    }
    else {
        res.push_back(ncols+x);
        res.push_back(x-ncols);
    }

    if (xy.second == 0) {
        res.push_back(x+1);
    }
    else if (xy.second == ncols - 1) {
        res.push_back(x-1);
    }
    else {
        res.push_back(x+1);
        res.push_back(x-1);
    }

    return res;
}

void Maze::buildRandomMaze() {

    srand(time(NULL));

    vector<int> neigh;
    int i = 0;
    int j;

    while (this->maze.getNumberOfSets() != 1) {
        neigh = this->getNeighbours(i);
        j = neigh[rand() % neigh.size()];

        if (this->maze.find(j) != this->maze.find(i) && this->maze.find(j) == j) {
            this->maze.unionSets(i, j);
            noWalls.emplace_back(i, j);
        }
        (i+1==ncols*nrows) ? i = 0 : i++;
    }
}
