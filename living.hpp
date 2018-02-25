//
//  living.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 14/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//
#ifndef living_h
#define living_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <random>
#include "item.h"
#include "spell.hpp"

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
    virtual string who() =0;

    bool isAlive();
    void ressurect();
};




/*********************** HERO ***********************/
class Hero : public Living
{

public:

    int r_co;
    int c_co;

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

    std::vector<Weapon * > Weapons;
    std::vector<Armor * >  Armour;
    std::vector<Potion * > Potions;
    std::vector<Icespell * > Icespells;
    std::vector<Firespell * > Firespells;
    std::vector<Lightingspell * > Lightingspells;

    void add_weapon(Weapon *);
    void add_armor(Armor *);
    void add_potion(Potion *);
    void add_icespell(Icespell *);
    void add_firespell(Firespell *);
    void add_lightingspell(Lightingspell *);

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
    int do_dmg(class Monster*);
    int accept_dmg(class Monster*);

    void accept_gold(class Monster*);
    void accept_exp(class Monster*);
    void attack(class Monster*, int times=999999);

    virtual void level_up();

    // Helper functions
    int get_dodge_chance();
    void print_stats();
    string who();
};




/*********************** WARRIOR ***********************/
class Warrior : public Hero
{
public:
    Warrior(string nm="Brave Warrior", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=20, int mon=1000, int exp=0) : Hero(nm, lv, hlth, man, str, dex, ag, mon, exp)
    {
        hero_type = "Warrior";
    }

    ~Warrior()
    {
    }

    void level_up();
};




/*********************** SORCERER ***********************/
class Sorcerer : public Hero
{
public:
    Sorcerer(string nm="Clever Sorcerer", int lv=1,int hlth=100, int man=100, int str=30, int dex=30, int ag=20, int mon=1000,
             int exp=0) : Hero(nm, lv, hlth, man, str, dex, ag, mon, exp)
    {
        hero_type = "Sorcerer";

    }

    ~Sorcerer()
    {
    }

    void level_up();
};




/*********************** PALADIN ***********************/
class Paladin : public Hero
{
public:
    Paladin(string nm="Fierce Paladin", int lv=1,int hlth=100, int man=100, int str=50, int dex=30, int ag=10, int mon=1000,
            int exp=0) : Hero(nm, lv, hlth, man, str, dex, ag, mon, exp)
    {
        hero_type = "Paladin";
    }

    ~Paladin()
    {
    }

    void level_up();
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
        defence = def + 5*sqrt((double)level);
        miss_chance = miss;
        kill_exp = level*10;
        kill_gold = level*50;
    }

    ~Monster()
    { }


    int accept_dmg(int amount);
    void do_dmg(Hero*);
    void print_stats();
    string who();
};




/*********************** DRAGON ***********************/
class Dragon : public Monster
{
public:
    Dragon(string nm="White Dragon", int lvl=1, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
    {
        monster_type = "Dragon";
    }

    ~Dragon()
    {
    }

};




/*********************** EXOSCELETON ***********************/
class Exosceleton : public Monster
{
public:
    Exosceleton(string nm="Crispy Exo", int lvl=1, int hlth=50, int dmin=5, int dmax=10, int def=30, int miss=10) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
    {
        monster_type = "Exosceleton";
    }

    ~Exosceleton()
    {
    }

};




/*********************** SPIRIT ***********************/
class Spirit : public Monster
{
public:
    Spirit(string nm="Semi-Visible Spirit", int lvl=1, int hlth=50, int dmin=5, int dmax=10, int def=10, int miss=40) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
    {
        monster_type = "Spirit";
    }

    ~Spirit()
    {
    }

};

#endif
