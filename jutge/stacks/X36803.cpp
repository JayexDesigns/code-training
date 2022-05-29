#include <stack>

using namespace std;

// Pre: Rep tres piles d'enters positius s1, s2 i s3
// Post: Com s3 la rep com a referència va afegint els elements de s1 i s2 que siguin
// més grans entre els dos, d'aquesta forma no té que retornar res ni crear cap nou stack
void maxStack(stack<int> &s1, stack<int> &s2, stack<int> &s3) {
    if (s1.empty() && s2.empty()) return;
    else if (s2.size() > s1.size()) {
        int value = s2.top();
        s2.pop();
        maxStack(s1, s2, s3);
        s3.push(value);
        return;
    }
    else if (s1.size() > s2.size()) {
        int value = s1.top();
        s1.pop();
        maxStack(s1, s2, s3);
        s3.push(value);
        return;
    }
    else {
        int value1 = s1.top();
        int value2 = s2.top();
        s1.pop();
        s2.pop();
        maxStack(s1, s2, s3);
        if (value1 >= value2) s3.push(value1);
        else s3.push(value2);
        return;
    }
}

// Pre: Rep dues piles d'enters positius s1 i s2.
// Post: Retorna una pila, on al seu fons hi ha el màxim dels fons de s1,s2, després,
// en segon lloc començant des del fons, el màxim dels segons llocs de s1,s2 començant des del fons,
// i així successivament.
// Quan una de les dues piles no té valors definits en alguna posició, la pila resultant hi té
// el valor de l'altra pila en aquella posició.
stack<int> maximumStack(stack<int> s1,stack<int> s2) {
    stack<int> s3;
    maxStack(s1, s2, s3);
    return s3;
}

int main() {
    return 0;
}