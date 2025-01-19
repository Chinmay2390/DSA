// min_stack.cpp - Stack with constant time min()
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s, minS;
public:
    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top()) minS.push(val);
    }

    void pop() {
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;
    cout << "Min: " << minStack.getMin() << endl;
    return 0;
}
