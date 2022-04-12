#include <iostream>

using namespace std;

void recursionPrint(int n) {
    if (n > 0) {
        string word;
        cin >> word;
        recursionPrint(n - 1);
        cout << word << endl;
    }
}

int main() {
    int n;
    cin >> n;
    recursionPrint(n);
    return 0;
}