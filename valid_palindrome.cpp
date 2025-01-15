// valid_palindrome.cpp - Check if a string is a valid palindrome (ignoring cases and non-alphanumerics)
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left++]) != tolower(s[right--])) return false;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    cout << (isPalindrome(s) ? "Valid Palindrome" : "Not a Palindrome") << endl;
    return 0;
}
