// climbing_stairs.cpp - DP solution to Climbing Stairs problem
#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;

    for (int i = 3; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

int main() {
    int n = 5;
    cout << "Ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
