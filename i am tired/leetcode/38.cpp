#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        string str = "1";
        return circle(str, n);
    }
    string circle(string &s, int time)
    {
        if (time == 0)
        {
            return s;
        }
        string str="";
        {
            auto it = s.begin();
            auto last = it;
            int count = 1;
            while (it < s.end())
            {
                while (*(++it) == *(last) && it < s.end())
                {
                    count++;
                }
                str+=to_string(count)+*last;
                last = it;
                count = 1;
            }
        }
        return circle(str, time - 1);
    }
};
int main()
{
    Solution X;
    cout << X.countAndSay(4);
    return 0;
}