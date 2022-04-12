#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<bool> > Matrix;

void checkDiagonal(const Matrix& board, int i, int j, int di, int dj) {
    int pi = i + di;
    int pj = j + dj;
    while (pi>=0 && pi<(int)board.size() && pj>=0 && pj<(int)board[0].size() && !board[pi][pj]) {
        pi += di;
        pj += dj;
    }
    if (pi>=0 && pi<(int)board.size() && pj>=0 && pj<(int)board[0].size() && board[pi][pj]) {
        cout << '(' << i+1 << ',' << j+1 << ")<->(" << pi+1 << ',' << pj+1 << ')' << endl;
    }
}

void calcThreats(const Matrix& board) {
    for (int i = 0; i < (int)board.size(); ++i) {
        for (int j = 0; j < (int)board[i].size(); ++j) {
            if (board[i][j]) {
                checkDiagonal(board, i, j, 1, 1);
                checkDiagonal(board, i, j, 1, -1);
                checkDiagonal(board, i, j, -1, 1);
                checkDiagonal(board, i, j, -1, -1);
            }
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Matrix board = {};
    for (int i = 0; i < rows; ++i) {
        board.push_back({});
        for (int j = 0; j < cols; ++j) {
            char elem;
            cin >> elem;
            board[i].push_back((elem == '.') ? false : true);
        }
    }
    calcThreats(board);
}