// word_break.cpp - Check if string can be segmented into words from a dictionary
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool backtrack(string& s, unordered_set<string>& dict, int start, unordered_map<int, bool>& memo) {
    if (start == s.size()) return true;
    if (memo.count(start)) return memo[start];

    for (int end = start + 1; end <= s.size(); ++end) {
        if (dict.count(s.substr(start, end - start)) && backtrack(s, dict, end, memo)) {
            return memo[start] = true;
        }
    }
    return memo[start] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    unordered_map<int, bool> memo;
    return backtrack(s, dict, 0, memo);
}

int main() {
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    cout << (wordBreak(s, dict) ? "Can be segmented" : "Cannot be segmented") << endl;
    return 0;
}
