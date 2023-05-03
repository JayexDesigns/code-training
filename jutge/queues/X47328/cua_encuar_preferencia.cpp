#include "cua.hpp"

void Cua::encuar_preferencia(const int &elem) {
    node_cua *n = new node_cua;
    n->info = elem;
    node_cua *n2 = this->primer_node;
    if (n2 == NULL) {
        n->seguent = NULL;
        this->primer_node = n;
    }
    else if (n2->info == elem) {
        n->seguent = n2;
        this->primer_node = n;
    }
    else {
        while (n2 != NULL) {
            if (n2->seguent == NULL) {
                n->seguent = NULL;
                n2->seguent = n;
                break;
            }
            else if (n2->seguent->info == elem) {
                n->seguent = n2->seguent;
                n2->seguent = n;
                break;
            }
            n2 = n2->seguent;
        }
    }
    ++longitud;
}