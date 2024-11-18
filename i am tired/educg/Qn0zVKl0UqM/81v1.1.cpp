#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// 用来查找字符在5x5矩阵中的位置
pair<int, int> findPosition(char ch, char pg[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (pg[i][j] == ch) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // 如果找不到，返回无效位置
}

// 构造5x5矩阵
void createMatrix(const string& key, char pg[5][5]) {
    unordered_set<char> used; // 用于记录已经使用的字符
    int px = 0, py = 0;

    // 首先填入密钥中的字符
    for (char ch : key) {
        if (used.find(ch) == used.end()) {
            pg[px][py++] = ch;
            used.insert(ch);
            if (py == 5) {
                py = 0;
                px++;
            }
        }
    }

    // 填入剩余的字母
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (used.find(ch) == used.end() && ch != 'j') {  // 'j' 和 'i' 合并
            pg[px][py++] = ch;
            used.insert(ch);
            if (py == 5) {
                py = 0;
                px++;
            }
        }
    }
}

// 加密一对字母
string encryptPair(char a, char b, char pg[5][5]) {
    pair<int, int> posA = findPosition(a, pg);
    pair<int, int> posB = findPosition(b, pg);

    // 如果任意一个字符不在矩阵中，直接返回原字符
    if (posA.first == -1 || posB.first == -1) {
        return string(1, a) + b;
    }

    // 如果在同一行
    if (posA.first == posB.first) {
        return string(1, pg[posA.first][(posA.second + 1) % 5]) + pg[posB.first][(posB.second + 1) % 5];
    }
    // 如果在同一列
    if (posA.second == posB.second) {
        return string(1, pg[(posA.first + 1) % 5][posA.second]) + pg[(posB.first + 1) % 5][posB.second];
    }
    // 否则，形成矩形
    return string(1, pg[posA.first][posB.second]) + pg[posB.first][posA.second];
}

// 处理待加密字符串
string processMessage(string message, char pg[5][5]) {
    // 如果字符串长度是奇数，添加一个 'x' 来填充
    if (message.length() % 2 != 0) {
        message += 'x';
    }

    string processedMessage;
    for (size_t i = 0; i < message.length(); i += 2) {
        char a = message[i];
        char b = message[i + 1];
        
        // 如果是重复字母对，如 "aa"，则用 'x' 代替第二个字符
        if (a == b) {
            processedMessage += encryptPair(a, 'x', pg);
            i--;  // 退回一位，重新处理这对字符
        } else {
            processedMessage += encryptPair(a, b, pg);
        }
    }
    return processedMessage;
}

int main() {
    string key, todo;
    getline(cin, key);  // 密钥
    getline(cin, todo); // 待加密字符串

    // 构建5x5矩阵
    char pg[5][5] = {{0}};
    createMatrix(key, pg);

    // 处理待加密字符串
    string encryptedMessage = processMessage(todo, pg);

    // 输出加密后的字符串
    cout << encryptedMessage << endl;

    return 0;
}
