
#include <iostream>
using namespace std;

#include "arbreBin.hpp"
#include "isomorfs.hpp"

int main () 
{
	arbreBin<int> a,b;
	
	cin >> a;
	cin >> b;
	
	cout << (isomorfs (a,b) ? "SI" : "NO") << endl;
}
