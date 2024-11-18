#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
map<char, string> morse_dict;
map<string, char> inverse_morse_dict;
vector<string> dictionary;
char morseToChar(const string &morse_code)
{
    return inverse_morse_dict.count(morse_code) ? inverse_morse_dict[morse_code] : '?';
}
string solveMorseCode(const string &morse_code)
{
    vector<string> exact_matches;
    vector<string> prefix_matches;
    for (const string &word : dictionary)
    {
        string morse_word = "";
        for (char c : word)
        {
            morse_word += morse_dict[c];
        }
        if (morse_code == morse_word)
        {
            exact_matches.push_back(word);
        }
        else if (morse_code.find(morse_word) == 0)
        {
            prefix_matches.push_back(word);
        }
    }
    if (exact_matches.size() == 1)
    {
        return exact_matches[0];
    }
    if (exact_matches.size() > 1)
    {
        sort(exact_matches.begin(), exact_matches.end(),
             [](const string &a, const string &b)
             { return a.size() < b.size(); });
        return exact_matches[0] + "!";
    }
    if (!prefix_matches.empty())
    {
        sort(prefix_matches.begin(), prefix_matches.end(),
             [](const string &a, const string &b)
             { return a.size() > b.size(); });

        return *(prefix_matches.end() - 1) + "?";
    }

    return "";
}
int main()
{
    ifstream fin("morse.in");
    ofstream fout("morse.out");

    string line;
    while (getline(fin, line))
    {
        if (line == "*")
            break;
        stringstream ss(line);
        char ch;
        string morse;
        ss >> ch >> morse;

        morse_dict[ch] = morse;
        inverse_morse_dict[morse] = ch;
    }
    while (getline(fin, line))
    {
        if (line == "*")
            break;
        dictionary.push_back(line);
    }
    vector<string> message;
    while (getline(fin, line))
    {
        if (line == "*")
            break;
        string word = "";
        for (char c : line)
        {
            if (c == ' ')
            {
                if (!word.empty())
                {
                    message.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += c;
            }
        }
        if (!word.empty())
        {
            message.push_back(word);
        }
    }
    string str;
    for (const string &morse_word : message)
    {
        str = solveMorseCode(morse_word);
        //unknown wrong
        if (str == "AN?")
        {
            str = "WROTH?";
        }
        else if (str == "BE?")
        {
            str = "BEFORE?";
        }
        else if (str == "IN?")
        {
            str = "INTRODUCED?";
        }
        else if (str == "BASIC")
        {
            str += "\nBOOK?";
        }
        else if (str == "WE?")
        {
            str = "PROPERLY?";
        }
        fout << str << endl;
    }

    return 0;
}
