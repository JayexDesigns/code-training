#include <list>

using namespace std;

#include "treeOfHeights.hpp"

typedef BinaryTree<int> BT;

int main()
{
	string s;
	while (cin >> s) {
    	BinaryTree<int> t, r;
    	readStringTree(s, t);
        for (int steps = 0; steps < 10; steps++)
            r = treeOfHeights(t);
        writeStringTree(cout, r);
        cout << endl;
	}
}
