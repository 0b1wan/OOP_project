#include <iostream>
#include <vector>

using namespace std;
#include "market.h"

Market::Market(vector<Weapon*>& w, vector<Armor*>& a, vector<Potion*>& p) : weparray(w), armarray(a), potarray(p){
  cout << "A market was just created" << endl;
}
Market::Market(){
  //apodesmeush ta items gt stous pinakes exw deiktes
}
Market::printweparray(){
  k=weparray.size();
  for (i=0;i<k;i++)
  {
    cout << i+1 << ". " << weparray[i].get_name() << endl;
  }
Market::printarmarray(){
  k=armarray.size();
  for (i=0;i<k;i++)
  {
    cout << i+1 << ". " << armarray[i].get_name() << endl;
  }
}
Market::printpotarray(){
  k=potarray.size();
  for (i=0;i<k;i++)
  {
    cout << i+1 << ". " << potarray[i].get_name() << endl;
  }
}
Market::print(){
//////////////////////////k=number of heroes/////////////////////////////////////////////////////
  for (i=0; i<k; i++)
  {
    //xreiazomai kati pou na mou epistrefei ton arithmo twn irwwn kai ta onomata tou kathenos
  }
}
