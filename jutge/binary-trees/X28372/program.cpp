#include <list>

using namespace std;

#include "longestLeftmostPath.hpp"

typedef BinaryTree<int> BT;

int main()
{
	string s;
	while (cin >> s) {
    	BinaryTree<int> t;
    	readStringTree(s, t);
    	list<int> l;
        for (int steps = 0; steps < 10; steps++)
            l = longestLeftmostPath(t);
        bool writespace = false;
        cout << "[";
        for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
            if (writespace) cout << ",";
            writespace = true;
            cout << *it;
        }
        cout << "]" << endl;
	}
}
