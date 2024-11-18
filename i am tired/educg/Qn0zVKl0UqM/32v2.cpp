#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int Ca, Cb, N; // A壶和B壶的容量，以及目标水量N
unordered_set<string> visited; // 用于记录访问过的状态
vector<string> endversion; // 记录最终的操作序列

// 表示水壶状态的类
class Solution {
public:
    int A, B;  // 当前A壶和B壶的水量
    vector<string> road;  // 记录操作序列

    Solution(int a = 0, int b = 0) : A(a), B(b) {}

    string getState() const {
        return to_string(A) + "-" + to_string(B);
    }

    // 执行Fill A操作
    bool FillA() {
        A = Ca;
        road.push_back("Fill A");
        return (B == N); // 如果B壶有目标水量N，返回成功
    }

    // 执行Fill B操作
    bool FillB() {
        B = Cb;
        road.push_back("Fill B");
        return (B == N);
    }

    // 执行Empty A操作
    bool EmptyA() {
        A = 0;
        road.push_back("Empty A");
        return (B == N);
    }

    // 执行Empty B操作
    bool EmptyB() {
        B = 0;
        road.push_back("Empty B");
        return (B == N);
    }

    // 执行Pour A B操作
    bool PourAB() {
        int transfer = min(A, Cb - B); // 计算A能倒入B的水量
        A -= transfer;
        B += transfer;
        road.push_back("Pour A B");
        return (B == N);
    }

    // 执行Pour B A操作
    bool PourBA() {
        int transfer = min(B, Ca - A); // 计算B能倒入A的水量
        B -= transfer;
        A += transfer;
        road.push_back("Pour B A");
        return (B == N);
    }

    // 执行操作并返回新状态
    bool applyAction(int action) {
        Solution newState = *this; // 复制当前状态
        bool result = false;
        switch (action) {
            case 1: result = newState.FillA(); break;
            case 2: result = newState.FillB(); break;
            case 3: result = newState.EmptyA(); break;
            case 4: result = newState.EmptyB(); break;
            case 5: result = newState.PourAB(); break;
            case 6: result = newState.PourBA(); break;
        }
        if (result) {
            road = newState.road; // 如果状态符合条件，将新状态的操作路径记录下来
        }
        return result;
    }
};

// BFS 深度优先的多层次搜索
bool bfs() {
    queue<Solution> q;
    q.push(Solution(0, 0)); // 从初始状态开始

    while (!q.empty()) {
        Solution current = q.front();
        q.pop();

        // 如果当前状态已经访问过，跳过
        if (visited.count(current.getState())) continue;

        visited.insert(current.getState()); // 标记当前状态为已访问

        // 检查每一种操作
        for (int i = 1; i <= 6; ++i) {
            Solution newState = current; // 复制当前状态
            if (newState.applyAction(i)) {
                endversion = newState.road; // 如果找到目标状态，记录操作序列
                return true;
            }
            q.push(newState); // 否则将新状态加入队列
        }
    }

    return false;
}

int main() {
    // 读取输入
    ifstream infile("jugs.in");
    infile >> Ca >> Cb >> N;
    infile.close();

    // 执行广度优先搜索
    if (bfs()) {
        // 输出结果到文件
        ofstream outfile("jugs.out");
        for (const string &action : endversion) {
            outfile << action << endl;
        }
        outfile.close();
    } else {
        // 如果没有找到解，输出没有解的情况
        ofstream outfile("jugs.out");
        outfile << "No solution" << endl;
        outfile.close();
    }

    return 0;
}
