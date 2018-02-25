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
    //apodesmeush ta items gt stous pinakes exw deiktes
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

//void Market::shopping() {
//    int k = mygame->total_Heros;
//    int a;
//    for (int i=0; i<k; i++)
//    {
//        cout << "Pick one of the following for : " << theHeros[i]->name << endl;
//        cout << "1. Buy  2. Sell  0. Exit" << endl;
//        cin >> a;
//        if (a==1){
//            cout << "1. Weapons  2. Armor  3. Potions  0. Exit" << endl;
//            cin >> a;
//            if (a==1){
//                cout << "Which one of these Weapons do you want to buy?" << endl;
//                printweparray();
//                cin >> a;
//                //add to *weparray[a-1] sta weapons tou hrwa
//            }
//            else if (a==2){
//                cout << "Which one of these Armor do you want to buy?" << endl;
//                printarmarray();
//                cin >> a;
//                // add to *armarray[a-1] sta armor tou hrwa
//            }
//            else if (a==3){
//                cout << "Which one of these Potions do you want to buy?" << endl;
//                printpotarray();
//                cin >> a;
//                // add to *potarray[a-1] sta potions tou hrwa
//            }
//            else continue;
//        }
//        else if (a==2){
//            cout << "1. Weapons  2. Armor  3. Potions  0. Exit" << endl;
//            cin >> a;
//            if (a==1){
//                cout << "Which one of these Weapons do you want to sell?" << endl;
//                for (int i=0; i<theHeros[i]->Weapons.size(); i++)
//                {
//                    cout << i+1 << ". " << theHeros[i]->Weapons.name << endl;
//                }
//                cin >> a;
//                //remove to theHeros[i]->Weapons[a-1] apo ta weapons tou hrwa kai add sta lefta tou to (theHeros[i]->Weapons[a-1].price)/2      }
//            }
//            if (a==2){
//                cout << "Which one of these Armor do you want to sell?" << endl;
//                for (int i=0; i<theHeros[i]->Armour.size(); i++)
//                {
//                    cout << i+1 << ". " << theHeros[i]->Armour.name << endl;
//                }
//                cin >> a;
//                //remove to theHeros[i]->Armour[a-1] apo ta Armor tou hrwa kai add sta lefta tou to (theHeros[i]->Armour[a-1].price)/2      }
//            }
//            if (a==3){
//                cout << "Which one of these Potions do you want to sell?" << endl;
//                for (int i=0; i<theHeros[i]->Potions.size(); i++)
//                {
//                    cout << i+1 << ". " << theHeros[i]->Potions.name << endl;
//                }
//                cin >> a;
//                //remove to theHeros[i]->Potions[a-1] apo ta potions tou hrwa kai add sta lefta tou to (theHeros[i]->Potions[a-1].price)/2      }
//            }
//            else continue;
//        }
//        else continue;
//    }
//}
//
//
