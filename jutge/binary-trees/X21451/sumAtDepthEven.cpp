#include "sumAtDepthEven.hpp"

int sumEven(const BinaryTree<int> &t) {
    if (t.isEmpty()) return 0;
    int sum = 0;
    sum += t.getRoot();

    if (!t.getLeft().isEmpty()) {
        sum += sumEven(t.getLeft().getLeft());
        sum += sumEven(t.getLeft().getRight());
    }
    if (!t.getRight().isEmpty()) {
        sum += sumEven(t.getRight().getLeft());
        sum += sumEven(t.getRight().getRight());
    }

    return sum;
}

int sumAtDepthEven(BinaryTree<int> t) {
    return sumEven(t);
}