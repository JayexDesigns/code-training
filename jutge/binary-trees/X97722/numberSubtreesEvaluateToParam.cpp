#include "numberSubtreesEvaluateToParam.hpp"

BinaryTree<string> numberSubtrees(const BinaryTree<string>& t, const int& x, int& res) {
    if (t.isEmpty()) return BinaryTree<string>();
    BinaryTree<string> l = numberSubtrees(t.getLeft(), x, res);
    BinaryTree<string> r = numberSubtrees(t.getRight(), x, res);
    if (t.getRoot() == "+" || t.getRoot() == "-" || t.getRoot() == "*") {
        int resOperation = 0;
        if (t.getRoot() == "+") {
            resOperation = (
                l.isEmpty() ? 0 : stoi(l.getRoot())
            ) + (
                r.isEmpty() ? 0 : stoi(r.getRoot())
            );
            if (resOperation == x) ++res;
        }
        else if (t.getRoot() == "-") {
            resOperation = (
                l.isEmpty() ? 0 : stoi(l.getRoot())
            ) - (
                r.isEmpty() ? 0 : stoi(r.getRoot())
            );
            if (resOperation == x) ++res;
        }
        else if (t.getRoot() == "*") {
            resOperation = (
                l.isEmpty() ? 0 : stoi(l.getRoot())
            ) * (
                r.isEmpty() ? 0 : stoi(r.getRoot())
            );
            if (resOperation == x) ++res;
        }
        return BinaryTree<string>(to_string(resOperation), BinaryTree<string>(), BinaryTree<string>());
    }
    else if (stoi(t.getRoot()) == x) ++res;
    return t;
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna el nombre de subarbres de t que s'avaluen a x.
int numberSubtreesEvaluateToParam(const BinaryTree<string> &t, int x) {
    int res = 0;
    numberSubtrees(t, x, res);
    return res;
}