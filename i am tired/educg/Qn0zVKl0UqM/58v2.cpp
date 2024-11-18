#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Morse编码表映射
map<char, string> morseCode;
map<string, vector<string>> morseToWords;

// 将字符转化为Morse编码
void initMorseCode() {
    morseCode['A'] = ".-";
    morseCode['B'] = "-...";
    morseCode['C'] = "-.-.";
    morseCode['D'] = "-..";
    morseCode['E'] = ".";
    morseCode['F'] = "..-.";
    morseCode['G'] = "--.";
    morseCode['H'] = "....";
    morseCode['I'] = "..";
    morseCode['J'] = ".---";
    morseCode['K'] = "-.-";
    morseCode['L'] = ".-..";
    morseCode['M'] = "--";
    morseCode['N'] = "-.";
    morseCode['O'] = "---";
    morseCode['P'] = ".--.";
    morseCode['Q'] = "--.-";
    morseCode['R'] = ".-.";
    morseCode['S'] = "...";
    morseCode['T'] = "-";
    morseCode['U'] = "..-";
    morseCode['V'] = "...-";
    morseCode['W'] = ".--";
    morseCode['X'] = "-..-";
    morseCode['Y'] = "-.--";
    morseCode['Z'] = "--..";
    morseCode['0'] = "-----";
    morseCode['1'] = ".----";
    morseCode['2'] = "..---";
    morseCode['3'] = "...--";
    morseCode['4'] = "....-";
    morseCode['5'] = ".....";
    morseCode['6'] = "-....";
    morseCode['7'] = "--...";
    morseCode['8'] = "---..";
    morseCode['9'] = "----.";

    // 构建反向映射，Morse码到字母和数字
    for (auto& entry : morseCode) {
        morseToWords[entry.second].push_back(string(1, entry.first));
    }
}

// 将单词转为Morse编码
string wordToMorse(const string& word) {
    string result;
    for (char ch : word) {
        result += morseCode[ch];
    }
    return result;
}

// 处理电报的翻译
void translateMessages(ifstream& input, ofstream& output) {
    string line;
    vector<string> dictionary;

    // 读取字典表
    while (getline(input, line) && line != "*") {
        dictionary.push_back(line);
    }

    // 创建字典的Morse映射
    map<string, string> morseToWord;
    for (const string& word : dictionary) {
        string morse = wordToMorse(word);
        morseToWord[morse] = word;
    }

    // 读取电报内容
    vector<string> messages;
    while (getline(input, line) && line != "*") {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            messages.push_back(word);
        }
    }

    // 处理每个电报单词
    for (const string& morse : messages) {
        if (morseToWord.find(morse) != morseToWord.end()) {
            // 完全匹配
            output << morseToWord[morse] << endl;
        } else {
            vector<string> possibleWords;
            // 寻找前缀匹配的单词
            for (auto& entry : morseToWord) {
                if (morse.find(entry.first) == 0) {  // Morse码是前缀
                    possibleWords.push_back(entry.second);
                }
            }

            if (possibleWords.empty()) {
                output << "?" << endl;  // 没有任何匹配
            } else {
                sort(possibleWords.begin(), possibleWords.end(), [](const string& a, const string& b) {
                    if (a.length() == b.length()) {
                        return a < b;  // 字典表中出现的顺序
                    }
                    return a.length() < b.length();
                });
                output << possibleWords.front() << "!" << endl;  // 有冲突
            }
        }
    }
}

int main() {
    ifstream input("morse.in");
    ofstream output("morse.out");

    initMorseCode();
    translateMessages(input, output);

    input.close();
    output.close();
    return 0;
}
