// basic_calculator_ii.cpp - Evaluate arithmetic expression with + - * /
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    int n = s.size();
    stack<int> stk;
    int num = 0;
    char sign = '+';

    for (int i = 0; i < n; ++i) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        }

        if ((!isdigit(ch) && ch != ' ') || i == n - 1) {
            if (sign == '+') stk.push(num);
            else if (sign == '-') stk.push(-num);
            else if (sign == '*') {
                int top = stk.top(); stk.pop();
                stk.push(top * num);
            } else if (sign == '/') {
                int top = stk.top(); stk.pop();
                stk.push(top / num);
            }

            sign = ch;
            num = 0;
        }
    }

    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return result;
}

int main() {
    string expr = "3+2*2";
    cout << "Result: " << calculate(expr) << endl;  // Output: 7
    return 0;
}
