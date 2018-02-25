//
//  game.cpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#include "game.hpp"


Game::Game(int r, int c)
{
    grid_c = c;
    grid_r = r;
    total_Heros = 0;
    theGrid = new class Grid(r, c);
}

Game::~Game(){
  //delete the market
  delete theMarket;
  //deallocate theHeros vector
  for(int i=0;i<theHeros.size();i++) {delete theHeros[i];}
  //deallocate grid
  delete theGrid;
}

void Game::begin()
{

    theMarket = new Market;

    add_Hero_Warrior(0,0, "Jesus", 9);
    add_Hero_Sorcerer(0,0, "Bob", 10);
    add_Hero_Paladin(0,0, "Kayla" , 10);


    theGrid->add_Market(1, 1);
    theGrid->add_Market(4, 3);
    theGrid->add_Market(3, 4);
    theGrid->add_NonAccessible(2, 1);


    cout << " Welcome to the Game! " << endl << endl;
    cout << " This is how the world looks right now... " << endl;
    theGrid->showMap();

    cout << " Your heros are on square [0,0] each showing his health percentage after the Character Type. " << endl;
    cout << " You begin the Game with 3 different Hero types..." << endl;
    cout << " A warrior, a sorcerer and paladin..." << endl;
    cout << " Each type has different attribute advantages as he levels up." << endl << endl;
    cout << " Try to take some action..." << endl;

    while (showPossibleActions() )
    {
    }


}

/********** ADD HEROS **********/



