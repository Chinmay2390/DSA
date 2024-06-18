// longest_common_prefix.cpp - Find the longest common prefix in string array
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    for (int i = 0; i < strs[0].length(); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }

    return strs[0];
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(words) << endl;
    return 0;
}
