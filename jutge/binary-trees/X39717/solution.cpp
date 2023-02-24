#include <iostream>
#include "abin.hpp"

using namespace std;

template <typename T>
list<T> Abin<T>::preordre() const {
    if (_arrel == NULL) return list<T>();

    list<node*> auxList;
    list<T> output;
    node* pNode = _arrel;
    auxList.push_back(pNode);

    do {
        while(pNode != NULL) {
            output.push_back(pNode->info);
            auxList.push_back(pNode);
            if (!pNode->thread_esq) pNode = pNode->f_esq;
            else break;
        }

        pNode = auxList.back();
        auxList.pop_back();

        if (!pNode->thread_dret) pNode = pNode->f_dret;
        else pNode = NULL;
    } while(!auxList.empty());

    return output;
}