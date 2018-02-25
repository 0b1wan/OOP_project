//
//  block.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//
#ifndef block_h
#define block_h

#include <iostream>
#include <string>
#include <vector>
#include "grid.hpp"
#include "living.hpp"

class Block
{
public:

    string block_type;
    int row;
    int column;

    vector<class Hero*> heros;

    Block(int r, int c, string type) {
        row = r;
        column = c;
        block_type = type;
    };
    ~Block() {;}

    bool hasHeros();
};

#endif /* block_h */
