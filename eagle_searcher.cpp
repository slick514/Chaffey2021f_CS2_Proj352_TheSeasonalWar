//
// Created by Justin Gries on 12/5/2021.
//

#include "eagle_searcher.h"
#include <vector>
#include <iostream>

using namespace std;


void EagleSearcher::find_eagles() {
    found_eagles = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid.at(i).at(j) == eagle) {
                found_eagles++;
                do_depth_search(i, j);
                //print_grid();
            }else set_searched(i, j);
        }
    }
}


void EagleSearcher::do_depth_search(int row, int col) {
    set_searched(row, col);

    // filter for edge-cases
    int low_i = ( row == 0) ? 0 : row - 1;
    int high_i = ( row == size - 1) ? size - 1 : row + 1;
    int low_j = ( col == 0) ? 0 : col - 1;
    int high_j = ( col == size - 1) ? size - 1 : col + 1;

    // search all surrounding cells
    for(int i = low_i; i <= high_i; i++){
        for(int j = low_j; j <= high_j; j++){
            if(grid.at(i).at(j) == eagle)
                do_depth_search(i, j);
            else
                set_searched(i, j);
        }
    }
}

void EagleSearcher::set_searched(int row, int col) {
    grid.at(row).at(col) = searched;
}

void EagleSearcher::search(vector<vector<char>> &search_grid) {
    size = (int)search_grid.size();
    grid = search_grid;
    print_grid();
    find_eagles();
}

void EagleSearcher::print_grid() {
    cout << endl;
    for(auto & i : grid){
        for(int j = 0; j < grid.size(); j++){
            cout << i.at(j);
        }
        cout << endl;
    }
}