int Game::add_Hero_Warrior(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Warrior* mywarrior = new class Warrior(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mywarrior->r_co = r;
    mywarrior->c_co = c;
    theHeros.push_back(mywarrior);
    theGrid->square[r][c]->heros.push_back(mywarrior);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Paladin(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Paladin* mypaladin = new class Paladin(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mypaladin->r_co = r;
    mypaladin->c_co = c;
    theHeros.push_back(mypaladin);
    theGrid->square[r][c]->heros.push_back(mypaladin);
    total_Heros++;
    return 0;
}


int Game::add_Hero_Sorcerer(int r, int c,string nm, int lv, int hlth, int man, int str, int dex, int ag, int mon, int exp)
{
    if (total_Heros == 3)
    {
        cout << "Maximum number of Heros reached!" << endl;
        return -1;
    }
    class Sorcerer* mysorcerer = new class Sorcerer(nm,lv,hlth,man,str,dex,ag,mon,exp);
    mysorcerer->r_co = r;
    mysorcerer->c_co = c;
    theHeros.push_back(mysorcerer);
    theGrid->square[r][c]->heros.push_back(mysorcerer);
    total_Heros++;
    return 0;
}





/********** ADD MONSTERS **********/


class Monster * Game::randMonster(Hero * thehero) {

    int montype = rand() % 3 + 1;
    Monster * themonster;

    if (montype == 1)
        themonster = new Dragon("The HEAT", thehero->level - 2);
    else if (montype == 2)
        themonster = new Spirit("See-through", thehero->level - 2);
    else
        themonster = new Exosceleton("Thin One", thehero->level - 2);

    return themonster;
}

void Game::surprise(vector<Hero*> heros) {

    // create random monster
    Monster * mymonster = randMonster(theHeros[0]);

    cout << "\n Random monster Appeared!";
    mymonster->print_stats();

    for (int i=0; i<total_Heros; i++) {
        if (theHeros[i]->isAlive()) {
            cout << " " << i + 1 << ". " << theHeros[i]->who() << endl;
        }
    }

    string i;
    int ii = -1;
    do {
        cout << " \n Select Hero for fight: \n > ";
        cin >> i;
        if (i == "1")
            if (theHeros[0]->isAlive()) {
                ii = 0;
                break;
            }
        if (i == "2")
            if (theHeros[1]->isAlive()) {
                ii = 1;
                break;
            }
        if (i == "3")
            if (theHeros[2]->isAlive()) {
                ii = 2;
                break;
            }
    } while(1);


    cout << " Commencing fight... \n" << endl;
    cout << " " <<  theHeros[ii]->name << " *** VS *** " << mymonster->name << endl;

    cout << "\n What would you like to do?" << endl;
    cout << " 1. Attack " << endl;
    cout << " 2. Cast Spell " << endl;
    cout << " 3. Use Potion " << endl;


    string k;
    do {
        cout << "\n > ";
        cin >> k;
        if ((k == "1") || (k == "2") || (k == "3"))
            break;
    } while(1);
    cout << endl;

    if (k == "1")
        theHeros[ii]->attack(mymonster);
    else if (k== "2")
    {
        // cast spell

        if (theHeros[ii]->Icespells.empty() && theHeros[ii]->Lightingspells.empty() && theHeros[ii]->Firespells.empty() )
        {
            cout << " This hero has no available spells " << endl;
            theHeros[ii]->attack(mymonster);
            return;
        }

        cout << "1. Firespell: " << theMarket->get_firarray()[0]->get_name() << endl;
        cout << "2. Icespell: " << theMarket->get_icearray()[0]->get_name() << endl;
        cout << "3. Lightingspell: " << theMarket->get_ligarray()[0]->get_name() << endl;

        cout << " Select Spell \n > ";

        int i;
        cin >> i;
        if (i == 1)
            mymonster->firespelled(theMarket->get_firarray()[0]);
        else if (i==2)
            mymonster->icespelled(theMarket->get_icearray()[0]);
        else if (i==3)
            mymonster->lightingspelled(theMarket->get_ligarray()[0]);


        cout << " Monster has been spelled! " << endl;
        theHeros[ii]->attack(mymonster);

    }
    else if (k== "3")
    {
        cout << endl;
        if (theHeros[ii]->Potions.empty()) {
            cout << " This hero has no available potions " << endl;
            theHeros[ii]->attack(mymonster);
            return;
        }

        int in;
        for (int j=0; j<theHeros[ii]->Potions.size(); j++)
            cout << j+1 << ". " << theHeros[ii]->Potions[j]->get_name() << endl;
        cout << "\n Choose Potion to use \n > " << endl << endl;
        cin >> in;

        try {
            theHeros[ii]->equipPotion(theHeros[ii]->Potions[in]);
            theHeros[ii]->attack(mymonster);
        } catch (exception) {
        }

    }

    if (checkHerosAlive() == false)
        exit(1);

}

bool Game::checkHerosAlive() {

    int dead = 0;
    for (int i=0; i<total_Heros; i++) {
        if (!theHeros[i]->isAlive())
            dead++;
    }

    return dead != total_Heros;
}


void Game::move_heros(string direction)
{
    // figure future location
    int fr, fc;

    if (direction == "up")
    {
        fr = theHeros[0]->r_co -1;
        fc = theHeros[0]->c_co;
    }
    else if (direction == "down")
    {
        fr = theHeros[0]->r_co +1;
        fc = theHeros[0]->c_co;
    }
    else if (direction == "left")
    {
        fr = theHeros[0]->r_co;
        fc = theHeros[0]->c_co -1;
    }
    else
    {
        fr = theHeros[0]->r_co;
        fc = theHeros[0]->c_co +1;
    }

    // check location within bounds
    if ((fc < 0) || (fr < 0) || (fc >= this->grid_c) || (fr >= this->grid_r)) {
        cout << " Moving " << direction << " not allowed. Map edge." << endl;
        return;
    }

    // check block_type is accessible
    if (theGrid->square[fr][fc]->block_type == "NonAccessible")
    {
        cout << " Moving " << direction << " not allowed. Block is Non Accessible." << endl;
        return;
    }

    // check if block_type is market
    if (theGrid->square[fr][fc]->block_type == "Market")
        foundMarket();
    else {
        // fight some monsters in the way
        int chance = rand() % 100 + 1;
        if (chance < 20)
            surprise(theHeros);
    }

    // actually move the heros
    theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->heros.clear();
    for (int i=0; i<total_Heros; i++) {
        theHeros[i]->r_co = fr;
        theHeros[i]->c_co = fc;
        theGrid->square[fr][fc]->heros.push_back(theHeros[i]);
    }
    cout << " Moved " << direction << ". Team now at pos [" << fr << "," << fc << "]" << endl;

    // Heal heros after moving them
    heal_heros();

}

void Game::askToMoveHeros()
{

    char input;
    do {
        cout << " Input Direction: (w, a, s, d) \n > ";
        cin >> input;
    } while (input != 'w' && input != 'a' && input != 'd' && input != 's');

    switch (input) {
        case 'w':
            move_heros("up");
            break;

        case 's':
            move_heros("down");
            break;

        case 'a':
            move_heros("left");
            break;

        case 'd':
            move_heros("right");
            break;

        default:
            break;
    }

}

void Game::heal_heros()
{
    for (int i=0; i<total_Heros; i++)
        theHeros[i]->heal();
}


string StringToUpper(string strToConvert)
{
    string newstring = "";

    for (int i=0; i<(int)strToConvert.length(); i++) {
        newstring.append(toupper(strToConvert[i]), i);
    }
    return newstring;
}

void Game::showHerosExpanded()
{
    Map mymap;
    for (auto hero : theHeros) {

        string herotype;
        if (hero->hero_type == "Sorcerer")
            herotype.append(" |  " + hero->hero_type + "  | ");
        else
            herotype.append(" |  " + hero->hero_type + "   |");

        Textbox * t1 = new Textbox( {" @------------+-",
                                      herotype,
                                     " +------------+-",
                                     " |       Mana | ",
                                     " |     Health | ",
                                     " +------------+-",
                                     " |     Damage | ",
                                     " |   Strength | ",
                                     " |  Dexterity | ",
                                     " |    Agility | ",
                                     " +------------+-",
                                     " |       Gold | ",
                                     " | Experience | ",
                                     " @------------+-", "\n"} );

        mymap.add_textbox(t1, -1, true);

        string mystring;
        vector<string> myvector;

        mystring.append(hero->name);
        mystring.append(" | ");
        mystring.append("LVL " + to_string(hero->level));
        mystring.append(" | ");
        mystring.append(to_string(hero->c_co) + ", " + to_string(hero->r_co) + " |");

        int len = (int)mystring.length();
        mystring.clear();

        for (int i=0; i<len-1; i++)
            mystring.append("-");
        mystring.append("@");

        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(hero->name);
        mystring.append(" | ");
        mystring.append("LVL " + to_string(hero->level));
        mystring.append(" | ");
        mystring.append(to_string(hero->c_co) + ", " + to_string(hero->r_co) + " |");

        myvector.push_back(mystring);
        mystring.clear();

        for (int i=0; i<len-1; i++)
            mystring.append("-");
        mystring.append("+");

        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->mana) + "/" + to_string(hero->max_mana) + " : ");
        mystring.append(to_string((int)(((float)hero->mana/hero->max_mana)*100)) + "%");
        int spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->health) + "/" + to_string(hero->max_health) + " : ");
        mystring.append(to_string((int)(((float)hero->health/hero->max_health)*100)) + "%");
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        for (int i=0; i<len-1; i++)
            mystring.append("-");
        mystring.append("+");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->strenght /* weapon strenght */));
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->strenght));
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->dexterity));
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->agility) + " : " + to_string(hero->get_dodge_chance()) + "%");
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();


        for (int i=0; i<len-1; i++)
            mystring.append("-");
        mystring.append("+");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->gold));
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        mystring.append(to_string(hero->experience) + "/" + to_string(hero->levelup_experience) + " : " + to_string((int)(((float)hero->experience/hero->levelup_experience)*100)) + "%");
        spaces = (int)myvector[0].size() - (int)mystring.size();
        for (int i=0; i<spaces -1; i++)
            mystring.append(" ");
        mystring.append("|");
        myvector.push_back(mystring);
        mystring.clear();

        for (int i=0; i<len-1; i++)
            mystring.append("-");
        mystring.append("@");
        myvector.push_back(mystring);
        mystring.clear();

        mymap.add_textbox(new Textbox(myvector));

    }
    mymap.show();

}



