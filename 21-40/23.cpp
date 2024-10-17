#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int times;
    cin >> times;
    
    // 存储收缩压和舒张压的值
    vector<pair<int, int>> pressure(times);
    
    for (int i = 0; i < times; i++)
    {
        cin >> pressure[i].first >> pressure[i].second;
    }

    int max_hours = 0;  // 记录最长连续正常小时数
    int current_hours = 0;  // 当前连续正常小时数

    for (int i = 0; i < times; i++)
    {
        // 判断当前时间段的血压是否正常
        if (pressure[i].first >= 90 && pressure[i].first <= 140 &&
            pressure[i].second >= 60 && pressure[i].second <= 90)
        {
            current_hours++;  // 连续正常小时数加1
        }
        else
        {
            // 若不正常，比较当前连续正常小时数并重置
            if (current_hours > max_hours)
            {
                max_hours = current_hours;
            }
            current_hours = 0;  // 重置连续正常小时数
        }
    }

    // 在循环结束后，再次检查current_hours
    if (current_hours > max_hours)
    {
        max_hours = current_hours;
    }

    // 输出最长连续正常小时数
    cout << max_hours << endl;

    return 0;
}
