#include "arbreBin.hpp"
#include "Punt.hpp"

arbreBin<Punt> reverse(const arbreBin<Punt> &a) {
    if (a.es_buit()) return arbreBin<Punt>();
    return arbreBin<Punt>(Punt(a.arrel().coordenaday(), a.arrel().coordenadax()), reverse(a.fe()), reverse(a.fd()));
}

int main() {
    arbreBin<Punt> a;
    cin >> a;

    arbreBin<Punt> b = reverse(a);

    cout << b << endl;
    return 0;
}