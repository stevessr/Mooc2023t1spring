#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;

// 第一次匹配的正则预处理
string preprocessPattern(const string &pattern)
{
    string regexPattern;
    bool inBrackets = false;
    bool excludeMode = false;

    for (size_t i = 0; i < pattern.size(); ++i)
    {
        char c = pattern[i];
        if (c == '*')
        {
            regexPattern += ".*?";
        }
        else if (c == '[')
        {
            inBrackets = true;
            excludeMode = (i + 1 < pattern.size() && pattern[i + 1] == '^');
            regexPattern += "[";
            if (excludeMode)
            {
                regexPattern += "^";
                ++i;
            }
        }
        else if (c == ']')
        {
            inBrackets = false;
            regexPattern += "]";
        }
        else
        {
            if (inBrackets)
            {
                regexPattern += c;
            }
            else
            {
                regexPattern += "[";
                regexPattern += static_cast<char>(toupper(c));
                regexPattern += static_cast<char>(tolower(c));
                regexPattern += "]";
            }
        }
    }

    return regexPattern;
}

// 二次匹配的正则预处理
string preprocessSecondPattern(const string &pattern)
{
    // 这里我们可以定义一个简单的二次匹配规则，假设我们再次匹配某种特定的子串
    string secondRegexPattern = pattern;
    // 可以在这里添加你想要的处理逻辑
    return secondRegexPattern;
}

int main()
{
    string inputPattern, line;
    ifstream fin("string.in");
    cout << "Enter the pattern: ";
    getline(cin, inputPattern);

    // 读取输入文本
    vector<string> lines;
    while (getline(fin, line))
    {
        lines.push_back(line);
    }

    // 处理正则表达式
    string regexPattern = preprocessPattern(inputPattern);
    regex re(regexPattern, regex::icase);

    // 假设我们使用一个新的正则表达式来进行二次匹配
    string secondPattern = regexPattern;//"yourSecondPattern"; // 这里可以根据需要进行修改
    regex reSecond(preprocessSecondPattern(secondPattern), regex::icase);

    ofstream outFile("string.out");

    // 遍历每行
    for (size_t i = 0; i < lines.size(); ++i)
    {
        smatch match;
        string currentLine = lines[i];
        vector<string> matches;
        auto searchStart = currentLine.cbegin();

        // 第一次匹配
        while (searchStart != currentLine.cend() && regex_search(searchStart, currentLine.cend(), match, re))
        {
            matches.push_back(match.str());
            // 通过将 searchStart 回退到当前匹配的起始位置，来确保重叠匹配被捕获
            searchStart = match.prefix().first + 1;
        }

        // 对每个第一次匹配到的结果进行二次匹配
        for (auto &m : matches)
        {
            smatch secondMatch;
            if (regex_search(m, secondMatch, reSecond))
            {
                // 这里你可以根据需要处理第二次匹配到的内容
                cout << "Second match for '" << m << "': " << secondMatch.str() << endl;
            }
        }

        // 输出结果
        string temp = "";
        if (!matches.empty())
        {
            outFile << (i + 1) << ":";
            cout << (i + 1) << ":";
            for (size_t j = 0; j < matches.size(); ++j)
            {
                if (j > 0)
                {
                    temp += ",";
                }
                temp += matches[j];
            }
            temp += "\n";
            cout << temp;
            outFile << temp;
        }
    }

    outFile.close();
    return 0;
}
