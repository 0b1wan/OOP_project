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

using namespace std;

class Textbox
{
public:

    string box_type;
    int lines;
    vector<string> text;

    Textbox(vector<string>, string srt = "Default");
};

class Map
{
public:
    int r_elements;
    int c_elements;
    vector<vector<class Textbox*>> textbox;

    void add_textbox(class Textbox*, int charLimit = -1, bool newline = false);
    int lineLength(int lineNumber);
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
    class Textbox* Space;
    class Textbox* TripleSpace;
    class Textbox* Newline;
    class Textbox* MarketBlockWTHeros;


    // Basic Visual square
    Map() {
        r_elements = 0;
        c_elements =0;
        HorizontalBlock1 =  new Textbox({"+------"}, "Build");
        HorizontalBlock2 =  new Textbox({"-------"}, "Build");
        HorizontalBlock3 =  new Textbox({"-------+"}, "Build");
        HorizontalBlock4 =  new Textbox({"|------"}, "Build");
        HorizontalBlock5 =  new Textbox({"+------|"}, "Build");
        VerticalBlock =     new Textbox({"|", "|", "|"}, "Build");
        EmptyBlock =        new Textbox({"      ", "      ", "      "}, "Common");
        MarketBlock =       new Textbox({"      ", "Market", "      "}, "Market");
        MarketBlockWTHeros =new Textbox({"xHeros", "~~IN~~", "Market"}, "MarketWHeros");
        NonAccessibleBlock =new Textbox({"XXXXXX", "XXXXXX", "XXXXXX"}, "NonAccessible");
        Space =             new Textbox({" "}, "Space");
        TripleSpace =       new Textbox({" ", " ", " "}, "Space");
        Newline =           new Textbox({"\n"}, "Newline");

    }

    class Textbox* HerosBlock(vector<class Hero*>);
};


class Grid
{
private:
    int createVisualMap();
    int updateVisualMap();

public:
    class Block *** square;
    class Map* theMap;
    int columns;
    int rows;

    Grid(int, int);
    ~Grid();

    void showMap();


    // New square
    int add_Market(int, int);
    int add_NonAccessible(int, int);

};

#endif
