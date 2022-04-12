#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        istringstream stream(input);
        int n;

        stack <int> even;
        stack <int> odd;
        while(stream >> n) {
            if (n % 2 == 0) even.push(n);
            else odd.push(n);
        }

        while (!even.empty()) {
            cout << even.top();
            even.pop();
            if (odd.empty() && !even.empty() || !odd.empty()) cout << " ";
        }

        while (!odd.empty()) {
            cout << odd.top();
            odd.pop();
            if (!odd.empty()) cout << " ";
        }

        cout << endl;
    }
    return 0;
}