// restore_ip_addresses.cpp - Generate all valid IP addresses from string
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(const string& s) {
    if (s.empty() || s.size() > 3 || (s[0] == '0' && s.size() > 1)) return false;
    int val = stoi(s);
    return val >= 0 && val <= 255;
}

void backtrack(string& s, int start, int dots, string path, vector<string>& result) {
    if (dots == 4 && start == s.size()) {
        result.push_back(path.substr(0, path.length() - 1));  // remove last dot
        return;
    }
    if (dots >= 4) return;

    for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
        string part = s.substr(start, len);
        if (isValid(part)) {
            backtrack(s, start + len, dots + 1, path + part + ".", result);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    backtrack(s, 0, 0, "", result);
    return result;
}

int main() {
    string s = "25525511135";
    vector<string> result = restoreIpAddresses(s);

    for (auto& ip : result) {
        cout << ip << "\n";
    }
    return 0;
}

