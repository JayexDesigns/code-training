
#include "utilitats.hpp"
#include "camiEnArbre.hpp"

int main () 
{
	arbreBin<int> a;
	
	cin >> a;
	cout << a << endl;
	
	int k;
	while (cin >> k)
	{
		T p = camiEnArbre(a,k);
		cout << (p.first ? "SI: " : "NO: ") << k << endl << endl;
		if (p.first) escriu (p.second);
	}

}
