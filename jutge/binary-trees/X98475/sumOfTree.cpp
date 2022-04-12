#include "sumOfTree.hpp"

// Pre:
// Post: Retorna la suma dels valors de t
int sum(BinaryTree<int>& t) {
    if (t.isEmpty()) return 0;
    return t.getRoot() + sum(t.getLeft()) + sum(t.getRight());
}

int sumOfTree(BinaryTree<int> t) {
    return sum(t);
}
