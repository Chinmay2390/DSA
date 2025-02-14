// android_unlock_patterns.cpp - Count valid patterns for Android lock screen
#include <iostream>
#include <vector>
using namespace std;

int skip[10][10];

void initSkip() {
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[3][9] = skip[9][3] = 6;
    skip[7][9] = skip[9][7] = 8;
    skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] =
    skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
}

int backtrack(int visited, int curr, int remaining) {
    if (remaining == 0) return 1;

    int count = 0;
    for (int next = 1; next <= 9; ++next) {
        if (!(visited & (1 << next))) {
            int s = skip[curr][next];
            if (s == 0 || (visited & (1 << s))) {
                count += backtrack(visited | (1 << next), next, remaining - 1);
            }
        }
    }
    return count;
}

int numberOfPatterns(int m, int n) {
    initSkip();
    int total = 0;
    for (int len = m; len <= n; ++len) {
        total += backtrack(1 << 1, 1, len - 1) * 4;
        total += backtrack(1 << 2, 2, len - 1) * 4;
        total += backtrack(1 << 5, 5, len - 1);
    }
    return total;
}

int main() {
    cout << "Total Patterns (Length 1 to 2): " << numberOfPatterns(1, 2) << endl;
    return 0;
}
