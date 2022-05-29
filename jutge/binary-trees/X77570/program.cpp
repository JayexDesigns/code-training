#include "maximumTree.hpp"

int main()
{
  string s1,s2;
  while (cin>>s1>>s2) {
    BinaryTree<int> a1,a2;
    readStringTree(s1,a1);
    readStringTree(s2,a2);
    BinaryTree<int> a=maximumTree(a1,a2);
    writeStringTree(cout,a);
    cout<<endl;
  }
}
