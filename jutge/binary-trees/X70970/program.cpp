#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "BinaryTree.hpp"
#include "searchInBST.hpp"

int main()
{
    string s;
    cin >> s;
    BinaryTree<int> t;
    readStringTree(s, t);
    int x;
    while (cin >> x) {
		if (searchInBST(t, x)) cout << "Exists" << endl;
        else cout << "Do not exist" << endl;
    }
}
