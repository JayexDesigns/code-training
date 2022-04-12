#include "remove01.hpp"

typedef BinaryTree<int> BT;

int main()
{
  string s;
  while (cin >> s) {
  	BinaryTree<int> t;
   	readStringTree(s, t);
    BinaryTree<int> r = remove01(t);
    writeStringTree(cout, r); cout << endl;
  }
}
