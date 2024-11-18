#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;

class wordclass
{
public:
    string word;
    string line;

    wordclass(string WORD, string LINE) : word(WORD), line(LINE) {}

    friend ostream &operator<<(ostream &os, const wordclass &dt)
    {
        os << dt.word + ":" + dt.line;
        return os;
    }

    bool operator<(const wordclass &dt) const
    {
        return word < dt.word;
    }
};

int main()
{
    ifstream file("crossin.txt");
    string line, word;
    stringstream ss;
    int p = 0, j;

    // 用 unordered_map 直接在读取文件时合并相同的 word
    unordered_map<string, string> wordMap;

    while (getline(file, line))
    {
        p++; // 当前行数
        j = 1; // 当前列位置

        ss = stringstream(line);
        while (ss >> word)
        {
            // 跳过数字和常见词
            if (word[0] >= '0' && word[0] <= '9' || word == "a" || word == "an" || word == "the" || word == "and")
            {
                continue;
            }
            // 去掉标点符号
            if ((word.find(".") != string::npos) || (word.find(",") != string::npos))
            {
                word.erase(word.length() - 1);
            }

            // 构造位置字符串
            string position = "(" + to_string(p) + "," + to_string(j) + ")";

            // 检查 word 是否已存在于 wordMap 中
            if (wordMap.find(word) != wordMap.end())
            {
                // 存在则追加位置
                wordMap[word] += "," + position;
            }
            else
            {
                // 不存在则插入新位置
                wordMap[word] = position;
            }

            // 更新列位置
            j += word.length() + 1;
        }
    }

    // 将 wordMap 转换为 set<wordclass> 以保持排序
    set<wordclass> wordset;
    for (const auto &entry : wordMap)
    {
        wordset.insert(wordclass(entry.first, entry.second));
    }

    // 输出结果
    for (const auto &i : wordset)
    {
        cout << i << endl;
    }

    return 0;
}
