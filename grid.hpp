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
#include "grid.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "living.hpp"

class Grid
{
public:
    class Block *** Blocks;
    int columns;
    int rows;

    Grid(int, int);
    ~Grid();

    void displayMap();

    void displayBlock(int, int);
};


#endif /* grid_h */
