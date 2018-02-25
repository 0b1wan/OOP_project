//
//  game.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//
#ifndef game_h
#define game_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include "grid.hpp"
#include "living.hpp"
#include "item.h"
#include "spell.hpp"
#include "market.h"

using namespace std;


class Game
{
public:

    int grid_r;
    int grid_c;

    int total_Heros;


    class Grid* theGrid;
    vector<class Hero * > theHeros;
    Market * theMarket;

    Game(int, int);
    ~Game();

    // New Heros
    int add_Hero_Warrior(int r=0, int c=0,string nm="Genghis Khan", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=20, int mon=1000, int exp=0);

    int add_Hero_Sorcerer(int r=0, int c=0,string nm="Magic Mike", int lv=1,int hlth=100, int man=100, int str=30, int dex=30, int ag=20, int mon=1000, int exp=0);

    int add_Hero_Paladin(int r=0, int c=0,string nm="Arthur The Great", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=10, int mon=1000, int exp=0);

    // New Monsters
    int add_Monster_Dragon(int r, int c, string nm="Fire Spitter", int lvl=1, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10);

    int add_Monster_Spirit(int r, int c, string nm="The 13th God", int lvl=1, int hlth=50, int dmin=10,int dmax=15, int def=10, int miss=10);

    int add_Monster_Exosceleton(int r, int c, string nm="Bone Cracker", int lvl=1, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10);

    void begin();
    bool showPossibleActions();
    void showHerosExpanded();
    void askToMoveHeros();
    void move_heros(string direction);
    void surprise(vector<Hero * >);
    void foundMarket();
    bool checkHerosAlive();
    void printweparray();
    void printarmarray();
    void printpotarray();
    void printicearray();
    void printfirarray();
    void printligarray();
    void goShopping();
    void printinventory();

    void heal_heros();

    class Monster* randMonster(Hero *);
};

#endif
