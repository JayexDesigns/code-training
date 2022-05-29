#include "treeOfHeights.hpp"

int heights(BinaryTree<int>& t) {
    if (t.isEmpty()) return 0;

    int n1 = heights(t.getLeft());
    int n2 = heights(t.getRight());

    int max = n1;
    if (n2 > n1) max = n2;

    t.getRoot() = ++max;

    return max;
}

BinaryTree<int> treeOfHeights(BinaryTree<int> t) {
    heights(t);
    return t;
}