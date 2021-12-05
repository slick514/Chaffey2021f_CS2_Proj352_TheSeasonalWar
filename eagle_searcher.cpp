//
// Created by Justin Gries on 12/5/2021.
//

#include "eagle_searcher.h"


EagleSearcher::EagleSearcher(EagleSearcher::state** &grid, const short size) {
    this->size = size;
    this->grid = grid;
    find_eagles();
}


void EagleSearcher::find_eagles() {
    for(short i = 0; i < this->size; i++){
        for(short j = 0; j < this->size; j++){
            if(this->grid[i][j] == eagle) {
                this->found_eagles++;
                do_depth_search(i, j);
            }else this->grid[i][j] = searched;
        }
    }
}


void EagleSearcher::do_depth_search(short row, short col) {
    this->grid[row][col] = searched;

    // filter for edge-cases
    short low_i = ( row == 0) ? 0 : row - 1;
    short high_i = ( row == size - 1) ? size - 1 : row + 1;
    short low_j = ( col == 0) ? 0 : col - 1;
    short high_j = ( col == size - 1) ? size - 1 : col + 1;

    // search all surrounding cells
    for(int i = low_i; i <= high_i; i++){
        for(int j = low_j; j <= high_j; j++){
            if(this->grid[i][j] == eagle)
                do_depth_search(i, j);
            else
                this->grid[i][j] = searched;
        }
    }
}
