#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#include "BinaryTree.hpp"

class Container {
public:
    
    int x;
    
    Container &operator+=(Container c) {
        x += c.x;
        return *this;
    }

    Container operator+(Container c) {
        Container caux;
        caux.x = x + c.x;
        return caux;
    }
    
    friend istream &operator>>(istream &is, Container &c);
    
    friend ostream &operator<<(ostream &os, const Container &c);
};

/*
Container operator+(Container c1, Container c2)
{
    Container c;
    c.x = c1.x + c2.x;
    return c;
}
*/

istream &operator>>(istream &is, Container &c)
{
    is >> c.x;
    return is;
}

ostream &operator<<(ostream &os, const Container &c)
{
    os << c.x;
    return os;
}

vector<string> split(string s)
{
    for (int i = 0; i < int(s.size()); i++)
        if (s[i] == '.')
            s[i] = ' ';
    istringstream mycin(s);
    vector<string> vs;
    string word;
    while (mycin >> word)
        vs.push_back(word);
    return vs;
        
}

BinaryTree<Container> &get(BinaryTree<Container> &t, vector<string> &v, int iv)
{
    if (iv == int(v.size())) return t;
    if (v[iv] == "left") return get(t.getLeft(), v, iv+1);
    if (v[iv] == "right") return get(t.getRight(), v, iv+1);
    return get(t, v, iv+1);
}

int main()
{
    BinaryTree<Container> t;
    string command;
    while (cin >> command) {
        //cout << "command " << command << endl;
        if (command == "<<") {
            string aux;
            cin >> aux;
            writeStringTree(cout, t); cout << endl;
            continue;
        }
        vector<string> vs = split(command);
        if (vs.back() == "sum") {
            cout << get(t, vs, 0).getSum() << endl;
        } else {
            string aux, s;
            cin >> aux >> s;
            readStringTree(s, get(t, vs, 0));
        }
    }
}
