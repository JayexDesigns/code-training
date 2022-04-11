#include <iostream>
#include <string>

using namespace std;

string decimal2binary(int num) {
    if (num < 2) return to_string(num);
    return decimal2binary(num/2) += to_string(num%2);
}

string decimal2octal(int num) {
    if (num < 8) return to_string(num);
    return decimal2octal(num/8) += to_string(num%8);
}

string decimal2hex(int num) {
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    if (num < 16) return (num > 9) ? string(1,letters[num-10]) : to_string(num);
    return decimal2hex(num/16) += (num%16 > 9) ? string(1,letters[num%16-10]) : to_string(num%16);
}

int main() {
    int num;
    while (cin >> num) {
        cout << num << " = " << decimal2binary(num) << ", " << decimal2octal(num) << ", " << decimal2hex(num) << endl;
    }
    return 0;
}