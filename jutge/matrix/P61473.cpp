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

int main() {
    return 0;
}