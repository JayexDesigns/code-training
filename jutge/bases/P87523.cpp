#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    char word[5] = {'h', 'e', 'l', 'l', 'o'};

    int counter = 0;
    bool valid = false;
    for (int i = 0; i < (int)input.length(); ++i) {
        if (input[i] == word[counter]) {
            counter++;
            if (counter == 5) {
                valid = true;
                break;
            }
        }
        else {
            counter = 0;
            if (input[i] == word[counter]) counter++;
        }
    }

    if (valid) cout << "hello" << endl;
    else cout << "bye" << endl;

    return 0;
}