#include <iostream>

using namespace std;

int reduction_of_digits(int x) {
    if (x < 10) return x;
    int digit = x % 10;
    int sum = digit + reduction_of_digits(x / 10);
    if (sum < 10) return sum;
    while (sum >= 10) sum = reduction_of_digits(sum);
    return sum;
}

int main() {
    int num;
    cin >> num;
    cout << reduction_of_digits(num) << endl;
    return 0;
}