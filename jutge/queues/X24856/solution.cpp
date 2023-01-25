#include <iostream>
#include "cua.hpp"

using namespace std;

cua::cua(const vector<int> &v) {
    _long = v.size();
    _ult = NULL;
    if (_long == 0) return;
    _ult = new node;
    _ult->info = v[0];
    _ult->seg = NULL;
    node* pAux = _ult;
    for (int i = 1; i < int(v.size()); ++i) {
        pAux->seg = new node;
        pAux->seg->info = v[i];
        pAux->seg->seg = NULL;
        pAux = pAux->seg;
    }
    pAux->seg = _ult;
    _ult = pAux;
}