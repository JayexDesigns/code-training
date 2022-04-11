#include <iostream>

using namespace std;

void count_and_add(int& num, int& sum) {
    num = 0;
    sum = 0;
    int lastNum = 0;
    while (cin >> lastNum) {
        num++;
        sum += lastNum;
    }
}

int main() {
    return 0;
}