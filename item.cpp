#include "item.h"

Item::Item(string a, int b, int c) : name(a), price(b), minlevel(c)
{
    cout << "Just constructed an Item" << endl;
}
Item::~Item()
{
    cout << "Just destroyed an Item" << endl;
}
string Item::get_name() const{
    return name;
}
int Item::get_price() const{
    return price;
}
int Item::get_minlevel() const{
    return minlevel;
}


Weapon::Weapon(string a, int b, int c, int d, string e) : Item(a,b,c), damage(d), hand(e)
{
    cout << "Just constructed a Weapon" << endl;
}
Weapon::~Weapon()
{
    cout << "Just destroyed a Weapon" << endl;
}
int Weapon::get_damage(){
    return damage;
}
string Weapon::get_hand(){
    return hand;
}



Armor::Armor(string a, int b, int c, int d) : Item(a,b,c), reduction(d)
{
    cout << "Just constructed an Armor" << endl;
}
Armor::~Armor()
{
    cout << "Just destroyed an Armor" << endl;
}
int Armor::get_reduction(){
    return reduction;
}



Potion::Potion(string a, int b, int c, string d, int e) : Item(a,b,c), ability(d), increasement(e)
{
    cout << "Just constructed a Potion" << endl;
}
Potion::~Potion()
{
    cout << "Just destroyed a Potion" << endl;
}
string Potion::get_ability(){
    return ability;
}
int Potion::get_increasement(){
    return increasement;
}
