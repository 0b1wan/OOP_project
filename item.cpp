#include "item.h"

Item::Item(string a, int b, int c) : name(a), price(b), minlevel(c)
{
  ;
}
Item::~Item()
{
  ;
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
  ;
}
Weapon::~Weapon()
{
  ;
}
int Weapon::get_damage(){
    return damage;
}
string Weapon::get_hand(){
    return hand;
}



Armor::Armor(string a, int b, int c, int d) : Item(a,b,c), reduction(d)
{
  ;
}
Armor::~Armor()
{
  ;
}
int Armor::get_reduction(){
    return reduction;
}



Potion::Potion(string a, int b, int c, string d, int e) : Item(a,b,c), ability(d), increasement(e)
{
  ;
}
Potion::~Potion()
{
  ;
}
string Potion::get_ability(){
    return ability;
}
int Potion::get_increasement(){
    return increasement;
}
