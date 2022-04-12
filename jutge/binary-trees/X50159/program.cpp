#include "arbreBin.hpp"
#include "listIOint.hpp"
#include <list>

int main() {
    arbreBin<int> a;
    cin >> a;
    cout << a << endl;
    cout << endl << "Amplada: ";

    list<int> nodes;
    list< arbreBin<int> > toVisit;
    toVisit.push_back(a);
    while (!toVisit.empty()) {
        if (toVisit.front().es_buit()) {
            toVisit.pop_front();
            continue;
        }
        nodes.push_back(toVisit.front().arrel());
        toVisit.push_back(toVisit.front().fe());
        toVisit.push_back(toVisit.front().fd());
        toVisit.pop_front();
    }

    cout << nodes;
    return 0;
}