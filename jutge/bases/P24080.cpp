#include <iostream>
#include <string>

using namespace std;

string repeatString(string text, int times) {
    string output;
    for (int i = 0; i < times; ++i) {
        output += text;
    }
    return output;
}

void drawSquare(int size) {
    for (int i = 0; i < size; ++i) {
        string out = repeatString(to_string(size), size);
        cout << out << endl;
    }
}

int main() {
    int size;
    bool firstUse = true;
    while (cin >> size) {
        if (!firstUse) {
            cout << endl;
        }
        drawSquare(size);
        firstUse = false;
    }

    return 0;
}