bool Game::showPossibleActions()
{
    cout << endl;
    cout << "      What would you like to do?       " << endl;
    cout << " /------------------------------------\\" << endl;
    cout << " |                                    |" << endl;
    cout << " |  1. Move team --------> Hotkey: m  |" << endl;
    cout << " |  2. Show Heros -------> Hotkey: h  |" << endl;
    cout << " |  3. Show Inventory ---> Hotkey: i  |" << endl;
    cout << " |  4. Display the Map --> Hotkey: v  |" << endl;
    cout << " |  5. Exit -------------> Hotkey: q  |" << endl;
    cout << " |                                    |" << endl;
    if (theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->block_type == "Market") {
        cout << " |  .. Reenter Market ---> Hotkey: r  |" << endl;
        cout << " |                                    |" << endl;
    }
    cout <<" \\------------------------------------/" << endl;

    string input;
    do {
        cout << "\n : ";
        cin >> input;
        if (theGrid->square[theHeros[0]->r_co][theHeros[0]->c_co]->block_type == "Market") {
            if (input == "r")
                break;
        }
        if (input != "m" && input != "h" && input != "q" && input != "v" && input != "i")
            cout << "  Invalid input. Try one of the 4 hotkeys..." << endl;
        else
            break;
    } while (1);

    cout << endl;
    if (input == "r")
        goShopping();
    if (input == "m") {
        askToMoveHeros();
    }
    else if (input == "h")
        showHerosExpanded();
    else if (input == "i")
        printinventory();
    else if (input == "q")
    {
        cout << " Thanks for playing!" << endl << endl;
        cout << " Game terminated." << endl << endl;
        return false;
    }
    else if (input == "v"){
        theGrid->showMap();
        return true;
    }
    else
        return true;

    return true;
}

