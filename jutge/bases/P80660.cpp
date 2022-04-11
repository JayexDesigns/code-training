#include <iostream>

using namespace std;

int collatz(int num) {
    int counter = 0;
    while (num != 1) {
        if (num % 2 == 0) num = num / 2;
        else num = num * 3 + 1;
        counter++;
    }
    return counter;
}

int main() {
    int num;
    while (cin >> num) {
        int result = collatz(num);
        cout << result << endl;
    }
    return 0;
}