#include <iostream>

using namespace std;

bool is_palindromic(int n) {
    int digit, reversedNum = 0;
    int originalNum = n;

    while (n != 0) {
        digit = n % 10;
        reversedNum = (reversedNum * 10) + digit;
        n = n / 10;
    }

    return (originalNum == reversedNum);
}

int main() {
    int num;
    cin >> num;
    cout << is_palindromic(num) << endl;
    return 0;
}