#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> i;
  i.push_back(1);
  i.push_back(2);
  i.push_back(18);
  i.push_back(6);
  for (int j=0; j<i.size(); j++) cout << i[j] << endl;
  cout << ".................." << endl;
  i.erase(i.begin()+2);
  for (int j=0; j<i.size();j++) cout << i[j] << endl;
}
