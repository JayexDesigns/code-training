#include "llista.hpp"

using namespace std;

Llista::Llista(const vector<int> &v) {
    _long = v.size();
    _prim = NULL;
    if (_long == 0) return;
    _prim = new node;
    _prim->info = v[0];
    _prim->seg = NULL;
    node* pAux = _prim;
    for (int i = 1; i < int(v.size()); ++i) {
        pAux->seg = new node;
        pAux->seg->info = v[i];
        pAux->seg->seg = NULL;
        pAux = pAux->seg;
    }
}