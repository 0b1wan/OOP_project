#include <iostream>
#include <string>

using namespace std;

class Block
{
    private:
        string condition;
        bool contains;
    public:
        Block(string a, bool b) : condition(a), contains(b)
        {
            cout << "Just constructed a Block" << endl;
        }
        ~Block()
        {
            cout << "Just destroyed a Block" << endl;
        }
        string get_condition() const{
            return condition;
        }
        bool get_contains() const{
            return contains;
        }
};