#include "llista_compra_articles.hpp"
#include "listIOint.hpp"
using namespace std;

int main() {
	list<int> preus;
	cin >> preus;
	cout << preus;
	int import;
	cin >> import;
	cout << import << endl;
	cout << "Es poden comprar " << compra_articles(preus, import) << " articles" << endl;
}