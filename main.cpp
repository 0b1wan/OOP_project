//
//  main.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos & Giannis Mystakidis on 14/01/2018.
//  Copyright © 2018 Zulufox. All rights reserved.
//

//#define _DEBUG

#include <iostream>
#include "living.hpp"
#include "item.cpp"
#include "game.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    srand(((unsigned int)time(NULL)));

    class Game* mygame = new Game(5, 5);

    mygame->add_Hero_Warrior(0,0, "Jesus", 5);
    mygame->add_Hero_Sorcerer(0,0);
    mygame->add_Hero_Paladin(0,0);

    mygame->add_Monster_Dragon(3, 3, "Josh" , 5);
    mygame->theGrid->add_Market(1, 1);
    mygame->theGrid->add_Market(4, 3);
    mygame->theGrid->add_Market(3, 4);


    mygame->theGrid->add_NonAccessible(4, 4);

    mygame->theHeros[0]->attack(mygame->theMonsters[0]);
    mygame->theHeros[0]->print_stats();
    mygame->theMonsters[0]->print_stats();



    mygame->move_heros("left");


    mygame->theGrid->showMap();

    cout << endl;
    return 0;
}
