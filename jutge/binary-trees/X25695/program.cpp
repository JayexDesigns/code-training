#include <queue>
#include "arbreBin.hpp"

using namespace std;

bool isBST(const arbreBin<int> &a) {
    if (a.es_buit()) return true;

    queue< arbreBin<int> > nodesLeft;
    queue< arbreBin<int> > nodesRight;
    nodesLeft.push(a.fe());
    nodesRight.push(a.fd());
    while (!nodesLeft.empty()) {
        if (!nodesLeft.front().es_buit()) {
            if (a.arrel() <= nodesLeft.front().arrel()) return false;
            nodesLeft.push(nodesLeft.front().fe());
            nodesLeft.push(nodesLeft.front().fd());
        }
        nodesLeft.pop();
    }
    while (!nodesRight.empty()) {
        if (!nodesRight.front().es_buit()) {
            if (a.arrel() >= nodesRight.front().arrel()) return false;
            nodesRight.push(nodesRight.front().fe());
            nodesRight.push(nodesRight.front().fd());
        }
        nodesRight.pop();
    }

    if (!isBST(a.fe())) return false;
    if (!isBST(a.fd())) return false;

    return true;
}

int main() {
    arbreBin<int> a;
    cin >> a;
    cout << a << endl;

    bool res = isBST(a);
    if (res) cout << "L'arbre és un arbre binari de cerca." << endl;
    else cout << "L'arbre no és un arbre binari de cerca." << endl;

    return 0;
}
