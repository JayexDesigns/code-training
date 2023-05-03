#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#include "BinaryTree.hpp"

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

BinaryTree<int> &get(BinaryTree<int> &t, vector<string> &v, int iv)
{
    if (iv == int(v.size())) return t;
    if (v[iv] == "left") return get(t.getLeft(), v, iv+1);
    if (v[iv] == "right") return get(t.getRight(), v, iv+1);
    return get(t, v, iv+1);
}

int main()
{
    BinaryTree<int> t;
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
        if (vs.back() == "size") {
            cout << get(t, vs, 0).getSize() << endl;
        } else {
            string aux, s;
            cin >> aux >> s;
            readStringTree(s, get(t, vs, 0));
        }
    }
}
