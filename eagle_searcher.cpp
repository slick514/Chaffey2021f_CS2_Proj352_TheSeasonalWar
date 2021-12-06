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
            if( grid.data_structure.at(i).at(j) == eagle) {
                found_eagles++;
                do_depth_search(i, j);
                // print_grid();
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
            if( grid.data_structure.at(i).at(j) == eagle)
                do_depth_search(i, j);
            else
                set_searched(i, j);
        }
    }
}


void EagleSearcher::set_searched(int row, int col) {
    grid.data_structure.at(row).at(col) = searched;
}


int EagleSearcher::search(const struct eagle_grid &search_grid) {
    size = (int)search_grid.data_structure.size();
    grid.data_structure = search_grid.data_structure;
    //print_grid();
    find_eagles();
    return found_eagles;
}


__attribute__((unused)) void EagleSearcher::print_grid() {
    vector<vector<char>> arr = grid.data_structure;
    cout << endl;
    for(auto & i : grid.data_structure){
        for( int j = 0; j < arr.size(); j++){
            cout << i.at(j);
        }
        cout << endl;
    }
}


void EagleSearcher::write_output(int grid_number, ostream &out_stream, int number_of_eagles) {
    out_stream << "Image number " << grid_number << " contains " ;
    out_stream << number_of_eagles << " war eagle" << ( number_of_eagles == 1 ? "" : "s") << "." << endl;
}


EagleSearcher::eagle_grid EagleSearcher::generate_grid(int size, istream &input_fstream) {

    vector<vector<char>> array; // the data_structure that will be populated
    array.reserve(size); // set the size of the data_structure

    // add "size" number of rows to the data_structure
    for( int i = 0; i < size; i++){
        vector<char> row = read_in_row(size, input_fstream); // populate a row
        array.push_back(row); // add the row to the end of the data_structure that is being formed
    }
    struct eagle_grid g;
    g.data_structure = array;
    return g;
}


vector<char> EagleSearcher::read_in_row(int size, istream &input_fstream) {
    vector<char> row; // a row that will be populated
    row.reserve(size); // set the size of each row
    string line; // line to be read in
    getline(input_fstream, line); // read in the next line (row) of text

    // populate the row from the line of input
    for(int j = 0; j < size; j++){
        row.push_back(line[j]);
    }
    return row;
}