#include <iostream>

using namespace std;

int main() {
    int counter = 0;
    bool found = false;
    int num;
    while (cin >> num) {
        if (!found) {
            if (num % 2 == 0) {
                found = true;
            }
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}