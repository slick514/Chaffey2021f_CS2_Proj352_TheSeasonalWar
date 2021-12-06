//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#include <vector>
/**
 * This class will take a square array of values (states) and the size of the array
 * It will search that array and provide the resulting number of "eagles"
 *
 * Things to do:
 * Iterate through array
   Mark each "cell" as handled once it has been viewed
   If a cell is a "1" (eagle):
        Iterate the count
        Do a recursive, depth-first search for any surrounding 1's, marking each as handled once it has been searched
        Any additional 1's that are found during the depth-first search do not iterate the count.
 */
class EagleSearcher {
public:
    /**
     * possible pGrid-states
     */
    enum state{
        eagle = '1',
        searched = '2'
    };

    /**
     * @param search_grid The square-array to be searched. This array is altered/consumed in the process of searching.
     */
    void search(std::vector<std::vector<char>> &search_grid);

    /**
     * @returns the number of "eagles" found in the search
     */
    int get_number_of_eagles_found() const { return found_eagles;}

    /**
     *
     */
     void set_searched(int row, int col);

private:
    /**
     * Searches the pGrid for eagles (1)s and records the number of eagles found in found_eagles
     */
    void find_eagles();

    /**
     * The number of eagles found in the pGrid
     */
    int found_eagles = 0;

    /**
     * The grid (square-array) to search (grid is consumed in the process)
     * Tried doing this with arrays, but couldn't figure out how to pass in a multi-variable array. *shrugs*
     */
     std::vector<std::vector<char>> grid;

    /**
     * The size of one side of the pGrid (which is a square-array)
     */
    int size;

    /**
     * Searches the pGrid for any "eagles" (1's) that share a corner with the cell at pGrid[row][col]
     * Marks all searched squares as "searched"
     * Recursively calls itself upon encountering any other "eagle" cells
     * DOES NOT ITERATE found_eagles
     * @param row the row of the central pGrid-square
     * @param col the column of the central pGrid-square
     */
    void do_depth_search(int row, int col);

    /**
     * Prints a grid to stdout.
     * @param grid_to_print
     */
    void print_grid();
};


#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
