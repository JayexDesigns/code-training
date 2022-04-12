#include <iostream>

using namespace std;

void recursionPrint() {
    string word;
    if (cin >> word) {
        recursionPrint();
        cout << word << endl;
    }
}

int main() {
    recursionPrint();
    return 0;
}