#include <iostream>
#include <fstream>
#include "eagle_searcher.h"
#include "main.h"

static const char *const INPUT_FILEPATH = "./input.txt";
static const char *const OUTPUT_FILEPATH = "./output.txt";

using namespace std;

/**
 * CHAFFEY COLLEGE FALL 2021; COMPSCI-2; ICPC PROJECT; GROUP 12
 * Group Members: Justin Gries & Christian Flores
 * Code link (Repl.it): https://replit.com/@JustinGries/Chaffey2021fCS2Proj352TheSeasonalWar#main.cpp
 * P352: "The seasonal war"
 * See attached description: p352.pdf
 */
int main() {
    // ---- Begin of Variable Instantiation ----
    ifstream input_fstream; // input stream to bring info from input file
    ofstream output_fstream; // output stream to write info to the output file
    int grid_count = 0; // keeps track of the number of grids/arrays that have been parsed/analyzed
    int size; // will hold the size (side-length) of each square-data_structure (Max = 25)
    EagleSearcher searcher; // will do the lifting for data_structure analysis
    string input_line; // will hold each line as it is read in from the input stream
    struct EagleSearcher::eagle_grid grid; // will hold each parsed data_structure
    int found_eagles; // will hold the number of found eagles for each iteration.
    //---- End of Variable Instantiation ----

    open_filestreams(input_fstream, output_fstream); // opens both file-streams

    while(getline(input_fstream, input_line)){ // while there are more lines of input...
        grid_count++; // iterate the grid/array-count.
        size = (int)stoi(input_line); // read in the size of the subsequent square (size x size) array.

        // create a square grid/array from the next "size" lines of input
        grid = EagleSearcher::generate_grid(size, input_fstream);

        found_eagles = searcher.search(grid); // search the grid for "eagles"

        // write the output to the output file
        EagleSearcher::write_output(grid_count, output_fstream, found_eagles);

        // write the output to stdout
        EagleSearcher::write_output(grid_count, cout, found_eagles);
    }
    close_filestreams(input_fstream, output_fstream); // close the input and output file-streams;
    return 0;
}


void close_filestreams(std::ifstream &in_stream, std::ofstream &out_stream) {
    in_stream.close();
    out_stream.close();
}


void open_filestreams(std::ifstream &in_stream, std::ofstream &out_stream) {
    in_stream.open(INPUT_FILEPATH);
    out_stream.open(OUTPUT_FILEPATH);
}