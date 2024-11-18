#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

// 对应操作类型的字符串
const string operations[] = {
    "Fill A",   // type 0
    "Fill B",   // type 1
    "Empty A",  // type 2
    "Empty B",  // type 3
    "Pour A B", // type 4
    "Pour B A"  // type 5
};

// 操作函数
class Solution
{
    // 操作函数：根据type执行操作，返回新的水量
    inline pair<int, int> op(int type, const pair<int, int> &state, int x, int y)
    {
        switch (type)
        {
        case 0:
            return make_pair(x, state.second); // Fill A
        case 1:
            return make_pair(state.first, y); // Fill B
        case 2:
            return make_pair(0, state.second); // Empty A
        case 3:
            return make_pair(state.first, 0); // Empty B
        case 4:
        { // Pour A B
            int move = min(state.first, y - state.second);
            return make_pair(state.first - move, state.second + move);
        }
        case 5:
        { // Pour B A
            int move = min(x - state.first, state.second);
            return make_pair(state.first + move, state.second - move);
        }
        }
        return make_pair(0, 0);
    }

    struct HashPair
    {
        size_t operator()(const pair<int, int> &key) const noexcept
        {
            return (size_t(key.first) << 31) | size_t(key.second);
        }
    };

    // 用int64_t作为hash值
    inline int64_t Hash(int x, int y)
    {
        return int64_t(x) << 32 | y;
    }

public:
    vector<string> solve(int x, int y, int z)
    {
        vector<string> result;
        if (x + y < z)
        { // 剪枝：x + y如果小于目标水量z，则不可能完成
            return result;
        }

        unordered_set<int64_t> mark;                // 记录访问过的状态
        queue<pair<pair<int, int>, vector<int>>> q; // 队列保存状态和路径
        q.push(make_pair(make_pair(0, 0), vector<int>()));

        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            int a = f.first.first;
            int b = f.first.second;
            vector<int> path = f.second;

            if (b == z)
            {
                // 如果B壶中水量等于目标，返回路径
                for (int opIndex : path)
                {
                    result.push_back(operations[opIndex]);
                }
                result.push_back("Success");
                return result;
            }

            // 对每个操作类型进行尝试
            for (int i = 0; i < 6; i++)
            {
                auto next = op(i, f.first, x, y);
                int64_t h = Hash(next.first, next.second);
                if (mark.find(h) != mark.end())
                {
                    continue; // 如果这个状态已经访问过，跳过
                }
                mark.insert(h);

                // 将新状态和路径加入队列
                path.push_back(i);
                q.push(make_pair(make_pair(next.first, next.second), path));
                path.pop_back();
            }
        }

        return result; // 如果没有找到解，返回空结果
    }
};

int main()
{
    int Ca, Cb, N;
    ifstream infile("jugs.in");
    infile >> Ca >> Cb >> N;
    infile.close();

    Solution solution;
    vector<string> result = solution.solve(Ca, Cb, N);
    ofstream outfile("jugs.out");
    // 输出结果
    for (const string &action : result)
    {
        outfile << action << endl;
    }
    outfile.close();
    return 0;
}
