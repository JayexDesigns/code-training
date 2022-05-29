#include <iostream>
#include "maximumTree.hpp"

using namespace std;

// Pre: rep per referencia tres arbres, a1, a2 i a3
// Post: construeix a3 a partir del les arrels dels arbres a1 i a2 agafant la més gran en cada cas
// va creant el arbre desde l'arrel fins al final, el cas base es quan tots dos a1 i a2 són buits, en aquest cas la recursió acaba
void maxTree(BinaryTree<int> &a1, BinaryTree<int> &a2, BinaryTree<int> &a3) {
    if (a1.isEmpty() && a2.isEmpty()) {
        a3 = BinaryTree<int>();
        return;
    }

    int root;
    if (a1.isEmpty()) root = a2.getRoot();
    else if (a2.isEmpty()) root = a1.getRoot();
    else {
        int root1 = a1.getRoot();
        int root2 = a2.getRoot();
        root = (root1 >= root2 ? root1 : root2);
    }

    a3 = BinaryTree<int>(root, BinaryTree<int>(), BinaryTree<int>());

    if (a1.isEmpty()) {
        maxTree(a1, a2.getLeft(), a3.getLeft());
        maxTree(a1, a2.getRight(), a3.getRight());
    }
    else if (a2.isEmpty()) {
        maxTree(a1.getLeft(), a2, a3.getLeft());
        maxTree(a1.getRight(), a2, a3.getRight());
    }
    else {
        maxTree(a1.getLeft(), a2.getLeft(), a3.getLeft());
        maxTree(a1.getRight(), a2.getRight(), a3.getRight());
    }
}

// Pre: Rep dos arbres binaris d'enters positius t1 i t2.
// Post: Retorna un arbre, on a la seva arrel hi ha el màxim de les arrels de t1,t2,
// en l'arrel del fill esquerre hi ha el màxim de les arrels dels fills esquerre de t1,t2,
// en l'arrel del fill dret hi ha el màxim de les arrels dels fills drets de t1,t2,
// i així successivament.
// Quan un dels arbres no té valors definits en alguna posició, l'arbre resultant hi té
// el valor de l'altre arbre en aquella posició.
BinaryTree<int> maximumTree(BinaryTree<int> a1, BinaryTree<int> a2) {
    BinaryTree<int> a3 = BinaryTree<int>();
    maxTree(a1, a2, a3);
    return a3;
}