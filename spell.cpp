#include <iostream>
#include <string>

using namespace std;

#include "spell.hpp"

        Spell::Spell(string a, int b, int c, int d, int e, int f) : name(a), price(b), minlevel(c), mindamage(d), maxdamage(e), mana(f)
        {

        }
        Spell::~Spell()
        {
          ;
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
          ;
        }
        Icespell::~Icespell()
        {
          ;
        }
        int Icespell::get_reduction(){
            return reduction;
        }
        int Icespell::get_rounds(){
            return rounds;
        }



        Firespell::Firespell(string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
          ;
        }
        Firespell::~Firespell()
        {
          ;
        }
        int Firespell::get_reduction(){
            return reduction;
        }
        int Firespell::get_rounds(){
            return rounds;
        }



        Lightingspell::Lightingspell (string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
          ;
        }
        Lightingspell::~Lightingspell()
        {
          ;
        }
        int Lightingspell::get_reduction(){
            return reduction;
        }
        int Lightingspell::get_rounds(){
            return rounds;
        }
