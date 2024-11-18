#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// 执行二元运算
int applyOperation(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b; 
    }
    return 0;
}


int evaluateExpression(const string& expression) {
    stack<int> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (isspace(c)) {
            continue; 
        }
        if (isdigit(c)) {
            int value = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                ++i;
            }
            --i;
            values.push(value);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && operators.top() != '(' &&
                   ((c == '+' || c == '-') && (operators.top() == '*' || operators.top() == '/')) == false) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {
    string expression, input;

    while (cin >> input && input != "=") {
        expression += input;
    }

    int result = evaluateExpression(expression);

    cout << result << endl;

    return 0;
}
