#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    char ch;
    cin >> ch;
    cin.ignore(); 

    string str;
    set<string> stset;
    while (getline(cin, str) && str != "@")
    {
        string temp;
        for (char cp : str)
        {
            if (cp != ch && cp!='@') // 删除指定字符
            {
                temp += cp;
            }
        }
        stset.insert(temp); // 将处理后的字符串加入 set
    }
    for (auto it = stset.rbegin(); it != stset.rend(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}
