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
public:
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
