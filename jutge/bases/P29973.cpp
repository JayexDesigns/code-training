#include <iostream>
#include <string>

using namespace std;

int main() {
    int size;
    cin >> size;
    for (int i = 1; i <= size; ++i) {
        string line(i, '*');
        cout << line << endl;
    }
    return 0;
}