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
    Parse data_structure size, "n"
    Create 2D, square data_structure consisting of vectors of "n x n" size, from the next "n" lines of file input
    Call an EagleSearcher to search the data_structure
    Print result of data_structure search
    If EOF is not reached, read in the next "section" and handle in similar fashion
 */
int main() {
    ifstream input_fstream; // input stream to bring info from input file
    ofstream output_fstream; // output stream to write info to the output file
    int grid_count = 0; // keeps track of the number of grids that have been parsed/analyzed
    int size; // will hold the size (side-length) of each square-data_structure
    EagleSearcher searcher; // will do the lifting for data_structure analysis
    string input_line; // will hold each line as it is read in from the input stream
    struct EagleSearcher::eagle_grid grid; // will hold each parsed data_structure
    int found_eagles; // will hold the number of found eagles for each iteration.

    open_filestreams(input_fstream, output_fstream); // opens both file-streams

    while(getline(input_fstream, input_line)){ // while there are more lines of input...
        grid_count++; // iterate the data_structure count.
        size = (int)stoi(input_line); // read in the size of the subsequent data_structure. (Max characters: 25)

        // create a data_structure from the next "size" lines of input
        grid = EagleSearcher::generate_grid(size, input_fstream);

        found_eagles = searcher.search(grid); // search the data_structure for "eagles"

        // write the output to the output file
        EagleSearcher::write_output(grid_count, output_fstream, found_eagles);

        // write the output to stdout
        EagleSearcher::write_output(grid_count, cout, found_eagles);
    }
    close_filestreams(input_fstream, output_fstream); // close the input and output file-streams;
    return 0;
}

void close_filestreams(ifstream &input_fstream, ofstream &output_fstream) {
    input_fstream.close();
    output_fstream.close();
}

void open_filestreams(ifstream &input_fstream, ofstream &output_fstream) {
    input_fstream.open(INPUT_FILEPATH);
    output_fstream.open(OUTPUT_FILEPATH);
}