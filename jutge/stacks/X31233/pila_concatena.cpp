#include "pila_concatena.hpp"

void concatena_piles(stack<int> &p, stack<int> &q, stack<int> &concatp) {
    if (p.empty() && q.empty()) return;
    if (!p.empty()) {
        int n = p.top();
        p.pop();
        concatena_piles(p, q, concatp);
        concatp.push(n);
    }
    if (!q.empty()) {
        int n = q.top();
        q.pop();
        concatena_piles(p, q, concatp);
        concatp.push(n);
    }
}