#include "sizeOfTree.hpp"

// Pre:
// Post: Retorna la mida de t
int size(BinaryTree<int>& t) {
    if (t.isEmpty()) return 0;
    return 1 + size(t.getLeft()) + size(t.getRight());
}

int sizeOfTree(BinaryTree<int> t) {
    return size(t);
}
