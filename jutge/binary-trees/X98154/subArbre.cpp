#include "subArbre.hpp"

using namespace std;

bool sub(const arbreBin<int> &a, const arbreBin<int> &b) {
    if (a.es_buit() && !b.es_buit()) return false;
    else if (a.es_buit() && b.es_buit()) return true;
    else if (!a.es_buit() && b.es_buit()) return true;
    else if (a.arrel() == b.arrel()) {
        if (sub(a.fe(), b.fe()) && sub(a.fd(), b.fd())) return true;
        else {
            if (sub(a.fe(), b)) return true;
            if (sub(a.fd(), b)) return true;
            return false;
        }
    }
    else if (sub(a.fe(), b) || sub(a.fd(), b)) return true;
    else return false;
}

bool subArbre(arbreBin<int> A, arbreBin<int> B) {
    return sub(A, B);
}