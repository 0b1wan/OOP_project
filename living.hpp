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

using namespace std;



/*********************** LIVING ***********************/
class Living
{
protected:
    string name;

    int level;
    int health;

public:
    Living(string nm, int lv , int hlth)
    {
        name = nm;
        level = lv;
        health = hlth + (lv*100);
    }

    ~Living()
    { }

    virtual string get_name() =0;
    virtual int get_level() =0;
    virtual int get_health() =0;
    virtual void set_health(int) =0;
    virtual void print_stats() =0;
};




/*********************** HERO ***********************/
class Hero : public Living
{

protected:
    int mana;
    int strenght;
    int dexterity;
    int agility;
    int money;
    int experience;
    string hero_type;

    // std::vector<Weapon> Weapons;
    // std::vector<Armor>  Armour;
    // std::vector<Potions> Potions;
    // std::vector<void*> inventory;

public:
    Hero(string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon,
         int exp) : Living(nm, lv, hlth)
    {
        level = lv;
        mana = man;
        strenght = str;
        dexterity = dex;
        agility = ag;
        money = mon;
        experience = exp;
    }

    ~Hero()
    { }

    string get_name()
    {
        return name;
    }
    int get_level()
    {
        return level;
    }
    int get_health()
    {
        return health;
    }
    void set_health(int hlth)
    {
        health += hlth;
    }
    int get_mana()
    {
        return mana;
    }
    int get_strenght()
    {
        return strenght;
    }
    int get_dexterity()
    {
        return dexterity;
    }
    int get_agility()
    {
        return agility;
    }
    int get_money()
    {
        return money;
    }
    int get_experience()
    {
        return experience;
    }

    int do_dmg(class Monster*);
    int accept_exp(class Monster*);
    void print_stats();
};




/*********************** WARRIOR ***********************/
class Warrior : public Hero
{
public:
    Warrior(string nm="Brave Warrior", int lv=0,int hlth=100, int man=100, int str=50, int dex=30, int ag=50, int mon=1000,
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
};




/*********************** SORCERER ***********************/
class Sorcerer : public Hero
{
public:
    Sorcerer(string nm="Clever Sorcerer", int lv=0,int hlth=100, int man=100, int str=30, int dex=50, int ag=50, int mon=1000,
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
    Paladin(string nm="Fierce Paladin", int lv=0,int hlth=100, int man=100, int str=50, int dex=50, int ag=30, int mon=1000,
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
protected:
    int damage_min;
    int damage_max;
    int defence;
    int miss_chance;
    string monster_type;

public:
    Monster(string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) : Living(nm, lvl, hlth)
    {
        damage_max = dmax;
        damage_min = dmin;
        defence = def;
        miss_chance = miss;
    }

    ~Monster()
    { }

    string get_name()
    {
        return name;
    }
    int get_level()
    {
        return level;
    }
    int get_health()
    {
        return health;
    }
    void set_health(int hlth)
    {
        health += hlth;
    }
    int get_damage_max()
    {
        return damage_max;
    }
    int get_damage_min()
    {
        return damage_min;
    }
    int get_defence()
    {
        return defence;
    }
    int get_miss_chance()
    {
        return miss_chance;
    }

    int accept_dmg(int amount);
    void print_stats();
};




/*********************** DRAGON ***********************/
class Dragon : public Monster
{
public:
    Dragon(string nm="White Dragon", int lvl=0, int hlth=50, int dmin=10, int dmax=15, int def=10, int miss=10) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
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
    Exosceleton(string nm="Crispy Exo", int lvl=0, int hlth=50, int dmin=5, int dmax=10, int def=30, int miss=10) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
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
    Spirit(string nm="Semi-Visible Spirit", int lvl=0, int hlth=50, int dmin=5, int dmax=10, int def=10, int miss=40) : Monster(nm, lvl,hlth,dmin,dmax,def,miss)
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
