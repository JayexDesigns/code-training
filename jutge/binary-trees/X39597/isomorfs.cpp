#include "isomorfs.hpp"

using namespace std;

bool iso(const arbreBin<int> &a, const arbreBin<int> &b) {
    if (a.es_buit() && b.es_buit()) return true;
    else if (a.es_buit() && !b.es_buit()) return false;
    else if (!a.es_buit() && b.es_buit()) return false;
    if (!iso(a.fe(), b.fe())) return false;
    if (!iso(a.fd(), b.fd())) return false;
    return true;
}

bool isomorfs(arbreBin<int> &a, arbreBin<int> &b) {
    return iso(a, b);
}