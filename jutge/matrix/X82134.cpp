#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;

// Retorna els valors d'abaix de la posició en la seva columna que siguin menors a ell mateix
vector<int> getLowValues(const Matrix& m, int row, int col) {
    vector<int> out = {};
    for (int i = 1; i < int(m.size())-row; ++i) {
        if (m[row+i][col] < m[row][col]) out.push_back(m[row+i][col]);
    }
    return out;
}

int main() {
    int n, m;
    Matrix matrix;
    cin >> n >> m;
    // Genera la matriu
    for (int i = 0; i < n; ++i) {
        matrix.push_back({});
        for (int j = 0; j < m; ++j) {
            int value;
            cin >> value;
            matrix[i].push_back(value);
        }
    }
    // Mostra per pantalla la mida del vector dels valors menors per cada posició
    for (int i = 0; i < (int)matrix.size(); ++i) {
        for (int j = 0; j < (int)matrix[i].size(); ++j) {
            if (j != 0) cout << " ";
            cout << getLowValues(matrix, i, j).size();
        }
        cout << endl;
    }
    return 0;
}