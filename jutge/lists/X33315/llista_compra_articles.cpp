#include "llista_compra_articles.hpp"

int compra(list<int> &l, int &x) {
    if (l.empty()) return 0;
    if (l.front() > x) {
        l.pop_front();
        return compra(l, x);
    }
    else {
        x -= l.front();
        l.pop_front();
        return 1 + compra(l, x);
    }
}

int compra_articles(const list<int> &l, int x) {
    list<int> tmp = l;
    int n = compra(tmp, x);
    return n;
}