#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;

Matrix createMatrix(int size) {
    Matrix m;
    for (int i = 0; i < size; ++i) {
        m.push_back({});
        for (int j = 0; j < size; ++j) {
            int value;
            cin >> value;
            m[i].push_back(value);
        }
    }
    return m;
}

bool checkMagicSquare(Matrix m) {
    vector<int> values(int(m.size())*int(m.size()), 0);
    int sumTotal = 0;
    for (int i = 0; i < (int)m.size(); ++i) {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < (int)m[i].size(); ++j) {
            if (m[i][j] > int(m.size())*int(m.size())) return false;
            else values[m[i][j]-1]++;
            sum1 += m[i][j];
            sum2 += m[j][i];
        }
        if (i == 0 && sum1 == sum2) sumTotal = sum1;
        else if (sum1 != sumTotal || sum2 != sumTotal) return false;
    }

    for (int i = 0; i < (int)values.size(); ++i) {
        if (values[i] != 1) return false;
    }

    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < (int)m.size(); ++i) {
        sum1 += m[i][i];
        sum2 += m[i][int(m.size())-1-i];
    }
    if (sum1 != sumTotal || sum2 != sumTotal) return false;

    return true;
}

int main() {
    int size;
    while (cin >> size) {
        Matrix m = createMatrix(size);
        cout << (checkMagicSquare(m) ? "yes" : "no") << endl;
    }
    return 0;
}