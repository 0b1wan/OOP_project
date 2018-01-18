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


using namespace std;

int main(int argc, const char * argv[]) {

    Warrior BraveWarrior("Andreas");
    Spirit QuietSpirit("Little Bitch");
    Dragon WhiteDragon("some mofo");

    WhiteDragon.print_stats();

    BraveWarrior.do_dmg(&WhiteDragon);
    BraveWarrior.do_dmg(&WhiteDragon);

    WhiteDragon.print_stats();

    return 0;
}
