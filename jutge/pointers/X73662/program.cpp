#include "arbreBin.hpp"
#include <iostream>
using namespace std;

int main (){
    arbreBin ar;
    cin >> ar;
    cout << ar << endl;

    ar.elimina_nodes_amb_un_fill();
    cout << ar;
}
