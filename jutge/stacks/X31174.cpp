#include <iostream>
#include <stack>

using namespace std;

void removeElements(stack<int> &s) {
    if (!s.empty()) {
        int elem = s.top();
        s.pop();
        bool remove = false;
        if ((elem == 0 && (s.size()+1) % 2 == 1) || (elem == 1 && (s.size()+1) % 2 == 0)) remove = true;
        removeElements(s);
        if (!remove) s.push(elem);
    }
}

stack<int> remove01(stack<int> s) {
    removeElements(s);
    return s;
}

int main() {
    return 0;
}