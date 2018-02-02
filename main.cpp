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

    class Game* mygame = new Game(5, 15);

    mygame->begin();

    mygame->theHeros[0]->print_stats();
    
    exit(0);

    return 0;
}
