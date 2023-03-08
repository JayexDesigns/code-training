#include <cstdlib>
#include <iostream>
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

    // operador << d’escriptura
    template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);

    // operador >> de lectura
    template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);

    // Modifica el contingut de l’arbre per tal de guardar a cada node la suma dels
    // nodes del seu subarbre.
    void arbre_sumes();

private:
    struct node {
    node* f_esq;
    node* f_dret;
    T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode arbre_sumes
#include <queue>
#include <stack>
template <typename T>
void Abin<T>::arbre_sumes() {
    if (_arrel == NULL) return;

    queue<node*> nodes;
    stack<node*> nodes2;
    nodes.push(_arrel);
    nodes2.push(_arrel);

    while(!nodes.empty()) {
        node* pNode = nodes.front();
        nodes.pop();
        int sum = 0;
        if (pNode->f_esq != NULL) sum += pNode->f_esq->info;
        if (pNode->f_dret != NULL) sum += pNode->f_dret->info;

        if (pNode->f_esq == NULL && pNode->f_dret == NULL) continue;

        if (pNode->f_esq != NULL) {
            nodes.push(pNode->f_esq);
            nodes2.push(pNode->f_esq);
        }
        if (pNode->f_dret != NULL) {
            nodes.push(pNode->f_dret);
            nodes2.push(pNode->f_dret);
        }
    }

    while(!nodes2.empty()) {
        node* pNode = nodes2.top();
        nodes2.pop();
        int sum = pNode->info;
        if (pNode->f_esq) sum += pNode->f_esq->info;
        if (pNode->f_dret) sum += pNode->f_dret->info;
        pNode->info = sum;
    }
}