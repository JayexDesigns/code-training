#include "queueIOpunt.hpp"
#include "stackIOpunt.hpp"

using namespace std;

int main() {
    queue<Punt> q;
    while (cin >> q) {
        cout << q;
        stack<Punt> tmp;
        while (!q.empty()) {
            tmp.push(q.front());
            q.pop();
        }
        stack<Punt> s;
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
        cout << s;
    }

    return 0;
}