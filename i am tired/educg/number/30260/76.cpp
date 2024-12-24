#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;
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

int main()
{
    string inputPattern, line;
    ifstream fin("string.in");
    cout << "Enter the pattern: ";
    // getline(cin, inputPattern);
    inputPattern = "w*d";
    // cout << "Enter the text (end with EOF):\n";

    vector<string> lines;
    while (getline(fin, line))
    {
        lines.push_back(line);
    }
    string regexPattern = preprocessPattern(inputPattern);
    regex re(regexPattern, regex::icase);

    ofstream outFile("string.out");

    for (size_t i = 0; i < lines.size(); ++i)
    {
        smatch match, last;
        string currentLine = lines[i];
        string temper;
        vector<string> matches;
        auto searchStart = currentLine.cbegin();
        while (regex_search(searchStart, currentLine.cend(), match, re))
        {
            temper = match.str();
            matches.push_back(temper);
            last = match;
            searchStart = match.prefix().second + 1;
            // if (regex_search(searchStart, currentLine.cend(), match, re) && match == last)
            {
                // searchStart = match.prefix().second + 1;
            }
        }

        string temp = "";
        if (!matches.empty())
        {
            /*sort(matches.begin(), matches.end(), [](const string &a, const string &b)
                 { return a.size() < b.size(); });*/
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
            temp = "";
        }
    }

    outFile.close();
    return 0;
}
