#include "llista.hpp"

void Llista::inverteix() {
    node_llista *a = this->primer_node;
    this->primer_node = this->ultim_node;
    this->ultim_node = a;
    while (a != NULL) {
        node_llista *tmp = a->seg;
        a->seg = a->ant;
        a->ant = tmp;
        a = a->ant;
    }
}

// void Llista::eliminar() {
//     node_llista* aux;
//     aux = act;
//     if (longitud == 1) {
//         primer_node = NULL;
//         ultim_node = NULL;
//     }
//     else if (act == primer_node) {
//     primer_node = act->seg;
//     primer_node->ant = NULL;
//     }
//     else if (act == ultim_node) {
//     ultim_node = act->ant;
//     ultim_node->seg = NULL;
//     }
//     else {
//     (act->ant)->seg = act->seg;
//     (act->seg)->ant = act->ant;
//     }
//     act = act->seg;
//     delete aux;
//     --longitud;
// }