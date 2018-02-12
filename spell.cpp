#include <iostream>
#include <string>

using namespace std;

#include "spell.h"

        Spell::Spell(string a, int b, int c, int d, int e, int f) : name(a), price(b), minlevel(c), mindamage(d), maxdamage(e), mana(f)
        {
            cout << "Just constructed a Spell" << endl;
        }
        Spell::~Spell()
        {
            cout << "Just destroyed a Spell" << endl;
        }
        string Spell::get_name() const{
            return name;
        }
        int Spell::get_price() const{
            return price;
        }
        int Spell::get_minlevel() const{
            return minlevel;
        }
        int Spell::get_mindamage() const{
            return mindamage;
        }
        int Spell::get_maxdamage() const{
            return maxdamage;
        }
        int Spell::get_mana() const{
            return mana;
        }



        Icespell::Icespell(string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
            cout << "Just constructed an Icespell" << endl;
        }
        Icespell::~Icespell()
        {
            cout << "Just destroyed an Icespell" << endl;
        }
        int Icespell::get_reduction(){
            return reduction;
        }
        int Icespell::get_rounds(){
            return rounds;
        }



        Firespell::Firespell(string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
            cout << "Just constructed a Firespell" << endl;
        }
        Firespell::~Firespell()
        {
            cout << "Just destroyed a Firespell" << endl;
        }
        int Firespell::get_reduction(){
            return reduction;
        }
        int Firespell::get_rounds(){
            return rounds;
        }



        Lightingspell::Lightingspell (string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
            cout << "Just constructed a Lightingspell" << endl;
        }
        Lightingspell::~Lightingspell()
        {
            cout << "Just destroyed a Lightingspell" << endl;
        }
        int Lightingspell::get_reduction(){
            return reduction;
        }
        int Lightingspell::get_rounds(){
            return rounds;
        }
