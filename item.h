class Item
{
private:
    const string name;
    const int price;
    const int minlevel;
public:
 Item(string, int, int);
 virtual ~Item();
 string get_name() const;
 int get_price() const;
 int get_minlevel() const;
};

class Weapon : public Item
{
    private:
        const int damage;
        const bool hand;
    public:
        Weapon(string a, int b, int c, int d, bool e);
        ~Weapon();
        int get_damage();
        bool get_hand();
};

class Armor : public Item
{
    private:
        const int reduction;
    public:
        Armor(string a, int b, int c, int d);
        ~Armor();
        int get_reduction();

};

class Potion : public Item
{
    private:
        string ability;
        int increasement;
    public:
        Potion(string a, int b, int c, string d, int e);
        ~Potion();
        string get_ability();
        int get_increasement();
};
