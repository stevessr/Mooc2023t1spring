#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str;
    char ch;
    vector<int> num;
    cin >> str >> ch;
    int strsize = str.size();
    for (int i = 0; i < strsize; i++)
    {
        if (str[i] == ch)
        {
            num.push_back(i);
        }
    }
    if (num.empty())
    {
        cout << "NULL";
    }
    else
    {
        for (auto j : num)
        {
            cout << j << " ";
        }
    }
    return 0;
}