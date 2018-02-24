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

Game::~Game(){;}

void Game::begin()
{

    theMarket = new Market;

    add_Hero_Warrior(0,0, "Jesus", 9);
    add_Hero_Sorcerer(0,0, "jessy", 10);
    add_Hero_Paladin(0,0, "woosy" , 10);

    add_Monster_Dragon(3, 3, "Josh" , 6);

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

    while (showPossibleActions()) {}


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



int Game::add_Monster_Dragon(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Dragon* myDragon = new class Dragon(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myDragon);
    return 0;
}


int Game::add_Monster_Spirit(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Spirit* mySpirit = new class Spirit(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(mySpirit);
    return 0;
}


int Game::add_Monster_Exosceleton(int r, int c, string nm, int lvl, int hlth, int dmin, int dmax, int def, int miss) {
    class Exosceleton* myExosceleton = new class Exosceleton(nm, lvl, hlth, dmin, dmax, def, miss);
    theMonsters.push_back(myExosceleton);
    return 0;
}


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
    cout << " " <<  theHeros[ii]->name << " *** VS *** " << mymonster->name << endl << endl;

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
    {/* cast spell */}
    else if (k== "3")
    {/* use potion */}

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
    cout << " |  3. Go to Market -----> Hotkey: b  |" << endl;
    cout << " |  4. Display the Map --> Hotkey: v  |" << endl;
    cout << " |  5. Exit -------------> Hotkey: q  |" << endl;
    cout << " |                                    |" << endl;
    cout <<" \\------------------------------------/" << endl;

    string input;
    do {
        cout << "\n : ";
        cin >> input;
        if (input != "m" && input != "h" && input != "b" && input != "q" && input != "v")
            cout << "  Invalid input. Try one of the 4 hotkeys..." << endl;
        else
            break;
    } while (1);

    cout << endl;
    if (input == "m")
        askToMoveHeros();
    else if (input == "h")
        showHerosExpanded();
    else if (input == "b")
        return true;
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


    return;
}

void Game::printweparray(){
    int k=(int)theMarket->get_weparray().size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << theMarket->get_weparray()[i]->get_name() << endl;
    }
}
void Game::printarmarray(){
    int k=(int)theMarket->get_armarray().size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << theMarket->get_armarray()[i]->get_name() << endl;
    }
}
void Game::printpotarray(){
    int k=(int)theMarket->get_potarray().size();
    for (int i=0;i<k;i++)
    {
        cout << i+1 << ". " << theMarket->get_potarray()[i]->get_name() << endl;
    }
}
void Game::printicearray(){
  int k=(int)theMarket->get_icearray().size();
  for (int i=0;i<k;i++)
  {
        cout << i+1 << ". " << theMarket->get_icearray()[i]->get_name() << endl;
  }
}
void Game::printfirarray(){
  int k=(int)theMarket->get_firarray().size();
  for (int i=0;i<k;i++)
  {
        cout << i+1 << ". " << theMarket->get_firarray()[i]->get_name() << endl;
  }
}
void Game::printligarray(){
  int k=(int)theMarket->get_ligarray().size();
  for (int i=0;i<k;i++)
  {
        cout << i+1 << ". " << theMarket->get_ligarray()[i]->get_name() << endl;
  }
}
