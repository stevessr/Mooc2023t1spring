#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// Morse编码字典，字母和数字到Morse码的映射
map<char, string> morse_dict;
map<string, char> inverse_morse_dict;

// 字典表
vector<string> dictionary;

// 根据Morse码返回对应的字符
char morseToChar(const string& morse_code) {
    return inverse_morse_dict.count(morse_code) ? inverse_morse_dict[morse_code] : '?';
}

// 根据字典查找最佳匹配的单词
string solveMorseCode(const string& morse_code) {
    vector<string> exact_matches;
    vector<string> prefix_matches;
    
    // 尝试匹配字典中的每个单词
    for (const string& word : dictionary) {
        string morse_word = "";
        for (char c : word) {
            morse_word += morse_dict[c];
        }
        
        // 如果完全匹配
        if (morse_code == morse_word) {
            exact_matches.push_back(word);
        }
        // 如果是前缀匹配
        else if (morse_code.find(morse_word) == 0) {
            prefix_matches.push_back(word);
        }
    }

    // 如果有精确匹配
    if (exact_matches.size() == 1) {
        return exact_matches[0];
    }

    // 多个匹配，选择最短的单词并加上!
    if (exact_matches.size() > 1) {
        sort(exact_matches.begin(), exact_matches.end(),
            [](const string& a, const string& b) { return a.size() < b.size(); });
        return exact_matches[0] + "!";
    }

    // 如果没有精确匹配但有前缀匹配，选择最长前缀匹配并加上?
    if (!prefix_matches.empty()) {
        sort(prefix_matches.begin(), prefix_matches.end(),
            [](const string& a, const string& b) { return a.size() > b.size(); });
        return prefix_matches[0] + "?";
    }

    // 未找到任何匹配，返回空字符串
    return "";
}

int main() {
    ifstream fin("morse.in");
    ofstream fout("morse.out");

    string line;
    
    // 1. 读取Morse编码表
    while (getline(fin, line)) {
        if (line == "*") break;
        
        // 读取每个字母和对应的Morse编码
        stringstream ss(line);
        char ch;
        string morse;
        ss >> ch >> morse;

        morse_dict[ch] = morse;
        inverse_morse_dict[morse] = ch;
    }

    // 2. 读取字典表
    while (getline(fin, line)) {
        if (line == "*") break;
        dictionary.push_back(line);
    }

    // 3. 读取电报内容
    vector<string> message;
    while (getline(fin, line)) {
        if (line == "*") break;
        
        // 拆分单词
        string word = "";
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    message.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {
            message.push_back(word);
        }
    }

    // 4. 解码每个Morse单词
    for (const string& morse_word : message) {
        string result = solveMorseCode(morse_word);
        if (!result.empty()) {
            fout << result << endl;
        }
    }

    return 0;
}
