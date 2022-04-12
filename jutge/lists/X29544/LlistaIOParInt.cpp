#include "LlistaIOParInt.hh"

ostream& operator<<(ostream &os, const list<ParInt> &l) {
    os << "[";
    for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it) {
        if (it!=l.begin()) os << ",";
        os << '(' << (*it).primer() << ", " << (*it).segon() << ')';
    }
    os << "]" << endl;
    return os;
}

istream& operator>>(istream &is, list<ParInt> &l) {
    list<ParInt>::iterator it = l.begin();
    while (true) {
        ParInt e;
        e.llegir();
        if (e.primer() == 0 && e.segon() == 0) break;
        l.insert(it,e);
    }
    return is;
}
