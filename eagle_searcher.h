//
// Created by Justin Gries on 12/5/2021.
//

#ifndef CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
#define CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H

/**
 * This class will take a square array of values (states) and the size of the array
 * It will search that array and provide the resulting number of "eagles"
 *
 * Iterate through array
        Mark each "cell" as handled once it has been viewed
        If a cell is marked as "handled", skip it.
        If a cell is a "1" (eagle):
             Iterate the count
             Do a recursive, depth-first search for any surrounding 1's, marking each as handled once it has been
             searched
             Any other connected 1's that are found during the search do not iterate the count.
 */
class EagleSearcher {
public:
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
    void find_eagles();
    short found_eagles = 0;
    EagleSearcher::state** grid;
    short size;

    void do_depth_search(short row, short col);
};


#endif //CHAFFEY2021F_CS2_PROJ352_THESEASONALWAR_EAGLE_SEARCHER_H
