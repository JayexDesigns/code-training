#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    string out = "";
    cin >> a >> b;
    if (a <= b) {
        for (int i = a; i <= b; ++i) {
            out += std::to_string(i);
            if (i != b) {
                out += ",";
            }
        }
    }
    cout << out << endl;
}