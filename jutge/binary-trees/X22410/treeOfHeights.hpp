#include <iostream>
#include <list>

using namespace std;

#include "BinaryTree.hpp"

// Pre:
// Post: Retorna un arbre d'enters amb la mateixa estructura que t,
//       i a on cada subarbre té com a arrel la seva alçada.
BinaryTree<int> treeOfHeights(BinaryTree<int> t);