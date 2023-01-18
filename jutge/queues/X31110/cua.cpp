#include <iostream>
#include <vector>

using namespace std;
typedef unsigned int nat;

template <typename T>
class cua { // Cua no circular en memòria dinàmica
public:
    cua();
    // Construeix una cua buida.

    ~cua();
    // Destrueix el p.i.

    cua(const vector<int> &v);
    // Crea cua amb els elements de v amb el mateix ordre.

    nat longitud() const;
    // Retorna el nombre d’elements del p.i.

    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.

    void fusiona(const cua<T> &c2);
    // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica

private:
    struct node {
        T info;
        node* seg;
    };
    node* _pri; // Apunta al primer element de la cua
    node* _ult; // Apunta al darrer element de la cua
    nat _mida;

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic fusiona i privats addicionals
template <typename T>
void cua<T>::fusiona(const cua<T> &c2) {
    // if (c2._mida == -1) return;
    // cout << "testing" << endl;
    if (c2._mida == 0) return;

    node* pNode1 = _pri;
    node* pNode2 = c2._pri;

    if (_pri == NULL && c2._pri != NULL) {
        _pri = new node;
        _pri->info = pNode2->info;
        _pri->seg = NULL;
        pNode1 = _pri;
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

    node* pAux = _pri;
    while (pAux != NULL && pAux->seg != NULL) {
        pAux = pAux->seg;
    }
    if (pAux != NULL) _ult = pAux;

    _mida += c2._mida;
}