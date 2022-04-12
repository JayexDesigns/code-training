#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m;
    char type;
    while (cin >> type) {
        if (type == 'a') {
            string input;
            cin >> input;
            if (m[input] == 0) m[input] = 1;
            else ++m[input];
        }
        else if (type == 'f') {
            string input;
            cin >> input;
            cout << m[input] << endl;
        }
    }
	return 0;
}
