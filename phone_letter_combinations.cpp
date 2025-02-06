// phone_letter_combinations.cpp - Map digit strings to letter combinations
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(string& digits, int index, string& path, vector<string>& result, const vector<string>& mapping) {
    if (index == digits.size()) {
        result.push_back(path);
        return;
    }
    string letters = mapping[digits[index] - '0'];
    for (char ch : letters) {
        path.push_back(ch);
        backtrack(digits, index + 1, path, result, mapping);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> result;
    string path;
    backtrack(digits, 0, path, result, mapping);
    return result;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);

    for (auto& s : result) {
        cout << s << "\n";
    }
    return 0;
}
