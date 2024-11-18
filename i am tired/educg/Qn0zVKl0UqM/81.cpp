#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 构建加密表
vector<vector<char>> buildSquare(const string &key) {
    unordered_set<char> used;
    vector<vector<char>> square(5, vector<char>(5));
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int idx = 0;

    // 填入字母表中不在密钥中的字母
    for (char c : alphabet) {
        if (key.find(c) == string::npos) {
            used.insert(c);
            square[idx / 5-1][idx % 5] = c;
            idx++;
        }
    }

    // 填入密钥中的字母
    for (char c : key) {
        if (used.find(c) == used.end()) {
            used.insert(c);
            square[idx / 5][idx % 5] = c;
            idx++;
        }
    }

    return square;
}

// 获取字母的行列位置
unordered_map<char, pair<int, int>> buildLookup(const vector<vector<char>> &square) {
    unordered_map<char, pair<int, int>> lookup;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            lookup[square[i][j]] = {i, j};
        }
    }
    return lookup;
}

// 加密函数
string encrypt(const string &input, const vector<vector<char>> &square,
               const unordered_map<char, pair<int, int>> &lookup) {
    string result;
    for (size_t i = 0; i < input.size(); i += 2) {
        char c1 = input[i];
        char c2 = (i + 1 < input.size()) ? input[i + 1] : '\0';

        // 如果只剩一个字母
        if (c2 == '\0') {
            result.push_back(c1);
            break;
        }

        // 如果两个字母相同或有字母不在正方形中
        if (c1 == c2 || lookup.find(c1) == lookup.end() || lookup.find(c2) == lookup.end()) {
            result.push_back(c1);
            result.push_back(c2);
            continue;
        }

        auto [r1, c1_pos] = lookup.at(c1);
        auto [r2, c2_pos] = lookup.at(c2);

        // 同一行，交换列
        if (r1 == r2) {
            result.push_back(square[r1][c2_pos]);
            result.push_back(square[r2][c1_pos]);
        }
        // 同一列，交换行
        else if (c1_pos == c2_pos) {
            result.push_back(square[r2][c1_pos]);
            result.push_back(square[r1][c2_pos]);
        }
        // 矩形，取对角
        else {
            result.push_back(square[r1][c2_pos]);
            result.push_back(square[r2][c1_pos]);
        }
    }
    return result;
}

int main() {
    string key, input;

    // 输入密钥和待加密字符串
    getline(cin, key);
    getline(cin, input);

    // 构建加密表和查找表
    vector<vector<char>> square = buildSquare(key);
    unordered_map<char, pair<int, int>> lookup = buildLookup(square);

    // 加密字符串
    string result = encrypt(input, square, lookup);

    // 输出结果
    cout << result << endl;

    return 0;
}
