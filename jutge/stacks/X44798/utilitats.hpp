#include <stack>
#include <iostream>

using namespace std;

void llegeix (stack<int> &p)
{	/// Llegeix del canal d'entrada fins que troba un -1.

	int i;
	cin >> i;
	while (i != -1)
	{
		p.push(i);
		cin >> i;
	}
	
	return;
};

void escriu (stack<int> p)
{
	while (not p.empty())
	{
		cout << "|" << p.top() << "|" << endl;
		p.pop();
	}
	cout << " =" << endl  << endl;
	return;
}
