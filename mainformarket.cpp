#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "item.h"
#include "spell.hpp"
#include "market.h"
#include "game.hpp"

int main()
{
  Market theMarket;
  Game MyGame(6,6,theMarket);
  cout << "The Weapons are:" << endl;
  MyGame.printweparray();
  cout << "The Armor are:" << endl;
  MyGame.printarmarray();
  cout << "The Potions are:" << endl;
  MyGame.printpotarray();
  cout << "The Icespells are: " << endl;
  MyGame.printicearray();
  cout << "The Firespells are: " << endl;
  MyGame.printfirarray();
  cout << "The Lightingspell are: " << endl;
  MyGame.printligarray();
}
