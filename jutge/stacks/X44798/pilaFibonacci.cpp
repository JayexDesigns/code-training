#include "pilaFibonacci.hpp"
#include <iostream>

using namespace std;

int fibonacci(stack<int> &s, bool &res) {
    if (s.empty() || !res) return 1;
    else if (s.size() == 1 && s.top() == 1) return 1;
    else if (s.size() == 2) {
        int n1 = s.top();
        s.pop();
        int n2 = s.top();
        s.push(n1);
        if (n1 == 1 && n2 == 1) return 1;
        else {
            res = false;
            return 1;
        }
    }

    int top1 = s.top();
    s.pop();
    int n1 = fibonacci(s, res);
    int n2 = 1;
    if (!s.empty()) {
        int top2 = s.top();
        s.pop();
        n2 = fibonacci(s, res);
        s.push(top2);
    }
    s.push(top1);

    if (n1 + n2 != top1) {
        res = false;
        return 1;
    }

    return top1;
}

bool pilaFibonacci(stack<int> P) {
    bool res = true;
    fibonacci(P, res);
    return res;
}