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

using namespace std;

class Block
{
public:

    string block_type;
    int row;
    int column;

    vector<class Hero*> heros;


    Block(int r, int c) {
        row = r;
        column = c;
    };
    ~Block() {} ;

    bool hasHeros();
};

class Common : public Block
{
public:

    Common(int r, int c) : Block(r, c) {
        block_type = "Common";
    }
};


class Market : public Block
{
public:
    Market(int r, int c) : Block(r, c) {
        block_type = "Market";
    }
};

class NonAccessible : public Block
{
public:
    NonAccessible(int r, int c) : Block(r, c) {
        block_type = "NonAccessible";
    }
};

#endif /* block_h */
