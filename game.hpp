//
//  game.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <random>
#include "grid.hpp"
#include "living.hpp"
#include "block.hpp"


class Game
{
public:
    int grid_x;
    int grid_y;
    int total_Heros;



    class Grid* theGrid;
    vector<class Hero*> theHeros;
    vector<class Monster*> theMonsters;


    Game(int, int);
    ~Game();

    // New Heros
    int add_Hero_Warrior(int x=0, int y=0,string nm="Genghis Khan", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=20, int mon=1000, int exp=0);

    int add_Hero_Sorcerer(int x=0, int y=0,string nm="Magic Mike", int lv=1,int hlth=100, int man=100, int str=30, int dex=30, int ag=20, int mon=1000, int exp=0);

    int add_Hero_Paladin(int x=0, int y=0,string nm="Arthur The Great", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=10, int mon=1000, int exp=0);

    // New Monsters
    int add_Monster_Dragon(int x, int y, string nm="Fire Spitter", int lvl=1, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10);

    int add_Monster_Spirit(int x, int y, string nm="The 13th God", int lvl=1, int hlth=50, int dmin=10,int dmax=15, int def=10, int miss=10);

    int add_Monster_Exosceleton(int x, int y, string nm="Bone Cracker", int lvl=1, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10);
};






#endif /* game_hpp */
