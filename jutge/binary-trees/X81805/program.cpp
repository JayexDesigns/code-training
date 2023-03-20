#include <iostream>
#include "arbreBin.hpp"

using namespace std;

arbreBin<int> sumTree(const arbreBin<int> &t1) {
    if (t1.es_buit()) return arbreBin<int>();

    arbreBin<int> r1 = sumTree(t1.fe());
    arbreBin<int> r2 = sumTree(t1.fd());

    arbreBin<int> r = arbreBin<int>(t1.arrel() + (!r1.es_buit() ? r1.arrel() : 0) + (!r2.es_buit() ? r2.arrel() : 0), r1, r2);

    return r;
}

int main() {
    arbreBin<int> t1;
    cin >> t1;
    arbreBin<int> t2 = sumTree(t1);
    cout << t2 << endl;
    return 0;
}