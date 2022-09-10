#include <iostream>

using namespace std;

void showWords(int &quantity) {
	string word;
	if (cin >> word) {
		showWords(quantity);
		if (quantity > 0) {
			cout << word << endl;
			--quantity;
		}
	}
}

int main() {
	int quantity;
	cin >> quantity;
	showWords(quantity);
	return 0;
}