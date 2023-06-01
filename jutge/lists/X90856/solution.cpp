#include "llista.hpp"

void Llista::inverteix() {
	node *ptr = _prim;
	do {
		node *aux = ptr->ant;
		ptr->ant = ptr->seg;
		ptr->seg = aux;
		ptr = ptr->ant;
	} while (ptr != _prim);
}
