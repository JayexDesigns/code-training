#include <iostream>
#include <list>
#include "ParInt.hh"

using namespace std;

ostream& operator<<(ostream &os, const list<ParInt> &l);

istream& operator>>(istream &is, list<ParInt> &l);
