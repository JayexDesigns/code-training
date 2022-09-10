#include <iostream>

using namespace std;

void printPattern(int n) {
    if (n == 1) cout << '*' << endl;
    else {
        printPattern(n-1);
        printPattern(n-1);
        for (int i = 0; i < n; ++i) cout << '*';
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}