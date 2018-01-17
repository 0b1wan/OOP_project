//
//  living.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 14/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#include "living.hpp"

int Hero::do_dmg(class Monster* enemy)
{

    // check fatal
    if (enemy->accept_dmg(this->strenght /* + weapon strength */) == -1)
        accept_exp(enemy);
    
    return 0;
}


int Monster::accept_dmg(int amnt)
{
    int actual = amnt - defence;
    if (actual > 0)
        set_health(-actual);

    if (get_health() <= 0)
        return -1;
    return actual;
}

int Hero::accept_exp(class Monster* enemy)
{

    cout << "GAINED EXP" << endl;
    
    return 0;
}

void Hero::print_stats()
{

    if (hero_type == "Warrior")
        cout << "--- Statistics for Warrior: " << get_name() << endl;

    else if (hero_type == "Sorcerer")
        cout << "--- Statistics for Sorcerer: " << get_name() << endl;

    else
        cout << "--- Statistics for Paladin: " << get_name() << endl;

    cout << " Level: " << get_level() << endl;
    cout <<  "Health: " << get_health() << endl;
    cout << " Damage: " << get_strenght() /* + weapon damage */ << endl;
    cout << " Experience: " << get_experience() << endl;
    cout << " Money: " << get_money() << endl;
    cout << " Strength: " << get_strenght() << endl;
    cout << " Dexterity: " << get_dexterity() << endl;
    cout << " Agility: " << get_agility() << endl << endl;

}

void Monster::print_stats()
{

    if (monster_type == "Dragon")
        cout << "--- Statistics for Dragon: " << get_name() << endl;

    else if (monster_type == "Exosceleton")
        cout << "--- Statistics for Exosceleton: " << get_name() << endl;

    else
        cout << "--- Statistics for Spirit: " << get_name() << endl;

    cout << " Level: " << get_level() << endl;
    cout << " Health: " << get_health() << endl;
    cout << " Damage: " << get_damage_min() << " - " << get_damage_max() << endl;
    cout << " Defence: " << get_defence() << endl;
    cout << " Miss Chance: " << get_miss_chance() << endl << endl;


}
