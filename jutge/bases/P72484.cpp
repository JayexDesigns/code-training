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

int main() {
    int sideSize;
    cin >> sideSize;
    int size = sideSize * 2 -1;
    
    for (int i = 1; i <= size; ++i) {
        string line;
        if (i <= sideSize) {
            line = repeatString(" ", sideSize-i);
            line += repeatString("*", i*2-1);
        }
        else {
            line = repeatString(" ", sideSize-(size-i+1));
            line += repeatString("*", (size-i+1)*2-1);
        }
        cout << line << endl;
    }

    return 0;
}