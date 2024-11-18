#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;
class datapack
{
public:
    string str;
    bool special;
    datapack(string STR = "", bool SP = false) : str(STR), special(SP) {}
    void empty() { str.empty(), special = false; }
};
int main()
{
    string str, line;
    datapack s1, s2, temp;
    stack<datapack> que;
    getline(cin, line);
    istringstream fuline(line);
    while (fuline >> str)
    {
        if (str == "+")
        {
            s1 = que.top();
            que.pop();
            s2 = que.top();
            que.pop();
            temp.str = s2.str + "+" + s1.str;
            temp.special = true;
            que.push(temp);
            s1.empty(), s2.empty(), temp.empty();
        }
        else if (str == "-")
        {
            s1 = que.top();
            que.pop();
            s2 = que.top();
            que.pop();
            if (s1.special)
            {
                s1.str = "(" + s1.str + ")";
            }
            temp.str = s2.str + "-" + s1.str;
            temp.special = true;
            que.push(temp);
            s1.empty(), s2.empty(), temp.empty();
        }
        else if (str == "*")
        {
            s1 = que.top();
            que.pop();
            s2 = que.top();
            que.pop();
            if (s1.special)
            {
                s1.str = "(" + s1.str + ")";
            }
            if (s2.special)
            {
                s2.str = "(" + s2.str + ")";
            }
            temp.str = s2.str + "*" + s1.str;
            temp.special = false;
            que.push(temp);
            s1.empty(), s2.empty(), temp.empty();
        }
        else if (str == "/")
        {
            s1 = que.top();
            que.pop();
            s2 = que.top();
            que.pop();
            if (s1.special || s1.str.find("*") != string::npos)
            {
                s1.str = "(" + s1.str + ")";
            }
            if (s2.special)
            {
                s2.str = "(" + s2.str + ")";
            }
            temp.str = s2.str + "/" + s1.str;
            que.push(temp);
            s1.empty(), s2.empty(), temp.empty();
        }
        else
        {
            temp = datapack(str);
            temp.special = false;
            que.push(temp);
            temp.empty();
        }
    }
    cout << temp.str;
    return 0;
}