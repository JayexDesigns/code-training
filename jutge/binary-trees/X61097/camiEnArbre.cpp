#include "camiEnArbre.hpp"

T cami(const arbreBin<int> &a, const int &x) {
    if (a.es_buit()) return T(false, {});
    if (a.arrel() != x) {
        T t1 = cami(a.fe(), x);
        T t2 = cami(a.fd(), x);
        if (t1.first) {
            t1.second.push(a.arrel());
            return t1;
        }
        if (t2.first) {
            t2.second.push(a.arrel());
            return t2;
        }
        return t1;
    }
    else {
        stack<int> s;
        s.push(a.arrel());
        return T(true, s);
    }
}

T camiEnArbre(arbreBin<int> a, int x) {
    return cami(a, x);
}