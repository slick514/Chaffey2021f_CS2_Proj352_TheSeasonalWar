//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#include <vector>
#include <ostream>

/**
 * This class will take a square grid of values (states) and the size of the grid
 * It will search that grid and provide the resulting number of "eagles"
 *
 * Things to do:
 * Iterate through grid
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
     * @param search_grid The square-grid to be searched.
     * @return the number of "eagles" located
     */
    int search(const struct eagle_grid &search_grid);

    /**
     * Writes the result of a search to the output stream
     * @param grid_number The grid number to be displayed
     * @param out_stream The output stream
     * @param number_of_eagles The number of "eagles" that were found in the grid
     */
    static void write_output(int grid_number, std::basic_ostream<char> &out_stream, int number_of_eagles);

    /**
     * @param size The number of lines to be read in, which must all by of length "size".
     * @param input_fstream Depends on the input stream's next "size" lines comprising a square-matrix of side-length
     * "size"
     * @return a "square" grid comprised of a vector of char vectors, with all vectors of length "size"
     */
    static eagle_grid generate_grid(int size, std::istream &input_fstream);

private:
    /**
     * The number of eagles found in the grid
     */
    int found_eagles = 0;

    /**
     * The grid (square-data_structure) to search.
     * Tried doing this with arrays, but couldn't figure out how to pass in a multi-variable array. *shrugs*
     */
    struct eagle_grid grid;

    /**
     * The size of one side of the (square) grid
     */
    int size = 0;

    /**
     * possible grid-states
     */
    enum state{
        eagle = '1',
        searched = '2'
    };

    /**
     * populates a list vector of characters from the next line of input
     * @param size the length of the row
     * @param input_fstream filestream to read from
     * @return a vector of chars of length "size", representing a row of input
     */
    static std::vector<char> read_in_row(int size, std::istream &input_fstream);

    /**
     * @row the row of the cell to be marked as searched
     * @col the column of the cell to be marked as searched
     */
    void set_searched(int row, int col);

    /**
     * Searches the grid for eagles (1)s and records the number of eagles found in this->found_eagles
     */
    void find_eagles();

    /**
     * Searches the grid for any "eagles" (1's) that share a corner with the cell at grid[row][col]
     * Marks all searched squares as "searched"
     * Recursively calls itself upon encountering any other "eagle" cells
     * DOES NOT ITERATE found_eagles
     * @param row the row of the central grid-square
     * @param col the column of the central grid-square
     */
    void do_depth_search(int row, int col);

    /**
     * Prints a grid to stdout.
     * @param grid_to_print
     */
    __attribute__((unused)) void print_grid();
};

#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
