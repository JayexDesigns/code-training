#include <iostream>
#include <vector>

using namespace std;
typedef unsigned int nat;

template <typename T>
class pila { // pila en memòria dinàmica
public:
    pila();
    // Crea pila buida

    ~pila();
    // Destrueix el p.i.

    pila(const vector<int> &v);
    // Crea pila amb els elements de v amb el mateix ordre.

    nat longitud() const;
    // Retorna el nombre d’elements del p.i.

    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.

    void fusiona(const pila<T> &p2);
    // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica

private:
    struct node {
        T info;
        node* seg;
    };
    node* _cim; // Apunta al cim de la pila
    nat _mida;  // Nombre d’elements de la pila

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic fusiona i privats addicionals
template <typename T>
void pila<T>::fusiona(const pila<T> &p2) {
    if (p2._mida == 0) return;

    node* pNode1 = _cim;
    node* pNode2 = p2._cim;

    if (_cim == NULL && p2._cim != NULL) {
        _cim = new node;
        _cim->info = pNode2->info;
        _cim->seg = NULL;
        pNode1 = _cim;
        pNode2 = pNode2->seg;
    }

    while ((pNode1 != NULL && pNode1->seg != NULL) || pNode2 != NULL) {
        if (pNode2 == NULL) break;
        else if (pNode1->info == pNode2->info) {
            node* pAux = pNode1->seg;
            pNode1->seg = new node;
            pNode1->seg->seg = pAux;
            pNode1->seg->info = pNode2->info;
            pNode1 = pAux;
            pNode2 = pNode2->seg;
        }
        else if (pNode1->info > pNode2->info) {
            node* pAux = pNode1->seg;
            pNode1->seg = new node;
            pNode1->seg->seg = pAux;
            pNode1->seg->info = pNode1->info;
            pNode1->info = pNode2->info;
            pNode1 = pNode1->seg;
            pNode2 = pNode2->seg;
        }
        else if (pNode1->seg == NULL) {
            pNode1->seg = new node;
            pNode1->seg->seg = NULL;
            pNode1->seg->info = pNode2->info;
            pNode1 = pNode1->seg;
            pNode2 = pNode2->seg;
        }
        else if (pNode1->info < pNode2->info) pNode1 = pNode1->seg;
    }

    _mida += p2._mida;
}