#include "stackIOpunt.hpp"

ostream& operator<<(ostream& os, stack<Punt> p) {
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        os << p.top();
        if (i < n-1) os << "|";
        p.pop();
    }
    os << "]" << endl;
    return os;
}

istream& operator>>(istream &is, stack<Punt> &p) {
    int n;
    is >> n;
    for (int i = 0; i < n ; ++i) {
        Punt e;
        is >> e;
        p.push(e);
    }
    return is;
}
