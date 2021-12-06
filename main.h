//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_MAIN_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_MAIN_H
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
 * @param output_fstream
 * @param number_of_eagles
 */
void write_output(int grid_number, std::ofstream &output_fstream, int number_of_eagles);

/**
 * Creates a square grid (vectors) based on file input.
 * @param size
 * @param input_fstream
 * @return a grid consisting of a vector of char-vectors
 */
std::vector<std::vector<char>> generate_grid(int size, std::ifstream &input_fstream);
#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_MAIN_H
