// 字母频率统计2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int group[27] = {0};
    string str;
    while (getline(cin, str))
    {
        for (auto &i : str)
        {
            if (i >= 'a' && i <= 'z')
                group[i - 'a']++;
            // else if(i>='A'&&i<='Z') group[i-'A']++;
        }
    }
    sort(group, group + 26);
    int i;
    for (i = 0; i < 26; i++)
    {
        if (group[i] != 0)
        {
            break;
        }
    }
    vector<int> m(group[25] + 1, 0);
    for (; i < 26; i++)
    {
        for (int j = group[i]; j > 0; j--)
        {
            m[j]++;
        }
    }
    sort(m.rbegin(), m.rend());
    for (auto it = m.rbegin(); it < m.rend(); it++)
    {
        while (*it > 0)
        {
            cout << "#";
            *it -= 1;
            if (*it == 0)
            {
                cout << endl;
            }
        }
    }
    return 0;
}