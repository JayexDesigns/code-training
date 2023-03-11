#include "llista.hpp"

using namespace std;

void Llista::separa(Llista &l2) {
    if (_long <= 0) return;
    int counter = 0;
    node* pNode1 = _prim;
    node* pNode1Prev = _prim;
    node* pNode2 = l2._prim;
    while (pNode1 != NULL) {
        if (counter % 2 != 0) {
            if (l2._long <= 0) {
                l2._prim = new node;
                pNode2 = l2._prim;
            }
            else {
                pNode2->seg = new node;
                pNode2 = pNode2->seg;
            }
            pNode2->info = pNode1->info;
            pNode2->seg = NULL;
            ++l2._long;

            node* pAux = pNode1;
            pNode1Prev->seg = pNode1->seg;
            pNode1 = pNode1->seg;
            delete pAux;
            --_long;
        }
        else {
            pNode1 = pNode1->seg;
            if (counter != 0) pNode1Prev = pNode1Prev->seg;
        }
        ++counter;
    }
}