#include "searchInBST.hpp"

bool searchInBST(BinaryTree<int> &t, int x) {
    if (t.isEmpty()) return false;
    else if (t.getRoot() > x) return searchInBST(t.getLeft(), x);
    else if (t.getRoot() < x) return searchInBST(t.getRight(), x);
    else if (t.getRoot() == x) return true;
}