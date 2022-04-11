#include <iostream>
#include <string>

using namespace std;

int main() {
    int a;
    cin >> a;
    string out = "";
    for (int i = 0; i <= a; ++i) {
        out += std::to_string(i*i*i);
        if (i != a) {
            out += ",";
        }
    }
    cout << out << endl;
}