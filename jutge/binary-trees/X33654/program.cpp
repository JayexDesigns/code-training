#include "reverseTree.hpp"

typedef BinaryTree<int> BT;

int main()
{
  string s;
  while (cin >> s) {
    BinaryTree<int> t;
    readStringTree(s, t);
    writeStringTree(cout,reverseTree(t)); cout << endl;
  }
}
