#include <iostream>

using namespace std;

int main() {
    char type;
    cin >> type;
    if (type == 'p') {
        double a;
        cin >> a;
        if (a > 0.15) cout << "Ha de ser sancionat" << endl;
        else cout << "Pot continuar conduint" << endl;
    }
    else if (type == 'n') {
        double a;
        int t;
        cin >> a >> t;
        if (a > 0.15 && t < 2) cout << "Ha de ser sancionat" << endl;
        else if (a > 0.25 && t >= 2) cout  << "Ha de ser sancionat" << endl;
        else cout << "Pot continuar conduint" << endl;
    }
    return 0;
}