//
//  living.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 14/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//
#include "living.hpp"

/**************************** LIVING FUNCTIONS ****************************/
/**************************************************************************/

bool Living::isAlive()
{
    return (health > 0);
}



void Living::ressurect() {
    health = max_health;
}



/**************************** HERO FUNCTIONS ****************************/
/************************************************************************/

void Hero::attack(class Monster* enemy, int times)
{
    if (!enemy->isAlive() || !this->isAlive())
        return;
    cout << " --- FIGHT: " << who() << " vs " << enemy->who() << " ---" << endl;
    while((times-- > 0) && enemy->isAlive() && this->isAlive()) {
        do_dmg(enemy);
        enemy->do_dmg(this);
    }
    if (isAlive())
        cout << " --- WINNER: " << who() << " ---"  << endl << endl;
    else
        cout << " --- WINNER: " << enemy->who() << " ---" << endl << endl;
}



int Hero::do_dmg(class Monster* enemy)
{
    if (!enemy->isAlive() || !this->isAlive())
        return -1;

    // Do damage to monster
    {
        int dmg = enemy->accept_dmg(this->strenght /* + weapon strength */);
        if (dmg == -1)
        {
            cout << enemy->who() << " was killed" << endl;
            cout << who() << " earned " << enemy->kill_exp << " exp" << endl;
            accept_exp(enemy);
            accept_gold(enemy);
        }
        else if (dmg == 0)
            cout << enemy->who() << " dodged an attack" << endl;
        else
            cout << who() << " -> " << enemy->who() << " " << dmg << " damage" << endl;
    }

    if (!enemy->isAlive() || !this->isAlive())
        return -1;

    // Accept damage from monster
    {
        int dmg = accept_dmg(enemy);
        if (dmg == -1)
            cout << who() << " was killed by a " << enemy->monster_type << endl;
        else if (dmg == 0)
            cout << who() << " dodged an attack" << endl;
        else
            cout << enemy->who() << " -> " << who() << " " << dmg << " damage" << endl;
    }
    return 0;
}

int Hero::accept_dmg(class Monster* enemy)
{
    if (health <= 0)
        return -1;
    // Dodge increases as agility increases, maximum dodge chance is 90%
    int dodge = rand() % 100 + 1;
    int chance = get_dodge_chance();
    dodge = (dodge <= chance);

    if (dodge)
        return 0;
    else
    {
        int damage = rand() % (enemy->damage_max - enemy->damage_min) + enemy->damage_min;
        health -= damage;
        if (!isAlive())
            return -1;
        return damage;
    }
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



void Hero::accept_gold(class Monster* enemy) {
    gold += enemy->kill_gold;
}



void Hero::print_stats()
{
    cout << endl;
    if (hero_type == "Warrior")
        cout << "--- Statistics for Warrior: " << name;

    else if (hero_type == "Sorcerer")
        cout << "--- Statistics for Sorcerer: " << name;

    else
        cout << "--- Statistics for Paladin: " << name;

    if (!isAlive())
        cout << " (Dead)" << endl;
    else
        cout << endl;

    cout << " Level: " << level << endl;
    cout << " Health: " << health << "/" << max_health  << " (" << (int)(((float)health/max_health)*100) << "%)" << endl;
    cout << " Mana: " << mana << "/" << max_mana << " (" << (int)(((float)mana/max_mana)*100) << "%)" << endl;
    cout << " Damage: " << strenght /* + weapon damage */ << endl;
    cout << " Experience: " << experience << "/" << levelup_experience  << " (" << (int)(((float)experience/levelup_experience)*100) << "%)" << endl;
    cout << " Gold: " << gold << endl;
    cout << " Strength: " << strenght << endl;
    cout << " Dexterity: " << dexterity << endl;
    cout << " Agility: " << agility << " (" << get_dodge_chance() << "%)" << endl << endl;
}

string Hero::who() {
    return hero_type + "(" + name + ")";
}

int Hero::get_dodge_chance() {
    int chance = 0.01*agility*agility;
    if (chance > 90)
        return 90;
    else
        return chance;
}



void Hero::level_up()
{
    level += 1;
    levelup_experience = level*levelup_exp_modifier;
    cout << who() <<  " is now level " << level << endl;
}




void Warrior::level_up()
{
    max_health += 100;
    health = max_health;
    strenght += 20;
    dexterity += 10;
    agility += 15;
    Hero::level_up();
}

void Sorcerer::level_up()
{
    max_health += 100;
    health = max_health;
    strenght += 10;
    dexterity += 15;
    agility += 15;
    Hero::level_up();
}

void Paladin::level_up()
{
    max_health += 100;
    health = max_health;
    strenght += 20;
    dexterity += 15;
    agility += 10;
    Hero::level_up();
}


void Hero::heal() {
    if (health < max_health)
        health += health*0.1;
    if (health > max_health)
        health = max_health;
}



/**************************** MONSTER FUNCTIONS ****************************/
/***************************************************************************/



void Monster::do_dmg(class Hero* enemy)
{}

int Monster::accept_dmg(int amnt)
{
    if (!isAlive())
        return -1;
    int actual = amnt - defence;
    if (actual > 0)
        this->health -= actual;

    if (!isAlive()) {
        return -1;
    }
    if (actual < 0)
        actual = 0;
    return actual;
}




void Monster::print_stats()
{
    cout << endl;
    if (monster_type == "Dragon")
        cout << "--- Statistics for Dragon: " << name ;

    else if (monster_type == "Exosceleton")
        cout << "--- Statistics for Exosceleton: " << name;

    else
        cout << "--- Statistics for Spirit: " << name;

    if (!isAlive())
        cout << " (Dead)" << endl;
    else
        cout << endl;
    cout << " Level: " << level << endl;
    cout << " Health: " << health << "/" << max_health << " (" << (int)(((float)health/max_health)*100) << "%)" << endl;
    cout << " Damage: " << damage_min << " - " << damage_max << endl;
    cout << " Defence: " << defence << endl;
    cout << " Dodge: " << miss_chance << "%" << endl;
    cout << " Kill Exp: " << kill_exp << endl;
    cout << " Kill Gold: " << kill_gold << endl << endl;

}


string Monster::who() {
    return monster_type + "(" + name + ")";
}

void Hero::add_weapon(Weapon * a){
  Weapons.push_back(a);
}
void Hero::add_armor(Armor * a){
  Armour.push_back(a);
}
void Hero::add_potion(Potion * a){
  Potions.push_back(a);
}
void Hero::add_icespell(Icespell * a){
  Icespells.push_back(a);
}
void Hero::add_firespell(Firespell * a){
  Firespells.push_back(a);
}
void Hero::add_lightingspell(Lightingspell * a){
  Lightingspells.push_back(a);
}
void Hero::remove_weapon(int a){
  Weapons.erase(Weapons.begin()+a);
}
void Hero::remove_armor(int a){
  Armour.erase(Armour.begin()+a);
}
void Hero::remove_potion(int a){
  Potions.erase(Potions.begin()+a);
}
void Hero::remove_icespell(int a){
  Icespells.erase(Icespells.begin()+a);
}
void Hero::remove_firespell(int a){
  Firespells.erase(Firespells.begin()+a);
}
void Hero::remove_lightingspell(int a){
  Lightingspells.erase(Lightingspells.begin()+a);
}
void Hero::remove_gold(int a){
  gold=gold-a;
}
void Hero::add_gold(int a){
  gold=gold+a;
}

