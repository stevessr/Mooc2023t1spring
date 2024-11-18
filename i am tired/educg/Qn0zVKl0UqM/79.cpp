#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int n = str.size();
    vector<int> dp(n, 1); // dp[i] 表示以第 i 个字符结尾的最长升序子串长度

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (str[i] >= str[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ma = 0;
    for (auto &i : dp)
    {
        if (i > ma)
        {
            ma = i;
        }
    }
    cout << ma << endl;
    return 0;
}
