#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int priority(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPrefix(string infix) {
    stack<char> s;
    string result = "";

    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Swap '(' and ')'
    for (char &ch : infix) {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    for (char ch : infix) {
        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else {
            while (!s.empty() && priority(s.top()) >= priority(ch)) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Prefix expression: " << infixToPrefix(infix) << endl;

    return 0;
}