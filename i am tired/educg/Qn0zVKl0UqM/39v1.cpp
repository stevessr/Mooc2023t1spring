#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
string infixToPostfix(string expr)
{
    stack<char> s;
    string result = "";

    for (char c : expr)
    {
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c))
            {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    cout << infixToPostfix(str) << endl;

    return 0;
}
