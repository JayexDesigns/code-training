#include "heightOfTree.hpp"

using namespace std;

int height(const BinaryTree<int> &t) {
    if (t.isEmpty()) return 0;
    int n1 = height(t.getLeft()), n2 = height(t.getRight());
    return 1 + ((n1 > n2) ? n1 : n2);
}

int heightOfTree(BinaryTree<int> t) {
    return height(t);
}