void Game::foundMarket() {

    cout << endl << " Welcome to the Market! Here you have the chance to equip your heros with the latest and greatest in Weapons, Armor, Spells and Potions! Enjoy. " << endl << endl;

    goShopping();

    return;
}

void Game::printweparray(){
    int k=(int)theMarket->get_weparray().size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << theMarket->get_weparray()[i]->get_name() <<" -> "<<"Price = "<< theMarket->get_weparray()[i]->get_price()<<" MinLevel = " <<theMarket->get_weparray()[i]->get_minlevel()<<" Damage = "<<theMarket->get_weparray()[i]->get_damage()<<" Hand = "<<theMarket->get_weparray()[i]->get_hand()<< endl;
    }
}
void Game::printarmarray(){
    int k=(int)theMarket->get_armarray().size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << theMarket->get_armarray()[i]->get_name() <<" -> "<<"Price = "<< theMarket->get_armarray()[i]->get_price()<<" MinLevel = " <<theMarket->get_armarray()[i]->get_minlevel()<<" Reduction = "<<theMarket->get_armarray()[i]->get_reduction()<< endl;
    }
}
void Game::printpotarray(){
    int k=(int)theMarket->get_potarray().size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << theMarket->get_potarray()[i]->get_name() <<" -> "<<"Price = "<< theMarket->get_potarray()[i]->get_price()<<" MinLevel = " <<theMarket->get_potarray()[i]->get_minlevel()<<" Ability = "<<theMarket->get_potarray()[i]->get_ability()<<" Increasement = "<<theMarket->get_potarray()[i]->get_increasement()<< endl;
    }
}
void Game::printicearray(){
  int k=(int)theMarket->get_icearray().size();
  for (int i=0;i<k;i++)
  {
        cout << i+1 << ". " << theMarket->get_icearray()[i]->get_name() <<" -> "<<"Price = "<< theMarket->get_icearray()[i]->get_price()<<" MinLevel = " <<theMarket->get_icearray()[i]->get_minlevel()<<" MinDamage = " <<theMarket->get_icearray()[i]->get_mindamage()<<" MaxDamage = " <<theMarket->get_icearray()[i]->get_maxdamage() << " Reduction = " <<theMarket->get_icearray()[i]->get_reduction()<< " Rounds = " <<theMarket->get_icearray()[i]->get_rounds()<< endl;
  }
}
void Game::printfirarray(){
  int k=(int)theMarket->get_firarray().size();
  for (int i=0;i<k;i++)
  {
        cout << i+1 << ". " << theMarket->get_firarray()[i]->get_name() <<" -> "<<"Price = "<< theMarket->get_firarray()[i]->get_price()<<" MinLevel = " <<theMarket->get_firarray()[i]->get_minlevel()<<" MinDamage = " <<theMarket->get_firarray()[i]->get_mindamage()<<" MaxDamage = " <<theMarket->get_firarray()[i]->get_maxdamage()<< " Reduction = " <<theMarket->get_firarray()[i]->get_reduction()<< " Rounds = " <<theMarket->get_firarray()[i]->get_rounds()<< endl;
  }
}
void Game::printligarray(){
  int k=(int)theMarket->get_ligarray().size();
  for (int i=0;i<k;i++)
  {
        cout << i+1 << ". " << theMarket->get_ligarray()[i]->get_name() <<" -> "<<"Price = "<< theMarket->get_ligarray()[i]->get_price()<<" MinLevel = " <<theMarket->get_ligarray()[i]->get_minlevel()<<" MinDamage = " <<theMarket->get_ligarray()[i]->get_mindamage()<<" MaxDamage = " <<theMarket->get_ligarray()[i]->get_maxdamage()<< " Reduction = " <<theMarket->get_ligarray()[i]->get_reduction()<< " Rounds = " <<theMarket->get_ligarray()[i]->get_rounds()<< endl;
  }
}

