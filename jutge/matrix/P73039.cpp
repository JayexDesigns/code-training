#include <iostream>
#include <string>

using namespace std;

int main() {
    int quantity;
    cin >> quantity;
    for (int i = 0; i < quantity; ++i) {
        int player = 0;
        bool gameEnded = false;
        char lastChar;
        string lastWord;
        bool firstEntry = true;
        char winner;
        while (cin) {
            cin >> lastWord;
            if (firstEntry) {
                firstEntry = false;
                lastChar = lastWord[(int)lastWord.length()-1];
            }
            else {
                if (lastWord[0] != lastChar && !gameEnded) {
                    gameEnded = true;
                    if (player%2 == 0) winner = 'B';
                    else if (player%2 == 1) winner = 'A';
                }
                lastChar = lastWord[(int)lastWord.length()-1];
            }
            player++;
            if (player == 10) {
                if (!gameEnded) winner = '=';
                cout << winner << endl;
                break;
            }
        }
    }
    return 0;
}