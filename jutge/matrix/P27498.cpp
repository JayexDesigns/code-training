#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector< vector<int> > Matrix;

bool is_symmetric(const Matrix& m) {
    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m.size(); ++j) {
            if (m[i][j] != m[j][i]) return false;
        }
    }
    return true;
}

void transpose(Matrix& m) {
    Matrix newM = m;
    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m.size(); ++j) {
            newM[j][i] = m[i][j];
        }
    }
    m = newM;
}

void print(const Matrix& m) {
    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m.size(); ++j) {
            std::cout << m[i][j] << " "; 
        }
        std::cout << std::endl; 
    }
}

int main() {
    Matrix m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    return 0;
}