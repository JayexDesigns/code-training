#include "remove01.hpp"

void removeElements(const BinaryTree<int> &t, BinaryTree<int> &r) {
    if (t.isEmpty()) {
        r = BinaryTree<int>();
        return;
    }
    int root = t.getRoot();
    if (root == 0) {
        removeElements(t.getLeft(), r);
        return;
    }
    if (root == 1) {
        removeElements(t.getRight(), r);
        return;
    }
    r = BinaryTree<int>(root, BinaryTree<int>(), BinaryTree<int>());
    removeElements(t.getLeft(), r.getLeft());
    removeElements(t.getRight(), r.getRight());
}

BinaryTree<int> remove01(BinaryTree<int> t) {
    BinaryTree<int> r = BinaryTree<int>();
    removeElements(t, r);
    return r;
}