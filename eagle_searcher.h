//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#include <vector>
#include <ostream>

/**
 * This class will take a square data_structure of values (states) and the size of the data_structure
 * It will search that data_structure and provide the resulting number of "eagles"
 *
 * Things to do:
 * Iterate through data_structure
   Mark each "cell" as handled once it has been viewed
   If a cell is a "1" (eagle):
        Iterate the count
        Do a recursive, depth-first search for any surrounding 1's, marking each as handled once it has been searched
        Any additional 1's that are found during the depth-first search do not iterate the count.
 */
class EagleSearcher {
public:
    /**
     * Encapsulates inner data-structure to preclude implementation dependency
     */
    struct eagle_grid{
        std::vector<std::vector<char>> data_structure;
    };

    /**
     * @param search_grid The square-data_structure to be searched.
     * @return the number of "eagles" located
     */
    int search(const struct eagle_grid &search_grid);

    /**
     * Writes the result of a search to the output file
     * @param grid_number
     * @param output_stream
     * @param number_of_eagles
     */
    static void write_output(int grid_number, std::basic_ostream<char> &output_stream, int number_of_eagles);

    /**
     * @param size The number of lines to be read in, which must all by of length "size".
     * @param input_fstream Depends on the input stream's next "size" lines comprising a square-matrix of side-length
     * "size"
     * @return a data_structure comprised of a vector of char vectors, with all vectors of length "size"
     */
    static eagle_grid generate_grid(int size, std::istream &input_fstream);

private:
    /**
     * The number of eagles found in the data_structure
     */
    int found_eagles = 0;

    /**
     * The data_structure (square-data_structure) to search (data_structure is consumed in the process)
     * Tried doing this with arrays, but couldn't figure out how to pass in a multi-variable data_structure. *shrugs*
     */
    struct eagle_grid grid;

    /**
     * The size of one side of the data_structure (which is a square-data_structure)
     */
    int size = 0;

    /**
     * possible data_structure-states
     */
    enum state{
        eagle = '1',
        searched = '2'
    };

    /**
     * @param size the length of the row
     * @param input_fstream filestream to read from
     * @return a vector of chars, representing a row of input
     */
    static std::vector<char> read_in_row(int size, std::istream &input_fstream);

    /**
     * @row the row of the cell to be marked as searched
     * @col the column of the cell to be marked as searched
     */
    void set_searched(int row, int col);

    /**
     * Searches the data_structure for eagles (1)s and records the number of eagles found in found_eagles
     */
    void find_eagles();

    /**
     * Searches the data_structure for any "eagles" (1's) that share a corner with the cell at data_structure[row][col]
     * Marks all searched squares as "searched"
     * Recursively calls itself upon encountering any other "eagle" cells
     * DOES NOT ITERATE found_eagles
     * @param row the row of the central data_structure-square
     * @param col the column of the central data_structure-square
     */
    void do_depth_search(int row, int col);

    /**
     * Prints a data_structure to stdout.
     * @param grid_to_print
     */
    __attribute__((unused)) void print_grid();
};

#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
