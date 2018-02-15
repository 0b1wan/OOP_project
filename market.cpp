#include <iostream>
#include <vector>
#include "market.h"


Market::Market(vector<Weapon*>& w, vector<Armor*>& a, vector<Potion*>& p) : weparray(w), armarray(a), potarray(p){
    cout << "A market was just created" << endl;
}
Market::~Market() {
    //apodesmeush ta items gt stous pinakes exw deiktes
}
void Market::printweparray() {
    int k;
    k= (int)weparray.size();
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
void Market::printpotarray() {
    int k=(int)potarray.size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << potarray[i]->get_name() << endl;
    }
}
//void Market::print(){
//    //////////////////////////k=number of heroes/////////////////////////////////////////////////////
//
//    int k;
//    for (int i=0; i<k; i++)
//    {
//        //xreiazomai kati pou na mou epistrefei ton arithmo twn irwwn kai ta onomata tou kathenos
//    }
//}

