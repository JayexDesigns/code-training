#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {

public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Pre: La clau k existeix al diccionari i té successor.
    // Post: Retorna la clau successora de la clau k.
    Clau successor(const Clau &k) const;

private:
    struct node {
    Clau _k;      // Clau
    node* _esq;   // fill esquerre
    node* _dret;  // fill dret
    nat _n;       // Nombre de nodes del subarbre
    node(const Clau &k, node* esq = NULL, node* dret = NULL);
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k, bool &ins);

    // Aquí va l’especificació dels mètodes privats addicionals
    // Pre: La clau k existeix al diccionari i té successor, la clau res es igual a la clau k.
    // Post: Guarda a res la clau successora de la clau k.
    // Cost: O(log(n))
    void successor_recursiu(node* n, const Clau &k, Clau &res) const;
};

// Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
Clau dicc<Clau>::successor(const Clau &k) const {
    Clau res = k;
    successor_recursiu(_arrel, k, res);
    return res;
}

template <typename Clau>
void dicc<Clau>::successor_recursiu(node* n, const Clau &k, Clau &res) const {
    if (n == nullptr) return;
    successor_recursiu(n->_esq, k, res);
    successor_recursiu(n->_dret, k, res);
    if (n->_k > k) if (res == k || n->_k < res) res = n->_k;
}
