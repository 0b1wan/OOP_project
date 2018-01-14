#include <iostream>
#include <string>

class Item
{
    private:
        const string name;
        const int price;
        const int minlevel;
    public:
        Item(string a, int b, int c) : name(a), price(b), minlevel(c)
        {
            cout << "Just constructed an Item" << endl;
        }
        virtual ~Item()
        {
            cout << "Just destroyed an Item" << endl;
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
        virtual int get_damage() = 0;
        virtual bool get_hand() = 0;
        virtual int get_reduction() = 0;
        virtual string get_ability() = 0;
        virtual int get_increasement() = 0;
};

class Weapon : public Item
{
    private:
        const int damage;
        const bool hand;
    public:
        Weapon(string a, int b, int c, int d, bool e) : Item(a,b,c), damage(d), hand(e)
        {
            cout << "Just constructed a Weapon" << endl;
        }
        ~Weapon()
        {
            cout << "Just destroyed a Weapon" << endl;
        }
        int get_damage(){
            return damage;
        }
        bool get_hand(){
            return hand;
        }
};

class Armor : public Item
{
    private:
        const int reduction;
    public:
        Armor(string a, int b, int c, int d) : Item(a,b,c), reduction(d)
        {
            cout << "Just constructed an Armor" << endl;
        }
        ~Armor()
        {
            cout << "Just destroyed an Armor" << endl;
        }
        int get_reduction(){
            return reduction;
        }
        
};

class Potion : public Item
{
    private:
        string ability;
        int increasement;
    public:
        Potion(string a, int b, int c, string d, int e) : Item(a,b,c), ability(d), increasement(e)
        {
            cout << "Just constructed a Potion" << endl;
        }
        ~Potion()
        {
            cout << "Just destroyed a Potion" << endl;
        }
        string get_ability(){
            return ability;
        }
        int get_increasement(){
            return increasement;
        }
};