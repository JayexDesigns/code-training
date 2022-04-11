#include <iostream>

using namespace std;

int main() {
    int size;
    while (cin >> size) {
        int biggest = 0;
        for (int i = 0; i < size; ++i) {
            int value;
            cin >> value;
            if (i == 0) biggest = value;
            else if (value > biggest) biggest = value;
        }
        cout << biggest << endl;
    }
    return 0;
}