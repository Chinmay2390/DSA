// word_search.cpp - Check if word exists in a 2D grid using backtracking
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
    if (index == word.size()) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
        return false;

    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    bool found = dfs(board, i+1, j, word, index+1) ||
                 dfs(board, i-1, j, word, index+1) ||
                 dfs(board, i, j+1, word, index+1) ||
                 dfs(board, i, j-1, word, index+1);

    board[i][j] = temp; // unmark
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            if (dfs(board, i, j, word, 0))
                return true;
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << (exist(board, word) ? "Word Found" : "Word Not Found") << endl;
    return 0;
}
