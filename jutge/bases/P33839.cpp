#include <iostream>
#include <string>

using namespace std;

void sumDigits(int num) {
    string number = to_string(num);
    int sum = 0;
    for (int i = 0; i < (int)number.length(); ++i) {
        sum += number[i] - '0';
    }
    cout << "The sum of the digits of " << num << " is " << sum << "." << endl;
}

int main() {
    int num;
    while (cin >> num) {
        sumDigits(num);
    }

    return 0;
}