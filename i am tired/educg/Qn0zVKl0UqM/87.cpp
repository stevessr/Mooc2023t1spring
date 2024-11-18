#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
using namespace std;

// 数据包结构体，用于表示字母在矩阵中的位置
struct pospack
{
    bool found; // 标识字母是否在矩阵中
    int x, y;   // 字母所在矩阵的行和列
    char ch;    // 字母本身
};

// 函数声明
pospack findornot(char pg[5][5], char ch);

int main()
{
    string key, todo;
    ifstream fin("encrypt.txt");
    getline(cin, key);
    getline(fin, todo);
    fin.close();
    string seen;
    char pg[5][5];
    char done = '0';
    bool flag = false;

    // 去重并记录密钥中出现的字母
    for (auto i = 0; i < key.size(); i++)
    {
        char *it = &key[i];
        if (flag)
        {
            if (*it == 'J' || *it == 'I')
            {
                break;
            }
        }
        if (seen.find(*it) == string::npos)
        {
            seen += (*it);
        }
        if (!flag)
        {
            if (*it == 'J' || *it == 'I')
            {
                done = *it;
                flag = true;
            }
        }
    }

    int px = 0, py = 0;
    for (auto &c : seen)
    {
        pg[px][py++] = c;
        if (py == 5)
        {
            py = 0;
            px++;
        }
        if (px == 5)
        {
            break;
        }
    }
    if (flag)
    {
        seen += 'J';
        seen += 'I';
    }
    // 按顺序填入未出现在密钥中的字母
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (seen.find(ch) == string::npos)
        {
            if(ch=='I'){
                seen+='I';
                seen+='J';
            }
            pg[px][py++] = ch;
            if (py == 5)
            {
                py = 0;
                px++;
            }
            if (px == 5)
            {
                break;
            }
        }
    }

    // 按顺序填入密钥中的字母

    // 处理字母对加密
    string ans;
    int len = todo.size();
    for (int i = 0; i < len; i += 2)
    {
        pospack pos1 = findornot(pg, todo[i]);
        pospack pos2 = (i + 1 < len) ? findornot(pg, todo[i + 1]) : pospack{false, 6, 6, '\0'};

        if (!pos1.found || !pos2.found || pos1.ch == pos2.ch)
        {
            // 情况 2 和 3：直接将字母对原样加入结果
            ans += pos1.ch;
            if (pos2.ch != '\0')
                ans += pos2.ch;
        }
        else if (pos1.x == pos2.x)
        {
            // 情况 4：同一行，交换字母
            ans += pos2.ch;
            ans += pos1.ch;
        }
        else if (pos1.y == pos2.y)
        {
            // 情况 4：同一列，交换字母
            ans += pos2.ch;
            ans += pos1.ch;
        }
        else
        {
            // 情况 5：矩形顶点替换
            ans += pg[pos1.x][pos2.y];
            ans += pg[pos2.x][pos1.y];
        }
    }
    ofstream fout("output.txt");
    cout << ans << endl;
    // 输出加密后的字符串
    fout << ans << endl;
    fout.close();
    return 0;
}

// 查找字母是否在矩阵中
pospack findornot(char pg[5][5], char ch)
{
    pospack p;
    p.ch = ch;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (pg[i][j] == ch)
            {
                p.found = true;
                p.x = i;
                p.y = j;
                return p;
            }
        }
    }
    p.found = false;
    return p;
}
