#include <iostream>
#include <string>
#include <vector>

using namespace std;

string invertWord(string word) {
    int textLength = (int)word.length();
    string newWord = "";
    for (int i = 0; i < textLength; ++i) {
        newWord += word[textLength-i-1];
    }

    return newWord;
}

int main() {
    string word = "";
    while (cin >> word) {
        cout << invertWord(word) << endl;
    }

    return 0;
}