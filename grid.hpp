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
#include "game.hpp"
#include <sstream>

class Textbox
{
public:

    string box_type;
    int lines;
    vector<string> text;

    Textbox(vector<string>, string);
};

class Map
{
public:
    int r_elements;
    int c_elements;
    vector<vector<class Textbox*>> blocks;

    void add_textbox(class Textbox*, int charLimit = -1, bool newline = false);
    void show();

    class Textbox* HorizontalBlock1;
    class Textbox* HorizontalBlock2;
    class Textbox* HorizontalBlock3;
    class Textbox* HorizontalBlock4;
    class Textbox* HorizontalBlock5;
    class Textbox* VerticalBlock;
    class Textbox* EmptyBlock;
    class Textbox* MarketBlock;
    class Textbox* NonAccessibleBlock;

    // Basic Visual Blocks
    Map() {
        HorizontalBlock1 =  new Textbox({"+------"}, "Build");
        HorizontalBlock2 =  new Textbox({"-------"}, "Build");
        HorizontalBlock3 =  new Textbox({"-------+"}, "Build");
        HorizontalBlock4 =  new Textbox({"|------"}, "Build");
        HorizontalBlock5 =  new Textbox({"+------|"}, "Build");
        VerticalBlock =     new Textbox({"|", "|", "|"}, "Build");
        EmptyBlock =        new Textbox({"      ", "      ", "      "}, "Common");
        MarketBlock =       new Textbox({"      ", "Market", "      "}, "Market");
        NonAccessibleBlock =new Textbox({"XXXXXX", "XXXXXX", "XXXXXX"}, "NonAccessible");
    }

    class Textbox* HerosBlock(vector<class Hero*>);
};


class Grid
{
private:
    int createVisualMap();
    int updateVisualMap();

public:
    class Block *** Blocks;
    class Map* theMap;
    int columns;
    int rows;

    Grid(int, int);
    ~Grid();

    void showMap();


    // New Blocks
    int add_Market(int, int);
    int add_NonAccessible(int, int);

};



#endif /* grid_h */
