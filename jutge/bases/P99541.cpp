#include <iostream>
#include <string>

using namespace std;

void print(int s, char c, int n) {
    string output = "";

    for (int i = 0; i < s; ++i) {
        output += " ";
    }
    for (int i = 0; i < n; ++i) {
        output += c;
    }

    cout << output << endl;
}

int main() {
    print(2, 'A', 4);
    return 0;
}