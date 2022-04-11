#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    string entry;
    while(cin >> entry) {
        bool keepGoing = true;
        for (int i = 0; i < (int)entry.length(); ++i) {
            if (entry[i] == '.') {
                keepGoing = false;
                break;
            }
        }
        text += entry;
        if (keepGoing) text += " ";
        else break;
    }

    bool contains = false;
    for (int i = 0; i < (int)text.length(); ++i) {
        if (text[i] == 'a') {
            contains = true;
            break;
        }
    }

    if (contains) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}