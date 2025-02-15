// expression_add_operators.cpp - Insert +, -, * to reach a target value
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(string& num, int target, int index, long curr, long prev, string expr, vector<string>& result) {
    if (index == num.size()) {
        if (curr == target) result.push_back(expr);
        return;
    }

    for (int len = 1; len + index <= num.size(); ++len) {
        string part = num.substr(index, len);
        if (part[0] == '0' && part.length() > 1) break;

        long n = stol(part);
        if (index == 0) {
            backtrack(num, target, index + len, n, n, part, result);
        } else {
            backtrack(num, target, index + len, curr + n, n, expr + "+" + part, result);
            backtrack(num, target, index + len, curr - n, -n, expr + "-" + part, result);
            backtrack(num, target, index + len, curr - prev + prev * n, prev * n, expr + "*" + part, result);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    backtrack(num, target, 0, 0, 0, "", result);
    return result;
}

int main() {
    string num = "123";
    int target = 6;
    vector<string> result = addOperators(num, target);

    for (auto& expr : result) {
        cout << expr << "\n";
    }
    return 0;
}
