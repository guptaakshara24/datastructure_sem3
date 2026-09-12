#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string prefix;
    stack<int> s;

    cout << "Enter prefix expression: ";
    cin >> prefix;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int a = s.top();
            s.pop();

            int b = s.top();
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
            }

            s.push(result);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}