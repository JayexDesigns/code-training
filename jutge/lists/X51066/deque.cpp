#include <cstddef>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class deque {
public:
    deque();
    // Pre: True
    // Post: El p.i. és una deque buida.

    deque(const deque &dq);
    // Pre: True
    // Post: El p.i. conté una còpia de dq.

    ~deque();
    // Post: Destrueix els elements del p.i.

    nat size() const;
    // Pre: True
    // Post: Retorna el nombre d’elements de la deque.

    bool empty() const;
    // Pre: True
    // Post: Retorna true si la deque és buida; false en cas contrari.

    T front() const;
    // Pre: La deque no és buida.
    // Post: Retorna el primer element de la deque.

    T rear() const;
    // Pre: La deque no és buida.
    // Post: Retorna l’últim element de la deque.

    void push(T e);
    // Pre: True
    // Post: Insereix un element al davant de la deque.

    void inject(T e);
    // Pre: True
    // Post: Insereix un element al darrera de la deque.

    void pop();
    // Pre: La deque no és buida.
    // Post: Elimina el primer element de la deque.

    void eject();
    // Pre: La deque no és buida.
    // Post: Elimina l’últim element de la deque.

private:
/* Double-ended queue implementada amb una llista doblement encadenada,
    sense fantasma i no circular. */
    struct node {
    T info;    // Informació del node
    node *seg; // Punter al següent element
    node *ant; // Punter a l’anterior element
    };
    node *_prim; // Punter al primer element
    node *_ult;  // Punter a l’últim element
    nat _long;   // Nombre d’elements

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació dels mètodes públics i privats addicionals
template <typename T>
void deque<T>::push(T e) {
    if (_prim == NULL) {
        _prim = new node;
        _prim->info = e;
        _prim->ant = NULL;
        _prim->seg = NULL;
        _ult = _prim;
    }
    else {
        _prim->ant = new node;
        _prim->ant->info = e;
        _prim->ant->seg = _prim;
        _prim->ant->ant = NULL;
        _prim = _prim->ant;
    }
    ++_long;
}

template <typename T>
void deque<T>::inject(T e) {
    if (_ult == NULL) {
        _ult = new node;
        _ult->info = e;
        _ult->seg = NULL;
        _ult->ant = NULL;
        _prim = _ult;
    }
    else {
        _ult->seg = new node;
        _ult->seg->info = e;
        _ult->seg->ant = _ult;
        _ult->seg->seg = NULL;
        _ult = _ult->seg;
    }
    ++_long;
}

template <typename T>
void deque<T>::pop() {
    if (_long > 0) {
        node* pAux = _prim;
        if (_prim->seg == NULL) _prim = NULL;
        else {
            _prim = _prim->seg;
            _prim->ant = NULL;
        }
        delete pAux;
        --_long;
    }
    if (_long == 0) {
        _ult = NULL;
    }
}

template <typename T>
void deque<T>::eject() {
    if (_long > 0) {
        node* pAux = _ult;
        if (_ult->ant == NULL) _ult = NULL;
        else {
            _ult = _ult->ant;
            _ult->seg = NULL;
        }
        delete pAux;
        --_long;
    }
    if (_long == 0) {
        _prim = NULL;
    }
}
