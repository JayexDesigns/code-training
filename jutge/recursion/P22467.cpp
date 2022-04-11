#include <iostream>

using namespace std;

bool is_perfect_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) return false;
    }
    if (n < 10) {
        if (n < 2) return false;
        return true;
    }
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return is_perfect_prime(sum);
}

int main() {
    int num;
    cin >> num;
    cout << is_perfect_prime(num) << endl;
}