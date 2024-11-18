#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 定义操作
pair<int, int> fillA(int a, int b, int Ca, int Cb) {
    return {Ca, b};
}

pair<int, int> fillB(int a, int b, int Ca, int Cb) {
    return {a, Cb};
}

pair<int, int> emptyA(int a, int b, int Ca, int Cb) {
    return {0, b};
}

pair<int, int> emptyB(int a, int b, int Ca, int Cb) {
    return {a, 0};
}

pair<int, int> pourAtoB(int a, int b, int Ca, int Cb) {
    int pourAmount = min(a, Cb - b);
    return {a - pourAmount, b + pourAmount};
}

pair<int, int> pourBtoA(int a, int b, int Ca, int Cb) {
    int pourAmount = min(b, Ca - a);
    return {a + pourAmount, b - pourAmount};
}

// 执行BFS并找到操作序列
vector<string> bfs(int Ca, int Cb, int N) {
    queue<pair<pair<int, int>, vector<string>>> q;  // 队列存储(状态, 操作序列)
    set<pair<int, int>> visited;  // 记录已访问的状态

    // 初始状态是两个水壶都为空
    pair<int, int> start = {0, 0};
    q.push({start, {}});
    visited.insert(start);

    // 操作序列
    vector<pair<string, pair<int, int> (*)(int, int, int, int)>> operations = {
        {"Fill A", fillA},
        {"Pour A B", pourAtoB},
        {"Fill B", fillB},
        {"Pour B A", pourBtoA},
        {"Empty A", emptyA},
        {"Empty B", emptyB}
    };

    // 执行BFS
    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        pair<int, int> current = front.first;
        vector<string> history = front.second;

        int a = current.first;
        int b = current.second;

        // 如果B壶中的水量达到了目标水量N
        if (b == N) {
            history.push_back("Success");
            return history;
        }

        // 按照固定的操作顺序执行
        for (auto& op : operations) {
            pair<int, int> newState = op.second(a, b, Ca, Cb);

            if (visited.find(newState) == visited.end()) {
                visited.insert(newState);
                vector<string> newHistory = history;
                newHistory.push_back(op.first);
                q.push({newState, newHistory});
            }
        }
    }

    return {};  // 如果没有找到解
}

int main() {
    int Ca, Cb, N;
    // 读取输入
    cin >> Ca >> Cb >> N;

    // 执行BFS以找到操作序列
    vector<string> result = bfs(Ca, Cb, N);

    // 输出结果
    if (!result.empty()) {
        for (const string& op : result) {
            cout << op << endl;
        }
    }

    return 0;
}
