#include <cstdlib>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Arbre {

public:
// Construeix un Arbre format per un únic node que conté a x.
Arbre(const T &x);

// Tres grans.
Arbre(const Arbre<T> &a);
Arbre& operator=(const Arbre<T> &a);
~Arbre() throw();

// Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
void afegir_fill(Arbre<T> &a);

static const int ArbreInvalid = 400;

// Indica quants nodes de grau n té.
nat quants_grau(nat n) const;

private:
Arbre(): _arrel(NULL) {};
struct node {
    T info;
    node* primf;
    node* seggerm;
};
node* _arrel;
static node* copia_arbre(node* p);
static void destrueix_arbre(node* p) throw();

// Aquí va l’especificació dels mètodes privats addicionals
void get_degree_quantity(const node* pNode, const nat degree, nat& quantity) const;
};

// Aquí va la implementació del mètode quants_grau
template <typename T>
nat Arbre<T>::quants_grau(nat n) const {
    if (_arrel == NULL) return 0;

    nat quantity = 0;
    get_degree_quantity(_arrel, n, quantity);
    return quantity;
}

template <typename T>
void Arbre<T>::get_degree_quantity(const node* pNode, const nat degree, nat& quantity) const {
    if (pNode->primf == NULL) {
        if (degree == 0) ++quantity;
        return;
    }

    int d = 0;
    node* pAux = pNode->primf;
    while(pAux != NULL) {
        ++d;
        get_degree_quantity(pAux, degree, quantity);
        pAux = pAux->seggerm;
    }
    if (d == degree) ++quantity;
}