#include <iostream>
#include <list>
#include "arbreBin.hpp"
#include "listIOint.hpp"

using namespace std;

list<int> previousElements(const arbreBin<int> &a, int x) {
    if (a.es_buit()) return {};
    else if (a.arrel() == x) {
        list<int> l;
        l.push_back(a.arrel());
        return l;
    }
    list<int> l1 = previousElements(a.fe(), x);
    list<int> l2 = previousElements(a.fd(), x);
    if (!l1.empty()) {
        l1.push_back(a.arrel());
        return l1;
    }
    if (!l2.empty()) {
        l2.push_back(a.arrel());
        return l2;
    }
    return {};
}

int main() {
    arbreBin<int> a;
    cin >> a;
    cout << a << endl;
    int n;
    while (cin >> n) {
        list<int> l = previousElements(a, n);
        if (!l.empty()) l.pop_front();
        cout << l;
    }
    return 0;
}