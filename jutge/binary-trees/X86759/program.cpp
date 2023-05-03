#include "arbreBin.hpp"
#include <iostream>
using namespace std;

int main (){
    arbreBin ar;
    cin >> ar;
    cout << ar << endl;

    if (ar.compleix_suma_fills())
        cout << "L'arbre compleix la propietat 'Suma dels fills'." << endl;
    else
        cout << "L'arbre no compleix la propietat 'Suma dels fills'." << endl;
}
