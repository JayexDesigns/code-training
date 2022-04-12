#include "arbreBin.hpp"

bool treeSum(const arbreBin &a) {
    if (a.es_buit()) return true;
    int sum = 0;
    sum += (a.fe().es_buit() ? 0 : a.fe().arrel());
    sum += (a.fd().es_buit() ? 0 : a.fd().arrel());
    if (!(a.fe().es_buit() && a.fd().es_buit()) && sum != a.arrel()) return false;

    if (!treeSum(a.fe())) return false;
    if (!treeSum(a.fd())) return false;

    return true;
}

bool arbreBin::compleix_suma_fills() const {
    return treeSum(*this);
}