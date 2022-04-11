#include <iostream>

using namespace std;

void product(int num) {
    bool ended = false;
    while (!ended) {
        int originalNum = num;
        int newNum = 1;
        if (num == 0) newNum = 0;
        while (num > 0) {
            newNum *= num%10;
            num /= 10;
        }
        cout << "The product of the digits of " << originalNum << " is " << newNum << "." << endl;
        if (newNum < 10) {
            cout << "----------" << endl;
            ended = true;
        }
        else num = newNum;
    }
}

int main() {
    int num;
    while (cin >> num)
        product(num);
    return 0;
}