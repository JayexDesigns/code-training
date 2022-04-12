#include "cua_elimina.hpp"

void elimina(queue<Punt> &c, Punt &p) {
    if (c.empty()) return;
    Punt tmp = c.front();
    c.pop();
    elimina(c, p);
    if (!(tmp == p)) c.push(tmp);
}

void reverseQueue(queue<Punt> &c) {
    if (c.empty()) return;
    Punt tmp = c.front();
    c.pop();
    reverseQueue(c);
    c.push(tmp);
}

queue<Punt> elimina_punts(queue<Punt> c, Punt p) {
    elimina(c, p);
    reverseQueue(c);
    return c;
}