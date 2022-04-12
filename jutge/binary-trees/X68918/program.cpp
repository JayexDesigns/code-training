#include "arbreBin.hpp"

using namespace std;

int checkSum(const arbreBin<int> &a, bool &res) {
    if (a.es_buit()) return 0;
    if (a.fe().es_buit() && a.fd().es_buit()) return a.arrel();

    int sum1 = checkSum(a.fe(), res);
    int sum2 = checkSum(a.fd(), res);
    int sum = sum1 + sum2;

    if (sum != a.arrel()) res = false;

    return sum;
}

int main() {
    arbreBin<int> a;
    cin >> a;
    cout << a << endl;
    bool res = true;
    checkSum(a, res);
    cout << "L'arbre" << (res ? " " : " no ") << "compleix la propietat 'Suma dels fills'." << endl;
    return 0;
}