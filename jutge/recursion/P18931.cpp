#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector< vector<char> > createPattern(int n) {
    if (n == 1) return {{'#'}};
    int v1_size = pow(2, n) - 1;
    vector< vector<char> > v1(v1_size, vector<char>(v1_size, '.'));
    vector< vector<char> > v2 = createPattern(n - 1);

    int size = (int)v2.size();

    // 1st Corner
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) v1[i][j] = v2[i][j];

    // 2nd Corner
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) v1[i + (int)v1_size/2 + 1][j] = v2[i][j];

    // 3rd Corner
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) v1[i][j + (int)v1_size/2 + 1] = v2[i][j];

    // 4th Corner
    for (int i = 0; i < size; ++i) for (int j = 0; j < size; ++j) v1[i + (int)v1_size/2 + 1][j + (int)v1_size/2 + 1] = v2[i][j];

    // Borders
    v1[0][v1_size/2] = '#';
    v1[v1_size-1][v1_size/2] = '#';
    v1[v1_size/2][0] = '#';
    v1[v1_size/2][v1_size-1] = '#';

    return v1;
}

void printMatrix(const vector< vector<char> > &m) {
    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m[i].size(); ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector< vector<char> > v = createPattern(n);
    printMatrix(v);
    return 0;
}