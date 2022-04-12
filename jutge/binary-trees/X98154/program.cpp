
#include <iostream>
using namespace std;

#include "arbreBin.hpp"
#include "subArbre.hpp"

int main () 
{
	arbreBin<int> a,b;

	cin >> a >> b;
	cout << a << endl << b << endl << endl;
	
	cout << (subArbre (a,b) ? "sí" : "no") << endl;
}


