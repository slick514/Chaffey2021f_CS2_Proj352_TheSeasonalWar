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
    int grid_count = 0; // keeps track of the number of grids that have been parsed/analyzed
    int size; // will hold the size (side-length) of each square-grid
    ifstream input_fstream; // input stream to bring info from input file
    ofstream output_fstream; // output stream to write info to the output file
    EagleSearcher searcher; // will do the lifting for grid analysis
    string input_line; // will hold each line as it is read in from the input stream
    vector<vector<char>> grid; // will hold each parsed grid

    open_filestreams(input_fstream, output_fstream); // opens both filestreams

    while(getline(input_fstream, input_line)){ // while there are more lines of input...
        grid_count++; // iterate the grid count.
        size = (int)stoi(input_line); // read in the size of the subsequent grid. (Max characters: 25)
        grid = generate_grid(size, input_fstream); // create a grid from the next "size" lines of input
        searcher.search(grid); // search the grid for "eagles"
        // write the output to the output file
        write_output(grid_count, output_fstream, searcher.get_number_of_eagles_found());
        // write the output to stdout
        write_output(grid_count, cout, searcher.get_number_of_eagles_found());
    }
    close_filestreams(input_fstream, output_fstream); // close the input and output filestreams;
    return 0;
}

vector<vector<char>> generate_grid(int size, ifstream &input_fstream) {

    vector<vector<char>> grid; // the grid that will be populated
    grid.reserve(size); // set the size of the grid

    // add "size" number of rows to the grid
    for( int i = 0; i < size; i++){
        vector<char> row = read_in_row(size, input_fstream); // populate a row
        grid.push_back(row); // add the row to the end of the grid that is being formed
    }

    return grid;
}

vector<char> read_in_row(int size, ifstream &input_fstream) {
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