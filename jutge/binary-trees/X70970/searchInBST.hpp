#include <iostream>
#include <list>

using namespace std;

#include "BinaryTree.hpp"

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t
bool searchInBST(BinaryTree<int> &t, int x);