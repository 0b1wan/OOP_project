#include <iostream>
#include <string>

using namespace std;

class Spell
{
    private:
        const string name;
        const int price;
        const int minlevel;
        const int mindamage;
        const int maxdamage;
        const int mana;
    public:
        Spell(string a, int b, int c, int d, int e, int f) : name(a), price(b), minlevel(c), mindamage(d), maxdamage(e), mana(f)
        {
            cout << "Just constructed a Spell" << endl;   
        }
        virtual ~Spell()
        {
            cout << "Just destroyed a Spell" << endl;
        }
        string get_name() const{
            return name;
        }
        int get_price() const{
            return price;
        }
        int get_minlevel() const{
            return minlevel;
        }
        int get_mindamage() const{
            return mindamage;
        }
        int get_maxdamage() const{
            return maxdamage;
        }
        int get_mana() const{
            return mana;
        }
};

class Icespell : public Spell
{
    private:
        const int reduction;
        const int rounds;
    public:
        Icespell(string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
            cout << "Just constructed an Icespell" << endl;
        }
        ~Icespell()
        {
            cout << "Just destroyed an Icespell" << endl;
        }
        int get_reduction(){
            return reduction;
        }
        int get_rounds(){
            return rounds;
        }
};

class Firespell : public Spell
{
    private:
        const int reduction;
        const int rounds;
    public:
        Firespell(string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
            cout << "Just constructed a Firespell" << endl;
        }
        ~Firespell()
        {
            cout << "Just destroyed a Firespell" << endl;
        }
        int get_reduction(){
            return reduction;
        }
        int get_rounds(){
            return rounds;
        }
};

class Lightingspell : public Spell
{
    private:
        const int reduction;
        const int rounds;
    public:
        Lightingspell (string a, int b, int c, int d, int e, int f, int g, int h) : Spell(a,b,c,d,e,f), reduction(g), rounds(h)
        {
            cout << "Just constructed a Lightingspell" << endl;
        }
        ~Lightingspell()
        {
            cout << "Just destroyed a Lightingspell" << endl;
        }
        int get_reduction(){
            return reduction;
        }
        int get_rounds(){
            return rounds;
        }
};