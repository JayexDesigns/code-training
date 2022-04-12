#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector< vector<char> > Matrix;

void print(const Matrix& m) {
    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m[i].size(); ++j) {
            std::cout << m[i][j]; 
        }
        std::cout << std::endl;
    }
}

Matrix createMatrix(int size, char character) {
    Matrix m = {};
    for (int i = 0; i < size; ++i) {
        m.push_back({});
        for (int j = 0; j < size; ++j) {
            m[i].push_back(character);
        }
    }
    return m;
}

Matrix spiralMatrix(Matrix m, char character) {
    vector<int> direction = {1, 0};
    vector<int> pos = {0, (int)(m.size()-1)};
    int lineSize = (int)m.size()+1;
    int drawn = 1;
    while (lineSize > 0) {
        int lineSizeParsed = lineSize;
        if (lineSizeParsed > (int)m.size()) lineSizeParsed -= 1;
        m[pos[1]][pos[0]] = character;
        pos[0] += direction[0];
        pos[1] += direction[1];
        drawn++;
        if (drawn >= lineSizeParsed) {
            drawn = 1;
            lineSize--;
            if (direction[0] == 1 && direction[1] == 0) {
                direction[0] = 0;
                direction[1] = -1;
            }
            else if (direction[0] == 0 && direction[1] == -1) {
                direction[0] = -1;
                direction[1] = 0;
            }
            else if (direction[0] == -1 && direction[1] == 0) {
                direction[0] = 0;
                direction[1] = 1;
            }
            else if (direction[0] == 0 && direction[1] == 1) {
                direction[0] = 1;
                direction[1] = 0;
            }
        }
    }
    return m;
}

int main() {
    int size;
    while (cin >> size) {
        if (size == 0) continue;
        Matrix m = createMatrix(size, '.');
        m = spiralMatrix(m, 'X');
        print(m);
        cout << endl;
    }
    return 0;
}