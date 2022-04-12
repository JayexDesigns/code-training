#include <iostream>
#include <list>

using namespace std;

#include "BinaryTree.hpp"

// Pre:  t no té repetits
// Post: retorna la llista de valors que es troben en el camí des de l'arrel
//       fins la posició de x en t. En cas que x no es trobi a t, retorna
//       una llista buida.
list<int> posInTree(const BinaryTree<int> t, int x);
