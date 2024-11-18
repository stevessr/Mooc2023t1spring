#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

// 判断是否是数字（包括整数和浮点数）
bool isNumber(const string& str) {
    stringstream ss(str);
    double temp;
    ss >> temp;
    return !ss.fail() && ss.eof();
}

// 判断运算符优先级，返回值较大表示优先级较高
int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;  // 加减优先级最低
    if (op == "*" || op == "/") return 2;  // 乘除优先级高
    return 0;
}

// 判断操作数是否包含加法或减法操作
bool hasAddOrSub(const string& expr) {
    return (expr.find("+") != string::npos || expr.find("-") != string::npos);
}

int main() {
    string str;
    stack<string> que;  // 用来保存操作数和中间结果

    while (cin >> str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            // 操作符处理
            string s1 = que.top(); que.pop();  // 取出栈顶的两个操作数
            string s2 = que.top(); que.pop();

            // 对加法和减法直接连接两个操作数
            if (str == "+" || str == "-") {
                que.push(s2 + " " + str + " " + s1);
            } else {
                // 对乘法和除法，检查左右操作数是否需要加括号
                if (hasAddOrSub(s1) && precedence(str) > precedence(s1)) {
                    s1 = "(" + s1 + ")";
                }
                if (hasAddOrSub(s2) && precedence(str) > precedence(s2)) {
                    s2 = "(" + s2 + ")";
                }
                que.push(s2 + " " + str + " " + s1);
            }
        } else if (isNumber(str)) {
            // 数字直接入栈
            que.push(str);
        }
    }

    // 最终栈中只有一个元素，即完整的中缀表达式
    cout << que.top() << endl;
    return 0;
}
