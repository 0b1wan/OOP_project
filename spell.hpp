#ifndef spell_h
#define spell_h

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
        Spell(string a, int b, int c, int d, int e, int f);
        virtual ~Spell();
        string get_name() const;
        int get_price() const;
        int get_minlevel() const;
        int get_mindamage() const;
        int get_maxdamage() const;
        int get_mana() const;
};

class Icespell : public Spell
{
    private:
        const int reduction;
        const int rounds;
    public:
        Icespell(string a, int b, int c, int d, int e, int f, int g, int h);
        ~Icespell();
        int get_reduction();
        int get_rounds();
};

class Firespell : public Spell
{
    private:
        const int reduction;
        const int rounds;
    public:
        Firespell(string a, int b, int c, int d, int e, int f, int g, int h);
        ~Firespell();
        int get_reduction();
        int get_rounds();
};

class Lightingspell : public Spell
{
    private:
        const int reduction;
        const int rounds;
    public:
        Lightingspell (string a, int b, int c, int d, int e, int f, int g, int h);
        ~Lightingspell();
        int get_reduction();
        int get_rounds();
};

#endif
