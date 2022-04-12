#include <iostream>
#include <string>
#include <sstream>
#include "stackIOpunt.hpp"

using namespace std;

int main() {
    stack<Punt> s;
    cin >> s;
    cout << s;

    float n1, n2;
    stack<Punt> tmp;
    while (cin >> n1 >> n2) {
        tmp = s;
        bool found = false;
        while (!tmp.empty() && !found) {
            if (tmp.top().coordenadax() == n1 && tmp.top().coordenaday() == n2) found = true;
            else tmp.pop();
        }
        cout << "El punt (" << n1 << ", " << n2 << ") ";
        if (!found) cout << "no ";
        cout << "es troba en la pila." << endl;
    }

    return 0;
}