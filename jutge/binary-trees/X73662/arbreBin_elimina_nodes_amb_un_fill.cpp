#include "arbreBin.hpp"

void removeNodes(arbreBin *a) {
    if ((*a).es_buit()) return;
    else if ((*a).fe().es_buit() && (*a).fd().es_buit()) return;
    else if ((*a).fe().es_buit() && !(*a).fd().es_buit()) {
        *a = (*a).fd();
        removeNodes(a);
    }
    else if (!(*a).fe().es_buit() && (*a).fd().es_buit()) {
        *a = (*a).fe();
        removeNodes(a);
    }
    else {
        arbreBin *a1 = new arbreBin();
        arbreBin *a2 = new arbreBin();
        *a1 = (*a).fe();
        *a2 = (*a).fd();
        removeNodes(a1);
        removeNodes(a2);
        (*a) = arbreBin((*a).arrel(), (*a1), (*a2));
    }
}

void arbreBin::elimina_nodes_amb_un_fill() {
    removeNodes(this);
}