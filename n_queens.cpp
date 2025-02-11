// n_queens.cpp - Place N queens on an N×N board without attacking each other
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q') return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q') return false;

    for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, vector<string>& board, vector<vector<string>>& result, int n) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, result, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    solve(0, board, result, n);
    return result;
}

int main() {
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);

    for (auto& board : result) {
        for (auto& row : board)
            cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
