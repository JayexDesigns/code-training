#include <iostream>

using namespace std;

bool equalNums(int n, int b, int &q) {
    if (n == 0) return false;
    if (equalNums(n / b, b, q)) return true;
    if ((n / b) != 0 && n % b == (n / b) % b) ++q;
    else q = 1;
    if (q == 3) return true;
    else return false;
}

bool three_equal_consecutive_digits(int n, int b) {
    int quantity = 0;
    return equalNums(n, b, quantity);
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    bool res = three_equal_consecutive_digits(num1, num2);
    cout << endl << (res ? "true" : "false") << endl;
    return 0;
}