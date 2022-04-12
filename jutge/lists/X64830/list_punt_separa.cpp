#include "list_punt_separa.hpp"

void separa(list<Punt> &lp, float x, list<Punt> &lp1, list<Punt> &lp2) {
    while (!lp.empty()) {
        if (x > lp.front().coordenadax()) lp1.push_back(lp.front());
        else if (x < lp.front().coordenadax()) lp2.push_back(lp.front());
        lp.pop_front();
    }
}
