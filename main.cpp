//
//  main.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos & Giannis Mystakidis on 14/01/2018.
//  Copyright © 2018 Zulufox. All rights reserved.
//

//#define _DEBUG

#include "game.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    srand(((unsigned int)time(NULL)));

    class Game* mygame = new Game(6, 10);


    mygame->begin();

    return 0;
}


