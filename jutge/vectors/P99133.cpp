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
    int times;
    cin >> times;
    vector<string> words;
    for (int i = 0; i < times; ++i) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    for (int i = 0; i < times; ++i) {
        cout << invertWord(words[times-i-1]) << endl;
    }

    return 0;
}