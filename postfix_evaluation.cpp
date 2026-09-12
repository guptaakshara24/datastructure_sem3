#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            switch (ch) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                default:
                    cout << "Invalid operator";
                    return 0;
            }

            s.push(result);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}