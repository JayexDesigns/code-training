#include <iostream>

using namespace std;

void power(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; ++i) {
        res *= a;
    }
    cout << res << endl;
}

int main() {
    int num0, num1;
    while (cin >> num0 >> num1) {
        power(num0, num1);
    }

    return 0;
}