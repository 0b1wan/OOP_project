//
//  block.hpp
//  oop_project
//
//  Created by Andreas Chrysopoulos on 20/01/2018.
//  Copyright © 2018 Andreas Chrysopoulos & Giannis Mystakidis. All rights reserved.
//

#ifndef block_h
#define block_h

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

#endif /* block_h */
