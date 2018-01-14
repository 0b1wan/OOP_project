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

class Living
{
protected:
    std::string name;
    int level;
    int health;


public:
    Living(int lv , int hlth) {
        level = lv;
        health = hlth + (lv*100);
    }

    virtual int get_level() = 0;
    virtual int get_mana() = 0;

};


class Hero : public Living
{

protected:
    int mana;
    int strenght;
    int dexterity;
    int agility;
    int money;
    int experience;
    // std::vector<Weapon> Weapons;
    // std::vector<Armor>  Armour;
    // std::vector<Potions> Potions;
    // std::vector<void*> inventory;

public:
    Hero(int lv, int hlth, int man, int str, int dex, int ag, int mon,
         int exp) : Living(lv, hlth)
    {
        level = lv;
        mana = man;
        strenght = str;
        dexterity = dex;
        agility = ag;
        money = mon;
        experience = exp;
    }

    int get_level()
    {
        return level;
    }
    int get_health()
    {
        return health;
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

};


class Warrior : public Hero
{
public:
    Warrior(int lv=0,int hlth=100, int man=100, int str=40, int dex=30, int ag=40, int mon=1000,
            int exp=0) : Hero(lv, hlth, man, str, dex, ag, mon, exp)
    {
        
    }
};

#endif /* living_hpp */
