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
    srand(((unsigned int)time(NULL)));

    Warrior BraveWarrior("Jessy", 1);
    Spirit QuietSpirit("Little Bitch");
    Dragon WhiteDragon("Some Mofo");
    Exosceleton exo("Mike");
    Dragon drago("Black Eye", 21);

    BraveWarrior.print_stats();
    QuietSpirit.print_stats();
    WhiteDragon.print_stats();
    exo.print_stats();

    BraveWarrior.attack(&WhiteDragon);
    BraveWarrior.attack(&QuietSpirit);
    BraveWarrior.attack(&exo);

    BraveWarrior.print_stats();
    drago.print_stats();

    BraveWarrior.attack(&drago);

    BraveWarrior.print_stats();

    return 0;
}
