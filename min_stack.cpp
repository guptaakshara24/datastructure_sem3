#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {
    }

    void push(int value) {
        if (minst.empty() || minst.top() >= value) {
            minst.push(value);
        } else {
            minst.push(minst.top());
        }

        st.push(value);
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        st.pop();
        minst.pop();
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return st.top();
    }

    int getMin() {
        if (minst.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return minst.top();
    }
};