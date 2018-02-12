class Market
{
private:
  vector<Weapon *> weparray;
  vector<Armor *> armarray;
  vector<Potion *> potarray;
public:
  void printweparray();
  void printarmarray();
  void printpotarray();
  void printmenu();
  void print();
  Market(vector<Weapon*>& w, vector<Armor*>& a, vector<Potion*>& p);
  ~Market();


};
