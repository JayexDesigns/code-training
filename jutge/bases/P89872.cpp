#include <iostream>
#include <string>

using namespace std;

int main() {
    string largest, secondLargest, word;

    while (cin >> word) {
        if (word > secondLargest) {
            if (word > largest) {
                secondLargest = largest;
                largest = word;
            }
            else if (word < largest) secondLargest = word;
        }
    }

    cout << secondLargest << endl;
} 