#include <iostream>
#include <cmath>

using namespace std;

int sum_divisors(int x) {
	if (x == 0) return 0;
	int sum = 0;
	for (int i = 1; i < ceil(sqrt(x)); ++i) {
		if (x % i == 0) sum += i + x / i;
	}
	if (sqrt(x) - ceil(sqrt(x)) == 0.0) sum += ceil(sqrt(x));
	return sum;
}

int main() {
	int n;
	cin >> n;
	cout << sum_divisors(n) << endl;
	return 0;
}
