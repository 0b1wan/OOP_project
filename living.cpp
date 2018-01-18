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
    {
        cout << enemy->monster_type << "(" << enemy->name << ") was killed" << endl;
        cout << name << " earned " << enemy->kill_exp << " exp" << endl;
        accept_exp(enemy);
        
    }

    return 0;
}

void Hero::attack(class Monster* enemy, int times)
{
    while((times-- > 0) && (enemy->health > 0)) {
        do_dmg(enemy);
    }
}


int Monster::accept_dmg(int amnt)
{
    int actual = amnt - defence;
    if (actual > 0)
        this->health -= actual;

    if (health <= 0) {
        return -1;
    }
    return actual;
}

void Hero::accept_exp(class Monster* enemy)
{
    experience += enemy->kill_exp;
    // check if level-up
    while (experience >= levelup_experience) {
        experience -= levelup_experience;
        level_up();
    }
}

void Hero::level_up()
{
    level += 1;
    levelup_experience = level*levelup_exp_modifier;
    cout << hero_type << "(" << name <<  ") is now level " << level << endl;
}

void Warrior::level_up()
{
    max_health += 100;
    health = max_health;
    strenght += 15;
    dexterity += 10;
    agility += 15;
    Hero::level_up();
}

void Hero::print_stats()
{
    cout << endl;
    if (hero_type == "Warrior")
        cout << "--- Statistics for Warrior: " << name << endl;

    else if (hero_type == "Sorcerer")
        cout << "--- Statistics for Sorcerer: " << name << endl;

    else
        cout << "--- Statistics for Paladin: " << name << endl;

    cout << " Level: " << level << endl;
    cout << " Health: " << health << "/" << max_health << endl;
    cout << " Damage: " << strenght /* + weapon damage */ << endl;
    cout << " Experience: " << experience << "/" << levelup_experience << endl;
    cout << " Gold: " << gold << endl;
    cout << " Strength: " << strenght << endl;
    cout << " Dexterity: " << dexterity << endl;
    cout << " Agility: " << agility << endl << endl;

}

void Monster::print_stats()
{
    cout << endl;
    if (monster_type == "Dragon")
        cout << "--- Statistics for Dragon: " << name << endl;

    else if (monster_type == "Exosceleton")
        cout << "--- Statistics for Exosceleton: " << name << endl;

    else
        cout << "--- Statistics for Spirit: " << name << endl;

    cout << " Level: " << level << endl;
    cout << " Health: " << health << "/" << max_health << endl;
    cout << " Damage: " << damage_min << " - " << damage_max << endl;
    cout << " Defence: " << defence << endl;
    cout << " Miss Chance: " << miss_chance << endl;
    cout << " Kill Exp: " << kill_exp << endl << endl;

}
