#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

struct pospack {
    bool found;
    int x, y;
    char ch;
};

pospack findornot(char pg[5][5], char ch);

int main() {
    string key, todo;
    getline(cin, key);
    getline(cin, todo);
    unordered_set<char> s;
    char pg[5][5];
    for (auto &i : key) {
        s.insert(i);
    }
    int px = 0, py = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (s.find(ch) == s.end()) {
            pg[px][py++] = ch;
            if (py == 5) {
                py = 0, px++;
            }
        }
    }
    vector<char> v;
    for (auto &i : s) {
        v.push_back(i);
    }
    for (auto it = v.rbegin(); it != v.rend() && px < 5; it++) {
        pg[px][py++] = *it;
        if (py == 5) {
            py = 0, px++;
        }
    }
    int sp = todo.size() / 2;
    pospack pos[2];
    string ans;
    for (int i = 0; i < sp; i++) {
        pos[0] = findornot(pg, todo[i * 2]);
        pos[1] = findornot(pg, todo[i * 2 + 1]);
        if (pos[0].found && pos[1].found) {
            if (pos[0].x == pos[1].x) {
                ans += pos[1].ch;
                ans += pos[0].ch;
            } else if (pos[0].y == pos[1].y) {
                ans += pos[1].ch;
                ans += pos[0].ch;
            } else {
                ans += pg[pos[0].x][pos[1].y];
                ans += pg[pos[1].x][pos[0].y];
            }
        } else if (pos[0].found || pos[1].found) {
            ans += pos[0].ch;
            ans += pos[1].ch;
        } else {
            ans += pos[1].ch;
            ans += pos[0].ch;
        }
    }
    if (sp * 2 < todo.size()) {
        ans += todo[sp * 2];
    }
    cout << ans << endl;
    return 0;
}

pospack findornot(char pg[5][5], char ch) {
    pospack p;
    p.ch = ch;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (pg[i][j] == ch) {
                p.found = true;
                p.x = i;
                p.y = j;
                return p;
            }
        }
    }
    p.found = false;
    p.x = -1, p.y = -1; // 使用 -1 表示未找到
    return p;
}