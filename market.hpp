#ifndef market_h
#define market_h

#include "item.hpp"
#include "game.hpp"
#include <iostream>
#include <vector>

using namespace std;


class Market
{
private:
    vector<Weapon *> weparray;
    vector<Armor *> armarray;
    vector<Potion *> potarray;

public:

    void add_weapon();
    void add_armor();
    void add_potion();

    void printweparray();
    void printarmarray();
    void printpotarray();
    void printmenu();
    void print();
    Market();
    ~Market();

};

#endif
