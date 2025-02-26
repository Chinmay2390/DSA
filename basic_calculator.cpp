// basic_calculator.cpp - Evaluate a basic arithmetic expression with parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    int result = 0, sign = 1, num = 0;
    stack<int> st;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * num;
            sign = 1;
            num = 0;
        } else if (ch == '-') {
            result += sign * num;
            sign = -1;
            num = 0;
        } else if (ch == '(') {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * num;
            result *= st.top(); st.pop();  // sign before '('
            result += st.top(); st.pop();  // result before '('
            num = 0;
        }
    }

    return result + (sign * num);
}

int main() {
    string expr = "(1+(4+5+2)-3)+(6+8)";
    cout << "Result: " << calculate(expr) << endl;  // Output: 23
    return 0;
}
