// implement_strstr.cpp - Implement strstr() (naive approach)
#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;

    for (int i = 0; i <= haystack.size() - needle.size(); i++) {
        if (haystack.substr(i, needle.size()) == needle)
            return i;
    }

    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "ll";
    int index = strStr(haystack, needle);
    cout << "Index: " << index << endl;
    return 0;
}
