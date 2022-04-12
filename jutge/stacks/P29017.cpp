#include <iostream>
#include <stack>

using namespace std;

void print_from_top_to_bottom(stack<int>& S) {
    while (!S.empty()) {
        cout << S.top();
        S.pop();
        if (!S.empty()) cout << " ";
    }
    cout << endl;
}

void print_from_bottom_to_top(stack<int>& S) {
    stack<int> T;
    while (!S.empty()) {
        T.push(S.top());
        S.pop();
    }
    print_from_top_to_bottom(T);
}

int main() {
    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
    print_from_bottom_to_top(stack);
    return 0;
}