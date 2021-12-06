#include <iostream>
#include <fstream>
#include "eagle_searcher.h"
#include "main.h"

static const char *const INPUT_FILEPATH = "./input.txt";
static const char *const OUTPUT_FILEPATH = "./output.txt";

using namespace std;

/**
 * P352: "The seasonal war"
 * See attached description: p352.pdf
 *
 * Algorithm:
 *  Read in first line
    Parse array size, "n"
    Create 2D, square grid consisting of vectors of "n x n" size, from the next "n" lines of file input
    Call an EagleSearcher to search the grid
    Print result of array search
    If EOF is not reached, read in the next "section" and handle in similar fashion
 */
int main() {
    int grid_count = 0;
    int size;
    ifstream input_fstream;
    ofstream output_fstream;
    EagleSearcher searcher;
    string input_line;
    vector<vector<char>> grid;

    open_filestreams(input_fstream, output_fstream);

    while(getline(input_fstream, input_line)){
        grid_count++;
        size = (int)stoi(input_line);
        grid = generate_grid(size, input_fstream);
        searcher.search(grid);
        write_output(grid_count, output_fstream, searcher.get_number_of_eagles_found());
        write_output(grid_count, cout, searcher.get_number_of_eagles_found());
    }
    close_filestreams(input_fstream, output_fstream);
    return 0;
}

vector<vector<char>> generate_grid(int size, ifstream &input_fstream) {
    string line;
    vector<vector<char>> grid;
    grid.reserve(size);
    for( int i = 0; i < size; i++){
        getline(input_fstream, line);
        vector<char> row;
        row.reserve(size);
        for(int j = 0; j < size; j++){
            row.push_back(line[j]);
        }
        grid.push_back(row);
    }
    return grid;
}

void write_output(int grid_number, ostream &output_stream, int number_of_eagles) {
    output_stream << "Image number " << grid_number << " contains " ;
    output_stream << number_of_eagles << " war eagle" << ( number_of_eagles == 1 ? "" : "s") << "." << endl;
}

void close_filestreams(ifstream &input_fstream, ofstream &output_fstream) {
    input_fstream.close();
    output_fstream.close();
}

void open_filestreams(ifstream &input_fstream, ofstream &output_fstream) {
    input_fstream.open(INPUT_FILEPATH);
    output_fstream.open(OUTPUT_FILEPATH);
}