#include <iostream>

using namespace std;

#include "BinaryTree.hpp"

// Pre:
// Post: Retorna el resultat de reemplaçar tans cops com calgui en t
//       cada subarbre amb arrel 0 pel seu fill esquerre,
//       i cada subarbre amb arrel 1 pel seu fill dret.
BinaryTree<int> remove01(BinaryTree<int> t);