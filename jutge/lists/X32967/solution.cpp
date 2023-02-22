#include "llista.hpp"

using namespace std;

Llista::Llista(const vector<int> &v) {
    _long = v.size();
    _prim = NULL;
    _prim = new node;
    _prim->seg = _prim;
    _prim->ant = _prim;
    if (_long == 0) return;
    node* pAux = _prim;
    for (int i = 0; i < int(v.size()); ++i) {
        pAux->seg = new node;
        pAux->seg->info = v[i];
        pAux->seg->ant = pAux;
        pAux->seg->seg = NULL;
        pAux = pAux->seg;
    }
    pAux->seg = _prim;
    pAux->seg->ant = pAux;
}