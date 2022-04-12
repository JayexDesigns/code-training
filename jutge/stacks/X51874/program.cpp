#include <iostream>
#include <string>
#include <stack>

using namespace std;

#include "utilitats.hpp"
#include "esborraSenars.hpp"

int main() 
{
	stack<int> P;

	llegeix (P);
	esborraSenars (P);
	escriu (P);

	return 0;
}

