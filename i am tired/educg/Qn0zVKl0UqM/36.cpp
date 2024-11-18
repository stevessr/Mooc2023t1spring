#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(int N, vector<int> &current, vector<bool> &used)
{
    if (current.size() == N)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << current[i];
            if (i != N - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!used[i])
        {                                // 如果数字i没有被使用
            used[i] = true;              // 标记数字i为已使用
            current.push_back(i);        // 将数字i加入当前排列
            backtrack(N, current, used); // 继续递归生成后续的排列
            current.pop_back();          // 回溯，撤销选择
            used[i] = false;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> current;
    vector<bool> used(N + 1, false);
    backtrack(N, current, used);
    return 0;
}
