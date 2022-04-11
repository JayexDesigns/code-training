#include <iostream>

using namespace std;

int main() {
    int index;
    cin >> index;
    int currentIndex = index;
    int num;
    bool found = false;
    while (num != -1 && !found) {
        cin >> num;
        --currentIndex;
        if (currentIndex == 0) found = true;
    }
    cout << "At the position " << index << " there is a(n) " << num << "." << endl;
}