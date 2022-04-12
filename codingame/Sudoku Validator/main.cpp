#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< vector<int> > Matrix;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void printMatrix(Matrix m) {
    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m[i].size(); ++j) {
            if (j != 0) cout << " ";
            cout << m[i][j];
        }
        cout << endl;
    }
}

bool checkSudoku(Matrix m) {
    for (int i = 0; i < (int)m.size(); ++i) {
        vector<int> rowValues(9, 0);
        vector<int> colValues(9, 0);
        for (int j = 0; j < (int)m[i].size(); ++j) {
            if (m[i][j] > 9 || m[i][j] < 1) return false;
            rowValues[m[i][j]-1]++;
            colValues[m[j][i]-1]++;
        }
        for (int j = 0; j < (int)rowValues.size(); ++j) {
            if (rowValues[j] != 1) return false;
        }
        for (int j = 0; j < (int)colValues.size(); ++j) {
            if (colValues[j] != 1) return false;
        }
    }

    for (int i = 0; i < (int)(m.size()/3); ++i) {
        for (int j = 0; j < (int)(m.size()/3); ++j) {
            int sum = 0;
            for (int k = 0; k < (int)(m.size()/3); ++k) {
                for (int l = 0; l < (int)(m.size()/3); ++l) {
                    sum += m[k+i*3][l+j*3];
                }
            }
            if (sum != 45) return false;
        }
    }

    return true;
}

int main()
{
    Matrix m = {};
    for (int i = 0; i < 9; i++) {
        m.push_back({});
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n; cin.ignore();
            m[i].push_back(n);
        }
    }

    cout << (checkSudoku(m) ? "true" : "false") << endl;

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}