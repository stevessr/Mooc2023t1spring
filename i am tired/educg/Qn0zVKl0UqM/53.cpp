#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // 输入队员人数
    vector<int> times(n);
    
    for (int i = 0; i < n; i++) {
        cin >> times[i];  // 输入每个队员到达终点的时间
    }

    if (n == 1) {
        cout << times[0] << endl;
        return 0;
    }

    // 动态规划数组 dp[i] 表示前i个队员的最短时间
    vector<int> dp(n + 1, 0);

    // 初始化：第一个队员的时间
    dp[1] = times[0];

    // 处理配对的动态规划，dp[i]表示前i个队员的最短完成时间
    for (int i = 2; i <= n; i++) {
        // 1. 最后两个人一起游泳
        dp[i] = max(dp[i - 2] + times[i - 1], dp[i - 1] + times[i - 1]);
        
        // 2. 如果有特殊情况下需要背回，可以考虑这样的配对
        // 对队员进行背回操作
    }

    // 输出最终的结果
    cout << dp[n] << endl;

    return 0;
}
