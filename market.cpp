#include "market.h"



Market::Market(vector<Weapon*>& w, vector<Armor*>& a, vector<Potion*>& p) : weparray(w), armarray(a), potarray(p){
    cout << "A market was just created" << endl;
}
Market::~Market() {
    //apodesmeush ta items gt stous pinakes exw deiktes
}
void Market::printweparray(){
    int k=(int)weparray.size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << weparray[i]->get_name() << endl;
    }
}
void Market::printarmarray(){
    int k=(int)armarray.size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << armarray[i]->get_name() << endl;
    }
}
void Market::printpotarray(){
    int k=(int)potarray.size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << potarray[i]->get_name() << endl;
    }
}
void Market::print() {
    int k=Game::total_Heros;
    int a;
    for (int i=0; i<k; i++)
    {
        cout << "Pick one of the following for : " << theHeros[i]->name << endl;
        cout << "1. Buy  2. Sell  0. Exit" << endl;
        cin >> a;
        if (a==1){
            cout << "1. Weapons  2. Armor  3. Potions  0. Exit" << endl;
            cin >> a;
            if (a==1){
                cout << "Which one of these Weapons do you want to buy?" << endl;
                printweparray();
                cin >> a;
                //add to *weparray[a-1] sta weapons tou hrwa
            }
            else if (a==2){
                cout << "Which one of these Armor do you want to buy?" << endl;
                printarmarray();
                cin >> a;
                // add to *armarray[a-1] sta armor tou hrwa
            }
            else if (a==3){
                cout << "Which one of these Potions do you want to buy?" << endl;
                printpotarray();
                cin >> a;
                // add to *potarray[a-1] sta potions tou hrwa
            }
            else continue;
        }
        else if (a==2){
            cout << "1. Weapons  2. Armor  3. Potions  0. Exit" << endl;
            cin >> a;
            if (a==1){
                cout << "Which one of these Weapons do you want to sell?" << endl;
                for (int i=0; i<theHeros[i]->Weapons.size(); i++)
                {
                    cout << i+1 << ". " << theHeros[i]->Weapons.name << endl;
                }
                cin >> a;
                //remove to theHeros[i]->Weapons[a-1] apo ta weapons tou hrwa kai add sta lefta tou to (theHeros[i]->Weapons[a-1].price)/2      }
            }
            if (a==2){
                cout << "Which one of these Armor do you want to sell?" << endl;
                for (int i=0; i<theHeros[i]->Armour.size(); i++)
                {
                    cout << i+1 << ". " << theHeros[i]->Armour.name << endl;
                }
                cin >> a;
                //remove to theHeros[i]->Armour[a-1] apo ta Armor tou hrwa kai add sta lefta tou to (theHeros[i]->Armour[a-1].price)/2      }
            }
            if (a==3){
                cout << "Which one of these Potions do you want to sell?" << endl;
                for (int i=0; i<theHeros[i]->Potions.size(); i++)
                {
                    cout << i+1 << ". " << theHeros[i]->Potions.name << endl;
                }
                cin >> a;
                //remove to theHeros[i]->Potions[a-1] apo ta potions tou hrwa kai add sta lefta tou to (theHeros[i]->Potions[a-1].price)/2      }
            }
            else continue;
        }
        else continue;
    }
}
