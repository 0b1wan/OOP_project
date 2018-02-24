#ifndef market_h
#define market_h

class Market
{
private:
  vector<Weapon * > weparray;
  vector<Armor * > armarray;
  vector<Potion * > potarray;
  vector<Icespell * > icearray;
  vector<Firespell * > firarray;
  vector<Lightingspell * > ligarray;
  int wepnum;
  int armnum;
  int potnum;
  int icenum;
  int firnum;
  int lignum;
public:
  int get_wepnum();
  int get_armnum();
  int get_potnum();
  int get_icenum();
  int get_firnum();
  int get_lignum();
  vector<Weapon * > get_weparray();
  vector<Armor * > get_armarray();
  vector<Potion * > get_potarray();
  vector<Icespell * > get_icearray();
  vector<Firespell * > get_firarray();
  vector<Lightingspell * > get_ligarray();
  Market();
  ~Market();


};

#endif
