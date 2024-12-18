//中缀转后缀
#include <string>
#include <stack>
#include <iostream>
using namespace std;
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}
int prec(char c)
{
    // 乘法和除法
    if (c == '*' || c == '/') {
        return 3;
    }
    // 加减
    if (c == '+' || c == '-') {
        return 4;
    }
    // Bitwise AND
    if (c == '&') {
        return 8;
    }
    // 按位异或(异或)
    if (c == '^') {
        return 9;
    }
    // 按位或(包括或)
    if (c == '|') {
        return 10;
    }
    // 如果需要，添加更多运算符
    return 11;            // 用于左括号'('
}
string infixToPostfix(const string & infix)
{
    // 创建一个空Stack来存储操作符
    stack<char> s;
 
    // 创建一个字符串来存储后缀表达式
    string postfix;
 
    // 从左到右处理中缀表达式
    for (char c: infix)
    {
        // 情况 1. 如果当前标记是一个左括号 '(',
        // 压入Stack中
        if (c == '(') {
            s.push(c);
        }
        // 情况 2. 如果当前标记是右括号 ')'
        else if (c == ')')
        {
            // 从Stack栈中弹出标记，直到对应的左括号 '('
            // 已移除。将每个运算符附加到后缀表达式的末尾
            while (s.top() != '(')
            {
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        // 情况 3. 如果当前标记是操作数，则将其附加到操作数的末尾
        // 后缀表达式
        else if (isOperand(c)) {
            postfix.push_back(c);
        }
        // 案例4. 如果当前token是一个操作符
        else {
            // 从Stack栈中删除具有更高或相等优先级的运算符
            // 并将它们附加到后缀表达式的末尾
            while (!s.empty() && prec(c) >= prec(s.top()))
            {
                postfix.push_back(s.top());
                s.pop();
            }
            // 最后，将当前操作符压入Stack顶
            s.push(c);
        }
    }
 
    // 将Stack栈中剩余的所有运算符附加到后缀表达式的末尾
    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }
 
    // 返回后缀表达式
    return postfix;
}
int main(){
    string str;
    getline(cin,str);
    cout<<infixToPostfix(str);
    return 0;
}