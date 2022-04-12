
#include "utilitats.hpp"
#include "pilaFibonacci.hpp"

int main() 
{
	stack<int> P;
	
	llegeix (P);
	escriu (P);
	
	bool b = pilaFibonacci(P);
	cout << (b ? "sí" : "no") << endl;

	return 0;
}

