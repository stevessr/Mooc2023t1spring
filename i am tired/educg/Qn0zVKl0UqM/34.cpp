#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

// 使用埃拉托斯特尼筛法预处理质数
unordered_set<int> generatePrimes(int maxVal) {
    vector<bool> isPrime(maxVal + 1, true);
    isPrime[0] = isPrime[1] = false;  // 0和1不是质数
    for (int i = 2; i * i <= maxVal; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxVal; j += i) {
                isPrime[j] = false;
            }
        }
    }
    unordered_set<int> primes;
    for (int i = 2; i <= maxVal; ++i) {
        if (isPrime[i]) {
            primes.insert(i);
        }
    }
    return primes;
}

// 回溯法，寻找所有符合条件的排列
void backtrack(int node, vector<int>& nodes, vector<bool>& visited, int N, const unordered_set<int>& primes, vector<vector<int>>& results) {
    if (node == N) {  // 所有节点都已放置完
        if (primes.count(nodes[N-1] + nodes[0])) { // 检查最后一个节点和第一个节点的和是否是质数
            results.push_back(nodes);  // 如果是质数，保存当前排列
        }
        return;
    }

    // 尝试将一个未被访问的数字放入当前位置
    for (int i = 2; i <= N; ++i) {
        if (!visited[i] && primes.count(nodes[node-1] + i)) {
            visited[i] = true;
            nodes[node] = i;
            backtrack(node + 1, nodes, visited, N, primes, results);  // 继续递归
            visited[i] = false;  // 回溯
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 预处理所有可能的质数（最大为20 + 20 = 40）
    unordered_set<int> primes = generatePrimes(40);

    // 初始化节点
    vector<int> nodes(N);
    vector<bool> visited(N + 1, false);
    
    // 将1放在第一个位置
    nodes[0] = 1;
    visited[1] = true;

    vector<vector<int>> results;
    // 从第二个节点开始回溯
    backtrack(1, nodes, visited, N, primes, results);

    // 输出所有合法的排列
    if (results.empty()) {
        cout << "No solution" << endl;
    } else {
        for (const auto& result : results) {
            for (int i = 0; i < N; ++i) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
