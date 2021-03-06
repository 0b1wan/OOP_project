#include <iostream>
#include <string>
#include <vector>

#include "item.h"
#include "spell.hpp"
#include "market.h"

using namespace std;

Market::Market() {
  //3 wep, 3 arm, 3 pot, 3 spell
    Weapon * temp1 = new Weapon("Sword",150,1,50,"right"); //3 fixed weapons
    weparray.push_back(temp1);
    Weapon * temp2 = new Weapon("Gun",240,1,69,"both");
    weparray.push_back(temp2);
    Weapon * temp3 = new Weapon("Crossbow",400,1,80,"both");
    weparray.push_back(temp3);
    Armor * temp4 = new Armor("Shield",100,1,20);  //2 fixed armor
    armarray.push_back(temp4);
    Armor * temp5 = new Armor("Vest",150,1,40);
    armarray.push_back(temp5);
    Potion * temp6 = new Potion("Speed",70,1,"Agillity",5);  //2 fixed potions
    potarray.push_back(temp6);
    Potion * temp7 = new Potion("Heavy Hands",50,1,"Strength",3);
    potarray.push_back(temp7);
    Icespell * temp8 = new Icespell("Snowflakes",30,1,20,40,30,3,1); //1 fixed icespell -30cost,1minlevel, 20-40 dmg, 30 mana, 3 reduction of ability for 1 round
    icearray.push_back(temp8);
    Firespell * temp9 = new Firespell("Flamethrow",30,1,20,40,30,3,1);
    firarray.push_back(temp9);
    Lightingspell * temp10 = new Lightingspell("Thunder",30,1,20,40,30,3,1);
    ligarray.push_back(temp10);

}

Market::~Market() {
    //deallocate weparray
    for(int i=0;i<weparray.size();i++) { delete weparray[i];}
    //deallocate armarray
    for(int i=0;i<armarray.size();i++) { delete armarray[i];}
    //deallocate potarray
    for(int i=0;i<potarray.size();i++) { delete potarray[i];}
    //dealllocate icearray
    for(int i=0;i<icearray.size();i++) { delete icearray[i];}
    //deallocate firarray
    for(int i=0;i<firarray.size();i++) { delete firarray[i];}
    //deallocate ligarray
    for(int i=0;i<ligarray.size();i++) { delete ligarray[i];}
}

vector<Weapon *> Market::get_weparray(){
  return weparray;
}
vector<Armor *> Market::get_armarray(){
  return armarray;
}
vector<Potion *> Market::get_potarray(){
  return potarray;
}
vector<Icespell *> Market::get_icearray(){
  return icearray;
}
vector<Firespell *> Market::get_firarray(){
  return firarray;
}
vector<Lightingspell *> Market::get_ligarray(){
  return ligarray;
}
