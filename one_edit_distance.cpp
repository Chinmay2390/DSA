// one_edit_distance.cpp - Check if two strings are exactly one edit apart
#include <iostream>
#include <string>
using namespace std;

bool isOneEditDistance(string s, string t) {
    int m = s.size(), n = t.size();
    if (abs(m - n) > 1) return false;

    for (int i = 0; i < min(m, n); ++i) {
        if (s[i] != t[i]) {
            if (m == n)
                return s.substr(i + 1) == t.substr(i + 1); // Replace
            else if (m < n)
                return s.substr(i) == t.substr(i + 1);     // Insert into s
            else
                return s.substr(i + 1) == t.substr(i);     // Delete from s
        }
    }

    return abs(m - n) == 1; // Edge case: last char differs
}

int main() {
    cout << boolalpha;
    cout << isOneEditDistance("ab", "acb") << endl;  // true (insert)
    cout << isOneEditDistance("cab", "ad") << endl;  // false
    cout << isOneEditDistance("1203", "1213") << endl;  // true (replace)
    return 0;
}
