#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istream;

#include <iomanip>

#include <map>

#include <queue>
using std::priority_queue;

#include <set>

#include <vector>

#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;


#include <cstdlib>
using std::exit;

#include <vector>

#include<tuple>
using std::tuple;

#include "Grid.h"

//Declare your maze grid and path vector
Grid maze;
std::vector<tuple<int, int, int> > path;

bool find_path(int x, int y, int z){

    //get dimensions of your grid
    int n_rows = maze.height();
    int n_columns = maze.width();
    int n_levels = maze.depth();

    //Check if your move is invalid due to not being in the grid
    if(x < 0|| y < 0|| z < 0|| x >= n_rows || y >= n_columns || z >= n_levels){
        return false;
    }

    //Check if your move is invalid because it's either been visited or you can't visit there
    if (maze.at(x,y,z) != 1){
        return false;
}
    //check if you reached the end of the grid
    if(x == n_rows - 1 && y == n_columns - 1 && z == n_levels - 1){
        path.push_back({x,y,z});
        return true;
    }

    //mark the current coordinate as visited and add the coordinate to your path vector
    maze.at(x,y,z) = 2;
    path.push_back({x,y,z});

    //check up, down, left, right, in and out of the grid
    if(find_path(x+1, y, z)||
    find_path(x-1, y, z)||
    find_path(x, y+1, z)||
    find_path(x, y-1, z)||
    find_path(x, y, z+1)||
    find_path(x, y, z-1)){
        return true;
    }

    //if there are no valid paths, backtrack and mark the stop as unvisited, remove that from your path vector
    maze.at(x,y,z) = 1;
    path.pop_back();
    return false;

}


int main(int argc, char* argv[]) {

    //read in your maze and declare it as a grid
    std::ifstream in_file(argv[1]);
    in_file >> maze;
    in_file.close();

    //open your outfile for writing and recurse through the maze
    std::ofstream out(argv[2]);
    if(find_path(0, 0, 0)){
        out << "SOLUTION" << endl;

        //print the solutions to the maze if a valid path is found
        for(auto[x,y,z] : path){
            out << x << " " << y << " " << z << endl;
        }
    }
    //otherwise declare that a valid path was not found
    else{
        out << "NO SOLUTION" << endl;
    }

    return 0;
}
