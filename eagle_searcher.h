//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H

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
     * possible grid-states
     */
    enum state{
        empty = 0,
        eagle = 1,
        searched = 2
    };

    /**
     * @param grid The square-array to be searched. This array is altered/consumed in the process of searching.
     * @param size The size of the square-array to be searched
     */
    EagleSearcher(EagleSearcher::state** &grid, short size);
    short get_number_of_eagles_found() const { return found_eagles;}
private:
    /**
     * Searches the grid for eagles (1)s and records the number of eagles found in found_eagles
     */
    void find_eagles();

    /**
     * The number of eagles found in the grid
     */
    short found_eagles = 0;

    /**
     * The grid (square-array) to search (grid is consumed in the process)
     */
    EagleSearcher::state** grid;

    /**
     * The size of one side of the grid (which is a square-array)
     */
    short size;

    /**
     * Searches the grid for any "eagles" (1's) that share a corner with the cell at grid[row][col]
     * Marks all searched squares as "searched"
     * Recursively calls itself upon encountering any other "eagle" cells
     * DOES NOT ITERATE found_eagles
     * @param row the row of the central grid-square
     * @param col the column of the central grid-square
     */
    void do_depth_search(short row, short col);
};


#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
