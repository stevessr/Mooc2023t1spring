#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 用于存储摩斯电码表和字典
unordered_map<char, string> morseCodeMap;  // 字母/数字 -> 摩斯电码
unordered_map<string, vector<string>> wordToMorseMap;  // 摩斯电码 -> 对应单词列表

// 函数：将字典单词转化为摩斯电码
string wordToMorse(const string& word) {
    string morse;
    for (char c : word)
        morse += morseCodeMap[c];
    return morse;
}

// 函数：从文件中读取摩斯电码表和字典
void readMorseCodeAndDictionary(ifstream& inputFile) {
    // 读取摩斯电码表
    string line;
    while (getline(inputFile, line)) {
        if (line == "*") break;  // 碰到 '*' 时结束摩斯电码表的读取
        char symbol = line[0];  // 字母或者数字
        string morse = line.substr(2);  // 对应的摩斯电码
        morseCodeMap[symbol] = morse;
    }

    // 读取字典表
    while (getline(inputFile, line)) {
        if (line == "*") break;  // 碰到 '*' 时结束字典表的读取
        string morse = wordToMorse(line);  // 将字典单词转为摩斯电码
        wordToMorseMap[morse].push_back(line);  // 将单词存入摩斯电码映射
    }
}

// 函数：从电报中翻译摩斯电码
void translateMorseMessage(ifstream& inputFile, ofstream& outputFile) {
    string morseWord;
    while (inputFile >> morseWord) {
        if (morseWord == "*") break;  // 碰到 '*' 时结束电文的读取

        // 如果有完全匹配的摩斯电码
        if (wordToMorseMap.find(morseWord) != wordToMorseMap.end()) {
            const vector<string>& candidates = wordToMorseMap[morseWord];
            if (candidates.size() == 1) {
                outputFile << candidates[0] << endl;
            } else {
                // 寻找最短的单词并输出
                string bestWord = *min_element(candidates.begin(), candidates.end(), 
                                               [](const string& a, const string& b) { return a.size() < b.size(); });
                outputFile << bestWord << "!" << endl;
            }
        } else {
            // 处理误码情况，寻找最长的前缀匹配
            string bestMatch;
            size_t bestMatchLength = 0;
            for (const auto& [morse, words] : wordToMorseMap) {
                size_t prefixLength = 0;
                while (prefixLength < morse.size() && prefixLength < morseWord.size() &&
                       morse[prefixLength] == morseWord[prefixLength]) {
                    ++prefixLength;
                }
                // 更新最长前缀
                if (prefixLength > bestMatchLength) {
                    bestMatchLength = prefixLength;
                    bestMatch = words[0];  // 使用第一个出现的单词
                }
            }
            // 输出最长前缀匹配的单词并加上"？"号
            if (!bestMatch.empty()) {
                outputFile << bestMatch << "?" << endl;
            }
        }
    }
}

int main() {
    // 打开输入和输出文件
    ifstream inputFile("morse.in");
    ofstream outputFile("morse.out");

    // 读取摩斯电码表和字典
    readMorseCodeAndDictionary(inputFile);
    
    // 翻译电报中的摩斯电码
    translateMorseMessage(inputFile, outputFile);

    return 0;
}