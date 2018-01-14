#include <iostream>
#include <string>

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
        
}