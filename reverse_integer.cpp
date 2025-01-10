// reverse_integer.cpp - Reverse an integer and handle overflow
#include <iostream>
using namespace std;

int reverse(int x) {
    long long rev = 0;
    while (x) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return (rev < INT_MIN || rev > INT_MAX) ? 0 : rev;
}

int main() {
    int x = 123;
    cout << "Reversed: " << reverse(x) << endl;
    return 0;
}

