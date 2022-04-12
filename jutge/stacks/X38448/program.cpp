#include <iostream>
#include <string>
#include <stack>

using namespace std;

#include "utilitats.hpp"
#include "subPila.hpp"

int main() 
{
	stack<int> P1, P2;
	
	llegeix (P1);
	llegeix (P2);
		
	escriu (P1);
	escriu (P2);

	cout << (subPila (P1,P2) ? "sí" : "no") << endl;

	return 0;
}

