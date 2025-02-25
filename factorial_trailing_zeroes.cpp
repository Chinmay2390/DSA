// factorial_trailing_zeroes.cpp - Count trailing zeroes in factorial
#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    int n = 100;
    cout << "Trailing zeroes in " << n << "! = " << trailingZeroes(n) << endl;  // Output: 24
    return 0;
}
