#include <iostream>

using namespace std;

int main() {
    char a;
    cin >> a;
    char out;
    if (a >= 65 && a <= 90) {
        out = a + 32;
    }
    else if (a >= 97 && a <= 122) {
        out = a - 32;
    }
    cout << out << endl;
    return 0;
}