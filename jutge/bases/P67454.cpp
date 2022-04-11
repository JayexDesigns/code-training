#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    string entry;
    while(cin >> entry) {
        bool keepGoing = true;
        for (int i = 0; i < (int)entry.length(); ++i) {
            text += entry[i];
            if (entry[i] == '.') {
                keepGoing = false;
                break;
            }
        }
        // text += entry;
        if (keepGoing) text += " ";
        else break;
    }

    int quantity = 0;
    for (int i = 0; i < (int)text.length(); ++i) {
        if (text[i] == 'a') {
            quantity++;
        }
    }

    cout << quantity << endl;
    return 0;
}