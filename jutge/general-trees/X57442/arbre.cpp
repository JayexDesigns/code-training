#include <cstdlib>
#include <string>
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

// Imprimeix la informació dels nodes en preodre, cada element en una nova línia i
// precedit per espais segons el nivell on està situat.
void preordre() const;

static const int ArbreInvalid = 400;

// Modifica el contingut dels nodes per tal de guardar a cada node la suma dels
// nodes dels seus fills. Els nodes fulla (els de grau 0) no es modifiquen.
void arbre_suma_fills();

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
static void preordre(node *p, string pre);

// Aquí va l’especificació dels mètodes privats addicionals
void suma_fills(node* n);
};

// Aquí va la implementació del mètode arbre_suma_fills i privats addicionals
#include <iostream>
template <typename T>
void Arbre<T>::arbre_suma_fills() {
    if (_arrel == NULL) return;
    suma_fills(_arrel);
}

template <typename T>
void Arbre<T>::suma_fills(node* n) {
    if (n->primf == NULL) return;

    node* pAux = n->primf;
    while(pAux != NULL) {
        suma_fills(pAux);
        pAux = pAux->seggerm;
    }

    int sum = 0;
    pAux = n->primf;
    while(pAux != NULL) {
        sum += pAux->info;
        pAux = pAux->seggerm;
    }
    n->info = sum;
}