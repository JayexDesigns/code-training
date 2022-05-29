#include "treeOfSums.hpp"

int sums(BinaryTree<int> &t) {
    if (t.isEmpty()) return 0;

    int r1 = sums(t.getLeft());
    int r2 = sums(t.getRight());

    int sum = t.getRoot() + r1 + r2;

    t.getRoot() = sum;

    return sum;
}

BinaryTree<int> treeOfSums(BinaryTree<int> t) {
    sums(t);
    return t;
}