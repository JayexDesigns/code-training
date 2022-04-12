#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    queue<int> q;
    string line;
    while (getline(cin, line)) {
        istringstream stream(line);
        int n;
        int sum = 0;
        while (stream >> n) {
            if (n <= sum) q.push(n);
            sum += n;
        }
        while (!q.empty()) {
            cout << q.front();
            q.pop();
            if (!q.empty()) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}