#include "llista.hpp"

void Llista::inserir_en_ordre(const int &x) {
    node_llista *a = this->primer_node;
    node_llista *a2 = new node_llista;
    a2->info = x;
    if (a == NULL) {
        a2->ant = NULL;
        a2->seg = NULL;
        this->primer_node = a2;
        this->ultim_node = a2;
    }
    else if (x <= a->info) {
        a2->ant = NULL;
        a2->seg = a;
        a->ant = a2;
        this->primer_node = a2;
        if (this->act != NULL && this->act->info == x) this->act = a2;
    }
    else {
        while (a != NULL) {
            if (x <= a->info) {
                node_llista *a3 = a->ant;
                a->ant = a2;
                a3->seg = a2;
                a2->ant = a3;
                a2->seg = a;
                if (this->act != NULL && this->act->info == x) this->act = a2;
                break;
            }
            else if (a->seg == NULL) {
                a->seg = a2;
                a2->ant = a;
                a2->seg = NULL;
                this->ultim_node = a2;
                break;
            }
            a = a->seg;
        }
    }
    ++this->longitud;
}