void Game::printinventory(){
  for (int i=0;i<theHeros.size();i++)
  {
    cout << "________________________________" << endl;
    cout << theHeros[i]->name << "'s' inventory is :" << endl;
    cout << "The Weapons are :" << endl;
    for (int j=0;j<theHeros[i]->Weapons.size();j++)
    {
      cout << j+1 << ". " << theHeros[i]->Weapons[j]->get_name() << endl;
    }
    cout << "The Armour are :" << endl;
    for (int j=0; j<theHeros[i]->Armour.size();j++)
    {
      cout << j+1 << ". " << theHeros[i]->Armour[j]->get_name() << endl;
    }
    cout << "The Potions are:" << endl;
    for (int j=0; j<theHeros[i]->Potions.size();j++)
    {
      cout << j+1 << ". " << theHeros[i]->Potions[j]->get_name() << endl;
    }
    cout << "The Icespells are:" << endl;
    for (int j=0; j<theHeros[i]->Icespells.size();j++)
    {
      cout << j+1 << ". " << theHeros[i]->Icespells[j]->get_name() << endl;
    }
    cout << "The Firespells are:" << endl;
    for (int j=0; j<theHeros[i]->Firespells.size();j++)
    {
      cout << j+1 << ". " << theHeros[i]->Firespells[j]->get_name() << endl;
    }
    cout << "The Lightingspells are:" << endl;
    for (int j=0; j<theHeros[i]->Lightingspells.size();j++)
    {
      cout << j+1 << ". " << theHeros[i]->Lightingspells[j]->get_name() << endl;
    }
    cout << "________________________________" << endl;
  }
}

