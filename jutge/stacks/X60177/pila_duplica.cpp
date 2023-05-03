#include "pila.hpp"

void Pila::duplica() {
    node_pila *n1 = this->primer_node;
    while (n1 != NULL) {
        node_pila *n2 = new node_pila;
        n2->info = n1->info;
        n2->seguent = n1->seguent;
        n1->seguent = n2;
        n1 = n2->seguent;
        ++altura;
    }
}

// void Pila::empilar(const int &x) {
//     node_pila *n = new node_pila;
//     n->info = x;
//     n->seguent = primer_node;
//     primer_node = n;
//     ++altura;
// }