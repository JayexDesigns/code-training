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
        for (int j = 0; j < (int)m[i].size(); ++j) {
            std::cout << m[i][j] << " "; 
        }
        std::cout << std::endl; 
    }
}

void printRow(const Matrix& m, int row) {
    for (int i = 0; i < (int)m[row].size(); ++i) {
        if (i != 0) cout << " ";
        cout << m[row][i];
    }
    cout << endl;
}
void printColumn(const Matrix& m, int col) {
    for (int i = 0; i < (int)m.size(); ++i) {
        if (i != 0) cout << " ";
        cout << m[i][col];
    }
    cout << endl;
}
void printElement(const Matrix& m, int el1, int el2) {
    cout << m[el1][el2];
    cout << endl;
}

Matrix createMatrix() {
    int height;
    int width;
    cin >> height;
    cin >> width;
    Matrix m = {};
    for (int i = 0; i < height; ++i) {
        m.push_back({});
        for (int j = 0; j < width; ++j) {
            int num;
            cin >> num;
            m[i].push_back(num);
        }
    }
    return m;
}

int main() {
    Matrix m = createMatrix();
    cin.get();
    string instruction;
    while (cin >> instruction) {
        if (instruction == "row") {
            int row;
            cin >> row;
            cout << "row " << row << ": ";
            printRow(m, row-1);
        }
        else if (instruction == "column") {
            int col;
            cin >> col;
            cout << "column " << col << ": ";
            printColumn(m, col-1);
        }
        else if (instruction == "element") {
            int el1;
            int el2;
            cin >> el1;
            cin >> el2;
            cout << "element " << el1 << " " << el2 << ": ";
            printElement(m, el1-1, el2-1);
        }
    }
    return 0;
}