#include <iostream>

using namespace std;

int valencia(int n) {
    int oddSum = 0;
    int evenSum = 0;
    int current = 1;
    while (n > 0) {
        if (current % 2 == 0) evenSum += n%10;
        else if (current % 2 != 0) oddSum += n%10;
        n /= 10;
        ++current;
    }
    int substraction = oddSum - evenSum;
    return (substraction < 0) ? -1 * substraction : substraction;
}

int main() {
    int num;
    int maxVal = 0;
    bool ended = false;
    while (!ended && cin >> num) {
        int parsedNum = valencia(num);
        if (parsedNum == 0) {
            cout << "The first balanced number is " << num << "." << endl;
            ended = true;
        }
        else if (parsedNum > maxVal) maxVal = parsedNum;
    }
    if (!ended) cout << "The greatest valencia is " << maxVal << "." << endl;
    return 0;
}