#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "BinaryTree.hpp"
#include "posInTree.hpp"

int main()
{
    string s;
    int x;
    while (cin >> s >> x) {
        BinaryTree<int> t;
        readStringTree(s, t);
        list<int> L = posInTree(t, x);
        bool writespace = false;
        for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
            if (writespace) cout << " ";
        	writespace = true;
            cout << *it;
        }
        cout << endl;
    }
}
