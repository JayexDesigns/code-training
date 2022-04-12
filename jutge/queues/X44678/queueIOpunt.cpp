#include "queueIOpunt.hpp"

ostream& operator<<(ostream& os, queue<Punt> q) {   
    os << "<";
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        os << q.front() << "|";
        q.pop();
    }
    os << "<" << endl;
    return os;
}

istream& operator>>(istream &is, queue<Punt> &q) {
    int n;
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        Punt e;
        is >> e;
        q.push(e);
    }
    return is;
}
