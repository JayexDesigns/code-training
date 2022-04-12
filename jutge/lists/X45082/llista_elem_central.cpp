#include "llista_elem_central.hpp"

using namespace std;

int elem(list<int> &l) {
    if (l.size() == 1) return l.front();
    if (l.size() % 2 == 0) l.pop_back();
    else if (l.size() % 2 == 1) l.pop_front();
    return elem(l);
}

int elem_central(const list<int> &l) {
    list<int> tmp = l;
    int n = elem(tmp);
    return n;
}