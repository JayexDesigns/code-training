#include <iostream>
#include <string>
#include <stack>

using namespace std;

void sumAorB(stack<int>& sint, stack<string>& sstring, stack<int>& res, int sumAbove, int& sumBelow) {
    if (sint.empty()) return;

    string currentOption = sstring.top();
    int currentNumber = sint.top();

    sumAbove += currentNumber;

    sint.pop();
    sstring.pop();
    sumAorB(sint, sstring, res, sumAbove, sumBelow);

    sumBelow += currentNumber;

    if (currentOption == "above") res.push(sumAbove);
    else if (currentOption == "below") res.push(sumBelow);
}

// Pre: sint i sstring tenen la mateixa mida, i sstring només conté
//      mots de {"above", "below"} un nombre arbitrari de cops i
//      en un ordre arbitrari.
// Post: Retorna una pila d'enters de la mateixa mida que sint i sstring.
//       Per a cada posició p, si sstring té "above" a posició p, llavors
//       la pila retornada té a posició p el resultat de sumar tots els
//       elements de sint a posició per sobre o igual a p,
//       i si per contra sstring té "below" a posició p, llavors
//       la pila retornada té a posició p el resultat de sumar tots els
//       elements de sint a posició per sota o igual a p.
stack<int> sumAboveOrBelow(stack<int> sint, stack<string> sstring) {
    stack<int> res = {};
    int sumBelow = 0;
    sumAorB(sint, sstring, res, 0, sumBelow);
    return res;
}

int main() {
    return 0;
}