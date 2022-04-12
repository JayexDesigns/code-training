#include <queue>
#include <iostream>
using namespace std;

// Lectura i escriptura de cues de int

ostream& operator<<(ostream&, queue<int>);
/* Pre: cert */
/* Post: s'han escrit els valors enters de la cua
   al canal estàndard de sortida */

istream& operator>>(istream&, queue<int> &);
/* Pre: cert */
/* Post: la cua passa a tenir els valors enters llegits del canal 
   estàndard d'entrada */
