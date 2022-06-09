#include <iostream>
#include <string>

using namespace std;

#include "BinaryTree.hpp"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna el nombre de subarbres de t que s'avaluen a x.
int numberSubtreesEvaluateToParam(const BinaryTree<string> &t, int x);