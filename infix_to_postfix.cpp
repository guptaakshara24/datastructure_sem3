#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isopr(char x);
int prec(char y);
bool isrightprec(char z);

string infixToPostfix(string infix) {
    stack<char> s;
    string post = "";

    for (char c : infix) {

        if (isalnum(c)) {
            post += c;
        }

        else if (c == '(') {
            s.push(c);
        }

        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                post += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        else if (isopr(c)) {

            while (!s.empty() &&
                   s.top() != '(' &&
                   (prec(s.top()) > prec(c) ||
                   (prec(c) == prec(s.top()) && !isrightprec(c)))) {

                post += s.top();
                s.pop();
            }

            s.push(c);
        }
    }

    while (!s.empty()) {
        post += s.top();
        s.pop();
    }

    return post;
}

bool isopr(char x) {
    if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^')
        return true;

    return false;
}

int prec(char y) {
    if (y == '^')
        return 3;
    else if (y == '*' || y == '/')
        return 2;
    else if (y == '+' || y == '-')
        return 1;
    else
        return 0;
}

bool isrightprec(char z) {
    return (z == '^');
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix);

    return 0;
}