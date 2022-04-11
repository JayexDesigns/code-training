#include <iostream>

using namespace std;

int sum_of_digits(int n) {
    if (n < 10) return n;
    return n%10 + sum_of_digits(int(n/10));
}

bool is_multiple_3(int n) {
    return sum_of_digits(n)%3 == 0;
}

int main() {
    int num;
    cin >> num;
    cout << is_multiple_3(num) << endl;
    return 0;
}