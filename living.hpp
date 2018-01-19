//
//  living.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 14/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#ifndef living_hpp
#define living_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <random>

using namespace std;



/*********************** LIVING ***********************/
class Living
{
public:
    string name;

    int level;
    const int max_level;
    int health;
    int max_health;

    Living(string nm, int lv , int hlth) : max_level(21)
    {
        name = nm;
        level = lv;
        health = hlth + (lv*100);
        max_health = health;
    }

    ~Living()
    { }

    virtual void print_stats() =0;
    bool isAlive();
    void ressurect();
};




/*********************** HERO ***********************/
class Hero : public Living
{

public:

    int mana;
    int max_mana;

    int strenght;
    int dexterity;
    int agility;
    int gold;
    int experience;
    int levelup_experience;

    int levelup_exp_modifier;
    int levelup_atrb_modifier;
    string hero_type;

    // std::vector<Weapon> Weapons;
    // std::vector<Armor>  Armour;
    // std::vector<Potions> Potions;
    // std::vector<void*> inventory;

    Hero(string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon,
         int exp) : Living(nm, lv, hlth)
    {
        level = lv;
        max_mana = man + man*level;
        mana = max_mana;
        strenght = str + (0.1)*str*level;
        dexterity = dex + (0.1)*dex*level;
        agility = ag + (0.1)*ag*level;
        gold = mon;
        experience = exp;
        levelup_exp_modifier = 25;
        levelup_experience = levelup_exp_modifier*level;
        levelup_atrb_modifier = 10;
    }

    ~Hero()
    { }

    // Main functions
    int  do_dmg(class Monster*);
    int accept_dmg(class Monster*);

    void accept_exp(class Monster*);
    void attack(class Monster*, int times=999999);

    // Helper functions
    virtual void level_up();
    void print_stats();
};




/*********************** WARRIOR ***********************/
class Warrior : public Hero
{
public:
    Warrior(string nm="Brave Warrior", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=20, int mon=1000,
            int exp=0) : Hero(nm, lv, hlth, man, str, dex, ag, mon, exp)
    {
        hero_type = "Warrior";
#ifdef _DEBUG
        cout << "Just constructed a Warrior" << endl;
#endif
    }

    ~Warrior()
    {
#ifdef _DEBUG
        cout << "Just destroyed a Warrior" << endl;
#endif
    }

    void level_up();
};




/*********************** SORCERER ***********************/
class Sorcerer : public Hero
{
public:
    Sorcerer(string nm="Clever Sorcerer", int lv=1,int hlth=100, int man=100, int str=30, int dex=20, int ag=20, int mon=1000,
             int exp=0) : Hero(nm, lv, hlth, man, str, dex, ag, mon, exp)
    {
        hero_type = "Sorcerer";

#ifdef _DEBUG
        cout << "Just constructed a Sorcerer" << endl;
#endif
    }

    ~Sorcerer()
    {
#ifdef _DEBUG
        cout << "Just destroyed a Sorcerer" << endl;
#endif
    }

};




/*********************** PALADIN ***********************/
class Paladin : public Hero
{
public:
    Paladin(string nm="Fierce Paladin", int lv=1,int hlth=100, int man=100, int str=50, int dex=20, int ag=10, int mon=1000,
            int exp=0) : Hero(nm, lv, hlth, man, str, dex, ag, mon, exp)
    {
        hero_type = "Paladin";
#ifdef _DEBUG
        cout << "Just constructed a Paladin" << endl;
#endif
    }

    ~Paladin()
    {
#ifdef _DEBUG
        cout << "Just destroyed a Paladin" << endl;
#endif
    }
};




/*********************** MONSTER ***********************/
class Monster : public Living
{
public:
    int damage_min;
    int damage_max;
    int defence;
    int miss_chance;

    int kill_exp;
    int kill_gold;

    string monster_type;

    Monster(string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) : Living(nm, lvl, hlth)
    {
        damage_max = dmax + 3*dmax*sqrt((double)level);
        damage_min = dmin + dmax*sqrt((double)level);
        defence = def + def*sqrt((double)level);
        miss_chance = miss;
        kill_exp = level*10;
        kill_gold = level*20;
    }

    ~Monster()
    { }


    int accept_dmg(int amount);
    void do_dmg(Hero*);
    void print_stats();
};




/*********************** DRAGON ***********************/
class Dragon : public Monster
{
public:
    Dragon(string nm="White Dragon", int lvl=1, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
    {
        monster_type = "Dragon";
#ifdef _DEBUG
        cout << "Just constructed a Dragon" << endl;
#endif
    }

    ~Dragon()
    {
#ifdef _DEBUG
        cout << "Just destroyed a Dragon" << endl;
#endif
    }

};




/*********************** EXOSCELETON ***********************/
class Exosceleton : public Monster
{
public:
    Exosceleton(string nm="Crispy Exo", int lvl=1, int hlth=50, int dmin=5, int dmax=10, int def=30, int miss=10) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
    {
        monster_type = "Exosceleton";
#ifdef _DEBUG
        cout << "Just constructed an Exosceleton" << endl;
#endif
    }

    ~Exosceleton()
    {
#ifdef _DEBUG
        cout << "Just destroyed an Exosceleton" << endl;
#endif
    }

};




/*********************** SPIRIT ***********************/
class Spirit : public Monster
{
public:
    Spirit(string nm="Semi-Visible Spirit", int lvl=1, int hlth=50, int dmin=5, int dmax=10, int def=10, int miss=40) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
    {
        monster_type = "Spirit";
#ifdef _DEBUG
        cout << "Just constructed a Spirit" << endl;
#endif
    }

    ~Spirit()
    {
#ifdef _DEBUG
        cout << "Just destroyed a Spirit" << endl;
#endif
    }

};


#endif /* living_hpp */
