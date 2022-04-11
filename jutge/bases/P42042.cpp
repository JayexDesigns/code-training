#include <iostream>

using namespace std;

int main() {
    char letter;
    cin >> letter;

    if (letter >= 'A' && letter <= 'Z') {
        cout << "uppercase" << endl;
    }
    else if (letter >= 'a' && letter <= 'z') {
        cout << "lowercase" << endl;
    }

    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        cout << "vowel" << endl;
    }
    else {
        cout << "consonant" << endl;
    }

    return 0;
}