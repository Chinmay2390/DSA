// generate_parentheses.cpp - Generate all combinations of valid parentheses
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(int open, int close, string& path, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(path);
        return;
    }
    if (open > 0) {
        path.push_back('(');
        backtrack(open - 1, close, path, result);
        path.pop_back();
    }
    if (close > open) {
        path.push_back(')');
        backtrack(open, close - 1, path, result);
        path.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string path;
    backtrack(n, n, path, result);
    return result;
}

int main() {
    int n = 3;
    vector<string> result = generateParenthesis(n);

    for (auto& s : result) {
        cout << s << "\n";
    }
    return 0;
}
