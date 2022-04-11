#include <iostream>
#include <string>

using namespace std;

string repeatString(string text, int times) {
    string out = "";
    for (int i = 0; i < times; ++i) {
        out += text;
    }
    return out;
}

void cross(int n, char c) {
    for (int i = 0; i < n; ++i) {
        if (i == n/2) {
            string character(1, c);
            cout << repeatString(character, n) << endl;
        }
        else {
            cout << repeatString(" ", n/2) << c << endl;
        }
    }
}

int main() {
    cross(9, '+');
    return 0;
}