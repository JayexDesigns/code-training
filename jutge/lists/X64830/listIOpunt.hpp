#include <list>
#include <iostream>
#include "Punt.hpp"

using namespace std;

ostream& operator<<(ostream &os, const list<Punt> &l);

istream& operator>>(istream &is, list<Punt> &l);
