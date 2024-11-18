#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
// 调度场算法
// see also https://zh.wikipedia.org/wiki/调度场算法
int main()
{
    string str, temp;
    getline(cin, str);
    stringstream ss(str);
    string word;
    stack<string> s,o;
    while (ss >> word)
    {
        if (word == "+")
        {
            if(o.top=="")
        }
        else if (word == "-")
        {
        }
        else if (word == "*")
        {
        }
        else if (word == "/")
        {
        }else if(o.empty()||o.top()=="(")
        {
            o.push(word);
        }
        else
        {
            s.push(word);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
