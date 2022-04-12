#include "sumOfTree.hpp"

typedef BinaryTree<int> BT;

int main()
{
  string s;
  while (cin >> s) {
    BinaryTree<int> t;
    readStringTree(s, t);
    cout << sumOfTree(t) << endl;
  }
}
