#include "numberSubtreesEvaluateToParam.hpp"

int main()
{
  string s;
  int x;
  while (cin >> s >> x) {
    BinaryTree<string> t;
    readStringTree(s, t);
    cout << numberSubtreesEvaluateToParam(t, x) << endl;
  }
}
