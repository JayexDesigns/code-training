#include "listIOpunt.hpp"

ostream& operator<<(ostream &os, const list<Punt> &l) {
    os << "[";
    for (list<Punt>::const_iterator it = l.begin(); it != l.end(); ++it) {
        if (it!=l.begin()) os << ",";
        os << (*it);
    }
    os << "]" << endl;
    return os;
}

istream& operator>>(istream &is, list<Punt> &l) {
    int n;
    is >> n;
    list<Punt>::iterator it = l.begin();
    while (n>0) {
        Punt e;
        is >> e;
        l.insert(it,e);
        --n;
    }
    return is;
}
