#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}

string infixToPostfix(const string& expression) {
    stack<char> operators;
    stringstream output;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (isspace(c)) {
            continue;
        } else if (isdigit(c)) {
            while (i < expression.size() && isdigit(expression[i])) {
                output << expression[i++];
            }
            output << ' ';
            --i;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                output << operators.top() << ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        output << operators.top() << ' ';
        operators.pop();
    }

    return output.str();
}

int evaluatePostfix(const string& postfix) {
    stack<int> values;
    stringstream tokens(postfix);
    string token;

    while (tokens >> token) {
        if (isdigit(token[0])) {
            values.push(stoi(token));
        } else {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            values.push(applyOperation(a, b, token[0]));
        }
    }

    return values.top();
}

int main() {
    string expression, input;

    while (cin >> input && input != "=") {
        expression += input;
    }

    string postfix = infixToPostfix(expression);
    int result = evaluatePostfix(postfix);

    cout  << result << endl;

    return 0;
}
