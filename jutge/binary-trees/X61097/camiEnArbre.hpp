
#include <iostream>
#include <stack>

using namespace std;

#include "arbreBin.hpp"

typedef pair<bool,stack<int>> T;

T camiEnArbre (arbreBin<int>, int);
/// Donat un arbre (sense repetitions) i un int k,
/// torna true (false altrament) si hi ha un camí de
/// l'arrel a k a dins de l'arbre, i en cas que hi sigui,
/// també torna, en una pila, el camí de l'arrel a k:
/// l'arrel es trobarà al cim de la pila, i k al fons de la pila.



