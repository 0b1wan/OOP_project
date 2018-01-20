//
//  game.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#include "game.hpp"

Game::Game(int x, int y)
{
    grid_x = x;
    grid_y = y;
    total_Heros = 0;
    theGrid = new class Grid(x, y);
}

/********** ADD HEROS **********/



int Game::add_Hero_Warrior(int x, int y,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Warrior* mywarrior = new class Warrior(nm,lv,hlth,man,str,dex,ag,mon,exp);
    theHeros.push_back(mywarrior);
    theGrid->Blocks[x][y]->heros.push_back(mywarrior);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Paladin(int x, int y,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Paladin* mypaladin = new class Paladin(nm,lv,hlth,man,str,dex,ag,mon,exp);
    theHeros.push_back(mypaladin);
    theGrid->Blocks[x][y]->heros.push_back(mypaladin);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Sorcerer(int x, int y,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Sorcerer* mysorcerer = new class Sorcerer(nm,lv,hlth,man,str,dex,ag,mon,exp);
    theHeros.push_back(mysorcerer);
    theGrid->Blocks[x][y]->heros.push_back(mysorcerer);
    total_Heros++;
    return 0;
}





/********** ADD MONSTERS **********/



int Game::add_Monster_Dragon(int x, int y, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Dragon* myDragon = new class Dragon(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myDragon);
    return 0;
}


int Game::add_Monster_Spirit(int x, int y, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Spirit* mySpirit = new class Spirit(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(mySpirit);
    return 0;
}


int Game::add_Monster_Exosceleton(int x, int y, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Exosceleton* myExosceleton = new class Exosceleton(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myExosceleton);
    return 0;
}













