//
//  grid.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#ifndef grid_h
#define grid_h

#include "block.hpp"


class Grid
{
private:
    class Block *** Blocks;
    int columns;
    int rows;

public:
    Grid(int, int);
    ~Grid();

    void displaymap();

};


#endif /* grid_h */
