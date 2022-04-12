#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector< vector<int> > Matrix;

int getMaxValue(Matrix charBoard, Matrix valueBoard, string word) {
    int maxValue = -1;
    int currentMaxValueX = -1;
    int currentMaxValueY = -1;

    for (int i = 0; i < (int)charBoard.size(); ++i) {
        for (int j = 0; j < (int)charBoard[i].size(); ++j) {
            if (charBoard[i][j] == word[0]) {
                currentMaxValueX = valueBoard[i][j];
                bool validX = true;
                currentMaxValueY = valueBoard[i][j];
                bool validY = true;
                for (int k = 1; k <= (int)word.length(); ++k) {
                    if (k == (int)word.length()) {
                        if (currentMaxValueX >= currentMaxValueY) {
                            if (maxValue < currentMaxValueX) maxValue = currentMaxValueX;
                        }
                        else {
                            if (maxValue < currentMaxValueY) maxValue = currentMaxValueY;
                        }
                        break;
                    }

                    if (((j+k) < (int)charBoard[i].size()) && validX) {
                        if (charBoard[i][j+k] == word[k]) currentMaxValueX += valueBoard[i][j+k];
                        else {
                            currentMaxValueX = -1;
                            validX = false;
                        }
                    }
                    else currentMaxValueX = -1;
                    if (((i+k) < (int)charBoard.size()) && validY) {
                        if (charBoard[i+k][j] == word[k]) currentMaxValueY += valueBoard[i+k][j];
                        else {
                            currentMaxValueY = -1;
                            validY = false;
                        }
                    }
                    else currentMaxValueY = -1;
                }
            }
        }
    }

    return maxValue;
}

int main() {
    while(cin) {
        Matrix charBoard = {};
        Matrix valueBoard = {};
        int r, c;
        cin >> r >> c;

        for (int i = 0; i < r; ++i) {
            charBoard.push_back({});
            for (int j = 0; j < c; ++j) {
                char character;
                cin >> character;
                charBoard[i].push_back(character);
            }
        }
        for (int i = 0; i < r; ++i) {
            valueBoard.push_back({});
            for (int j = 0; j < c; ++j) {
                int value;
                cin >> value;
                valueBoard[i].push_back(value);
            }
        }

        int wordQuantity;
        cin >> wordQuantity;
        for (int i = 0; i < wordQuantity; ++i) {
            string word;
            cin >> word;
            int res = getMaxValue(charBoard, valueBoard, word);
            cout << ((res >= 0) ? to_string(res) : "no") << endl;
        }

        cin.ignore();
        cin.get();
    }
    return 0;
}