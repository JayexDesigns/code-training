#include "longestLeftmostPath.hpp"

list<int> longest(const BinaryTree<int>& t) {
    if (t.isEmpty()) return {};

    list<int> ll = longest(t.getLeft());
    list<int> rl = longest(t.getRight());

    if (rl.size() > ll.size()) {
        rl.push_front(t.getRoot());
        return rl;
    }
    else {
        ll.push_front(t.getRoot());
        return ll;
    }
}

list<int> longestLeftmostPath(BinaryTree<int> t) {
    list<int> l = longest(t);
    return l;
}