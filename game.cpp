//
//  game.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#include "game.hpp"

Game::Game(int r, int c)
{
    grid_c = c;
    grid_r = r;
    total_Heros = 0;
    theGrid = new class Grid(r, c);
}

/********** ADD HEROS **********/



int Game::add_Hero_Warrior(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Warrior* mywarrior = new class Warrior(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mywarrior->r_co = r;
    mywarrior->c_co = c;
    theHeros.push_back(mywarrior);
    theGrid->Blocks[r][c]->heros.push_back(mywarrior);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Paladin(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Paladin* mypaladin = new class Paladin(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mypaladin->r_co = r;
    mypaladin->c_co = c;
    theHeros.push_back(mypaladin);
    theGrid->Blocks[r][c]->heros.push_back(mypaladin);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Sorcerer(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Sorcerer* mysorcerer = new class Sorcerer(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mysorcerer->r_co = r;
    mysorcerer->c_co = c;
    theHeros.push_back(mysorcerer);
    theGrid->Blocks[r][c]->heros.push_back(mysorcerer);
    total_Heros++;
    return 0;
}





/********** ADD MONSTERS **********/



int Game::add_Monster_Dragon(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Dragon* myDragon = new class Dragon(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myDragon);
    return 0;
}


int Game::add_Monster_Spirit(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Spirit* mySpirit = new class Spirit(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(mySpirit);
    return 0;
}


int Game::add_Monster_Exosceleton(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Exosceleton* myExosceleton = new class Exosceleton(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myExosceleton);
    return 0;
}



void Game::move_heros(string direction)
{
    if ((direction == "up" ) && (theHeros[0]->r_co > 0))
    {
        theGrid->Blocks[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->r_co--;
            theGrid->Blocks[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
    }
    else if ((direction == "down") && (theHeros[0]->r_co < grid_r-1))
    {
        theGrid->Blocks[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->r_co++;
            theGrid->Blocks[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
    }
    else if ((direction == "left") && (theHeros[0]->c_co > 0))
    {
        theGrid->Blocks[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->c_co--;
            theGrid->Blocks[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
    }
    else if ((direction == "right") && (theHeros[0]->c_co < grid_c-1))
    {
        theGrid->Blocks[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
        for (int i=0; i<total_Heros; i++) {
            theHeros[i]->c_co++;
            theGrid->Blocks[theHeros[i]->r_co][theHeros[i]->c_co]->heros.push_back(theHeros[i]);
        }
    }

}