void Game::goShopping() {
    int k = (int)theHeros.size();
    int a;
    for (int i=0; i<k; i++)
    {
        cout << "Pick one of the following for : " << theHeros[i]->name << "( Got " << theHeros[i]->gold << " Gold" << " )" << endl;
        cout << "1. Buy  2. Sell  0. Exit" << endl;
        cin >> a;
        if (a==1){
            cout << "1. Weapons  2. Armor  3. Potions  4. Icespells  5. Firespells  6. Lightingspells  0. Exit" << endl;
            cin >> a;
            if (a==1){
                cout << "Which one of these Weapons do you want to buy?" << endl;
                printweparray();
                cin >> a;
                if (theHeros[i]->gold >= theMarket->get_weparray()[a-1]->get_price())
                {
                   Weapon * wep = new Weapon(*theMarket->get_weparray()[a-1]);
                   theHeros[i]->add_weapon(wep);
                   theHeros[i]->remove_gold(theMarket->get_weparray()[a-1]->get_price());
                }
                else cout << "Not enough money!" << endl;
            }
            else if (a==2){
                cout << "Which one of these Armor do you want to buy?" << endl;
                printarmarray();
                cin >> a;
                if (theHeros[i]->gold >= theMarket->get_armarray()[a-1]->get_price())
                {
                   Armor * arm = new Armor(*theMarket->get_armarray()[a-1]);
                   theHeros[i]->add_armor(arm);
                   theHeros[i]->remove_gold(theMarket->get_armarray()[a-1]->get_price());
                }
                else cout << "Not enough money!"  << endl;
            }
            else if (a==3){
                cout << "Which one of these Potions do you want to buy?" << endl;
                printpotarray();
                cin >> a;
                if (theHeros[i]->gold >= theMarket->get_potarray()[a-1]->get_price())
                {
                   Potion * pot = new Potion(*theMarket->get_potarray()[a-1]);
                   theHeros[i]->add_potion(pot);
                   theHeros[i]->remove_gold(theMarket->get_potarray()[a-1]->get_price());
                }
                else cout << "Not enough money!" << endl;
            }
            else if (a==4){
                cout << "Which one of these Icespells do you want to buy?" << endl;
                printicearray();
                cin >> a;
                if (theHeros[i]->gold >= theMarket->get_icearray()[a-1]->get_price())
                {
                   Icespell * ice = new Icespell(*theMarket->get_icearray()[a-1]);
                   theHeros[i]->add_icespell(ice);
                   theHeros[i]->remove_gold(theMarket->get_icearray()[a-1]->get_price());
                }
                else cout << "Not enough money!" << endl;
            }
            else if (a==5){
                cout << "Which one of these Firespells do you want to buy?" << endl;
                printfirarray();
                cin >> a;
                if (theHeros[i]->gold >= theMarket->get_firarray()[a-1]->get_price())
                {
                   Firespell * fir = new Firespell(*theMarket->get_firarray()[a-1]);
                   theHeros[i]->add_firespell(fir);
                   theHeros[i]->remove_gold(theMarket->get_firarray()[a-1]->get_price());
                }
                else cout << "Not enough money!" << endl;
            }
            else if (a==6){
                cout << "Which one of these Lightingspells do you want to buy?" << endl;
                printligarray();
                cin >> a;
                if (theHeros[i]->gold >= theMarket->get_ligarray()[a-1]->get_price())
                {
                   Lightingspell * lig = new Lightingspell(*theMarket->get_ligarray()[a-1]);
                   theHeros[i]->add_lightingspell(lig);
                   theHeros[i]->remove_gold(theMarket->get_ligarray()[a-1]->get_price());
                }
                else cout << "Not enough money!" << endl;
            }
            else continue;
        }
        else if (a==2){
            cout << "1. Weapons  2. Armor  3. Potions  4. Icespells  5. Firespells  6. Lightingspells  0. Exit" << endl;
            cin >> a;
            if (a==1){
                cout << "Which one of these Weapons do you want to sell?" << endl;
                for (int j=0; j<theHeros[i]->Weapons.size(); j++)
                {
                    cout << j+1 << ". " << theHeros[i]->Weapons[j]->get_name() << endl;
                }
                cin >> a;
                theHeros[i]->remove_weapon(a-1);
                theHeros[i]->add_gold( (theHeros[i]->Weapons[a-1]->get_price())/2 );
            }
            if (a==2){
                cout << "Which one of these Armor do you want to sell?" << endl;
                for (int j=0; j<theHeros[i]->Armour.size(); j++)
                {
                    cout << j+1 << ". " << theHeros[i]->Armour[j]->get_name() << endl;
                }
                cin >> a;
                theHeros[i]->remove_armor(a-1);
                theHeros[i]->add_gold( (theHeros[i]->Armour[a-1]->get_price())/2 );
            }
            if (a==3){
                cout << "Which one of these Potions do you want to sell?" << endl;
                for (int j=0; j<theHeros[i]->Potions.size(); j++)
                {
                    cout << j+1 << ". " << theHeros[i]->Potions[j]->get_name() << endl;
                }
                cin >> a;
                theHeros[i]->remove_potion(a-1);
                theHeros[i]->add_gold( (theHeros[i]->Potions[a-1]->get_price())/2 );
            }
            if (a==4){
                cout << "Which one of these Icespells do you want to sell?" << endl;
                for (int j=0; j<theHeros[i]->Icespells.size(); j++)
                {
                    cout << j+1 << ". " << theHeros[i]->Icespells[j]->get_name() << endl;
                }
                cin >> a;
                theHeros[i]->remove_icespell(a-1);
                theHeros[i]->add_gold( (theHeros[i]->Icespells[a-1]->get_price())/2 );
            }
            if (a==5){
                cout << "Which one of these Firespells do you want to sell?" << endl;
                for (int j=0; j<theHeros[i]->Firespells.size(); j++)
                {
                    cout << j+1 << ". " << theHeros[i]->Firespells[j]->get_name() << endl;
                }
                cin >> a;
                theHeros[i]->remove_firespell(a-1);
                theHeros[i]->add_gold( (theHeros[i]->Firespells[a-1]->get_price())/2 );
            }
            if (a==6){
                cout << "Which one of these Lightingspells do you want to sell?" << endl;
                for (int j=0; j<theHeros[i]->Lightingspells.size(); j++)
                {
                    cout << j+1 << ". " << theHeros[i]->Lightingspells[j]->get_name() << endl;
                }
                cin >> a;
                theHeros[i]->remove_lightingspell(a-1);
                theHeros[i]->add_gold( (theHeros[i]->Lightingspells[a-1]->get_price())/2 );
            }
            else continue;
        }
        else continue;
    }
}
