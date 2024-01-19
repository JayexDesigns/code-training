#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
	// Graf dirigit i no etiquetat.
	// Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
public:
	// Constructora per defecte. Crea un graf buit de n vèrtexs.
	graf(nat n);

	// Destructora
	~graf();

	// Retorna un vector amb els successors del vèrtex v
	vector<nat> successors(nat v) const;

	// Retorna un vector amb els predecessors del vèrtex v
	vector<nat> predecessors(nat v) const;

	void insereix(nat orig, nat dest);
	// Pre: orig i dest són menors que el número de vèrtexs
	// Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
	// Si l’aresta ja existia no fa res.

private:
	nat nv; // Nombre de vèrtexs
	struct node
	{
		nat orig;		// Vèrtex origen
		nat dest;		// Vèrtex destí
		node *seg_succ; // Punter al següent successor
		node *seg_pred; // Punter al següent predecessor
	};
	vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
							  // La llista de successors està ordenada.
	vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
							  // La llista de predecessors està ordenada.

	// Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic insereix i privats addicionals
// Pre: orig i dest són menors que el número de vèrtexs
// Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
// Si l’aresta ja existia no fa res.
void graf::insereix(nat orig, nat dest) {
	node *ptr = prim_succ[orig], *ptr_prev = nullptr;
	bool found = false;
	while (ptr != nullptr && ptr->dest <= dest && !found) {
		found = ptr->dest == dest;
		ptr_prev = ptr;
		ptr = ptr->seg_succ;
	}
	if (!found) {
		node *ptr_new = new node;
		ptr_new->orig = orig;
		ptr_new->dest = dest;
		if (ptr_prev == nullptr) {
			ptr_new->seg_succ = prim_succ[orig];
			prim_succ[orig] = ptr_new;
		}
		else {
			ptr_new->seg_succ = ptr_prev->seg_succ;
			ptr_prev->seg_succ = ptr_new;
		}
		ptr = prim_pred[dest];
		ptr_prev = nullptr;
		while (ptr != nullptr && ptr->orig <= orig) {
			ptr_prev = ptr;
			ptr = ptr->seg_pred;
		}
		if (ptr_prev == nullptr) {
			ptr_new->seg_pred = prim_pred[dest];
			prim_pred[dest] = ptr_new;
		}
		else {
			ptr_new->seg_pred = ptr_prev->seg_pred;
			ptr_prev->seg_pred = ptr_new;
		}
	}
}
