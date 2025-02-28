// basic_calculator_iii.cpp - Handle + - * / with nested parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s, int& i) {
    stack<int> stk;
    int num = 0;
    char sign = '+';

    for (; i < s.length(); ++i) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '(') {
            ++i; // skip '('
            num = calculate(s, i);
        }

        if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1 || ch == ')') {
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

        if (ch == ')') break;
    }

    int result = 0;
    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }

    return result;
}

int calculate(string s) {
    int i = 0;
    return calculate(s, i);
}

int main() {
    string expr = "(2+6* 3+5- (3*14/7+2)*5)+3";
    cout << "Result: " << calculate(expr) << endl;  // Output: -12
    return 0;
}
