#include <iostream>
#include <cmath>

using namespace std;

bool is_perfect(int n) {
	if (n == 0 || n == 1) return false;
	int sum = 1;
	for (int i = 2; i < sqrt(n); ++i) {
		if (n % i == 0) sum += i + n / i;
	}
	return sum == n ? true : false;
}

int main() {
	int n;
	cin >> n;
	cout << is_perfect(n) << endl;
	return 0;
}
