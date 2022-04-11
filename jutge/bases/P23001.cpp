#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    string firstWord;
    bool first = true;
    int counter = 1;
    int maxCounter = 1;
    while (cin >> input) {
        if (first) {
            firstWord = input;
            first = false;
        }
        else if (firstWord == input) ++counter;
        else {
            if (maxCounter < counter) maxCounter = counter;
            counter = 0;
        }
    }
    if (maxCounter < counter) maxCounter = counter;

    cout << maxCounter << endl;

    return 0;
}