#include "stackIOpunt.hpp"

ostream& operator<<(ostream& os, stack<Punt> p) {
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        os << '(' << p.top().coordenadax() << ", " << p.top().coordenaday() << ')';
        if (i < n-1) os << '|';
        p.pop();
    }
    os << ']' << endl;
    return os;
}

istream& operator>>(istream &is, stack<Punt> &p)
/* Pre: cert */
/* Post: la pila p passa a tenir els enters llegits del canal 
   estàndard d'entrada */
{
    int n;
    is >> n;
    for (int i = 0; i < n ; ++i) {
        float i1, i2;
        is >> i1 >> i2;
        Punt punt(i1, i2);
        p.push(punt);
    }
    return is;
}
