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

static const int ArbreInvalid = 400;

// Comprova que el contingut de cada node coincideix amb la suma dels nodes
// dels seus fills, exceptuant les fulles (els de grau 0).
bool es_arbre_suma();

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
};

// Aquí va la implementació del mètode es_arbre_suma
#include <queue>
#include <iostream>
template <typename T>
bool Arbre<T>::es_arbre_suma() {
    queue<node*> q;
    q.push(_arrel);

    while(!q.empty()) {
        node* pNode = q.front();
        q.pop();

        if (pNode->primf != NULL) {
            q.push(pNode->primf);
            node* pAux = pNode->primf;
            int sum = pAux->info;
            while (pAux->seggerm != NULL) {
                sum += pAux->seggerm->info;
                q.push(pAux->seggerm);
                pAux = pAux->seggerm;
            }
            if (sum != pNode->info) return false;
        }
    }

    return true;
}