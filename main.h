//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_MAIN_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_MAIN_H

#include <ostream>

/**
 * Opens the input and output filestreams
 * @param input_fstream
 * @param output_fstream
 */
void open_filestreams(std::ifstream &input_fstream, std::ofstream &output_fstream);

/**
 * CLoses the input and output filestreams
 * @param input_fstream
 * @param output_fstream
 */
void close_filestreams(std::ifstream &input_fstream, std::ofstream &output_fstream);

/**
 * Writes the result of a search to the output file
 * @param grid_number
 * @param output_stream
 * @param number_of_eagles
 */
void write_output(int grid_number, std::basic_ostream<char> &output_stream, int number_of_eagles);

/**
 * Creates a square grid (vectors) based on file input.
 * @param size
 * @param input_fstream
 * @return a grid consisting of a vector of char-vectors
 */

/**
 *
 * @param size the length of the row
 * @param input_fstream filestream to read from
 * @return a vector of chars, representing a row of input
 */
std::vector<char> read_in_row(int size, std::ifstream &input_fstream);

/**
 * @param size
 * @param input_fstream
 * @return a grid comprised of a vector of char vectors, with all vectors of length "size"
 */
std::vector<std::vector<char>> generate_grid(int size, std::ifstream &input_fstream);

#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_MAIN_H
