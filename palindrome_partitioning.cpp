// palindrome_partitioning.cpp - Partition string into all palindrome combinations
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void backtrack(int start, string& s, vector<string>& path, vector<vector<string>>& result) {
    if (start == s.size()) {
        result.push_back(path);
        return;
    }
    for (int end = start; end < s.size(); ++end) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(end + 1, s, path, result);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    backtrack(0, s, path, result);
    return result;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);

    for (auto& group : result) {
        cout << "[ ";
        for (auto& part : group) cout << part << " ";
        cout << "]\n";
    }
    return 0;
}
