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
    int x_coord;
    int y_coord;
    vector<class Hero*> heros;

    Block(int x, int y) {
        x_coord = x;
        y_coord = y;
    };
    ~Block() {} ;

    bool empty();
    int heroCount();
};

class Common : public Block
{
public:

    Common(int x, int y) : Block(x, y) {
        block_type = "Common";
    }

};


class Market : public Block
{
public:
    Market(int x, int y) : Block(x, y) {
        block_type = "Market";
    }


};

class NonAccessible : public Block
{
public:
    NonAccessible(int x, int y) : Block(x, y) {
        block_type = "Non Accessible";
    }

};

#endif /* block_h */
