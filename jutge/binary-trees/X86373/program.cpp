#include "arbreBin.hpp"

using namespace std;

arbreBin<int> reverse(const arbreBin<int> &a) {
    if (a.es_buit()) return arbreBin<int>();
    return arbreBin<int>(a.arrel(), reverse(a.fd()), reverse(a.fe()));
}

bool checkEqual(const arbreBin<int> &a, const arbreBin<int> &b) {
    if (a.es_buit() && b.es_buit()) return true;
    else if (a.es_buit() && !b.es_buit()) return false;
    else if (!a.es_buit() && b.es_buit()) return false;
    if (a.arrel() != b.arrel()) return false;
    if (!checkEqual(a.fe(), b.fe())) return false;
    if (!checkEqual(a.fd(), b.fd())) return false;
    return true;
}

int main() {
    arbreBin<int> a;
    cin >> a;
    cout << a << endl;

    arbreBin<int> b = reverse(a);
    bool res = checkEqual(a, b);
    if (res) cout << "L'arbre és simètric" << endl;
    else cout << "L'arbre no és simètric." << endl;

    return 0;
}