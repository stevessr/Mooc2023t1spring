#include <iostream>
#include <vector>
#pragma GCC optimize("O3")
using namespace std;

void target(int s);

int main()
{
    short s;
    cin >> s;
    target(s * s * s);
    return 0;
}

void target(int s)
{
    int sum, current;
    vector<int> vint;

    // 从1开始循环到 s 的平方根
    for (int start = 1; start < s; start += 2) // start 是奇数
    {
        sum = 0;
        current = start;
        vint.clear();

        // 累加奇数直到 sum >= s
        while (sum < s)
        {
            sum += current;
            vint.push_back(current);
            current += 2;

            // 检查是否找到匹配的 sum
            if (sum == s)
            {
                for (const auto &i : vint)
                {
                    cout << i << " ";
                }
                return; // 找到后立即返回
            }
        }
    }
}
