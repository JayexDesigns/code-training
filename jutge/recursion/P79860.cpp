#include <iostream>

using namespace std;

void printPattern(int n) {
    if (n == 1) cout << '*' << endl;
    else {
        for (int i = 0; i < n; ++i) cout << '*';
        cout << endl;
        printPattern(n-1);
        printPattern(n-1);
    }
}

int main() {
    int n;
    cin >> n;
    printPattern(n);
    return 0;
}