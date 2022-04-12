#include "subPila.hpp"

bool subPila(stack<int> p1, stack<int> p2) {
    if (p1.empty() && !p2.empty()) return false;
    else if (p2.empty()) return true;
    else if (p1.top() == p2.top()) {
        p1.pop();
        int n = p2.top();
        p2.pop();
        if (!(p1.empty() && !p2.empty()) && (p2.empty() || p1.top() == p2.top()) && subPila(p1, p2)) return true;
        else {
            p2.push(n);
            if (subPila(p1, p2)) return true;
            return false;
        }
    }
    else {
        p1.pop();
        if (subPila(p1, p2)) return true;
        else return false;
    }
}