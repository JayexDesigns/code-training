#include <iostream>
#include <list>

using namespace std;

#include "BinaryTree.hpp"

// Pre:
// Post: Retorna la llista d'elements que es troben a t, baixant des de l'arrel i
//       seguint el camí més llarg. En cas de varis camins màxims,
//       escull el de més a l'esquerra.
list<int> longestLeftmostPath(BinaryTree<int> t);