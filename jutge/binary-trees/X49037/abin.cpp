#include <iostream>
#include <cstdlib>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin {
public:
    Abin(): _arrel(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);

    // Escriu una línia amb els elements del nivell i-èssim, d’esquerra 
    // a dreta. Cada element ha de sortir precedit d’un espai.
    void nivell(nat i) const;

private:
    struct node {
    node* f_esq;
    node* f_dret;
    T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode nivell
#include <queue>
#include <stack>
template <typename T>
void Abin<T>::nivell(nat i) const {
    if (_arrel == NULL) return;

    queue< pair<int, node*> > nodes;
    nodes.push(pair<int, node*>(0, _arrel));

    while(!nodes.empty()) {
        pair<int, node*> pNode = nodes.front();
        nodes.pop();

        if (pNode.first == i) cout << " " << pNode.second->info;

        if (pNode.first >= i || (pNode.second->f_esq == NULL && pNode.second->f_dret == NULL)) continue;

        if (pNode.second->f_esq != NULL) nodes.push(pair<int, node*>(pNode.first + 1, pNode.second->f_esq));
        if (pNode.second->f_dret != NULL) nodes.push(pair<int, node*>(pNode.first + 1, pNode.second->f_dret));
    }
}