#include <iostream>
#include "arbreBin.hpp"

using namespace std;

bool sumTree(const arbreBin<int> &t) {
    if (t.es_buit()) return true;
    if (!sumTree(t.fe()) || !sumTree(t.fd())) return false;

    int sum = 0;
    if (!t.fe().es_buit()) sum += t.fe().arrel();
    if (!t.fd().es_buit()) sum += t.fd().arrel();
    if (t.fe().es_buit() && t.fd().es_buit()) return true;
    else if (t.arrel() == sum) return true;

    return false;
}

int main() {
    arbreBin<int> t;
    cin >> t;
    cout << t << endl;
    cout << (sumTree(t) ? "L'arbre compleix la propietat 'Suma dels fills'." : "L'arbre no compleix la propietat 'Suma dels fills'.") << endl;
    return 0;
}