#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// 判断一个单词是否为控制流关键字
bool isControlKeyword(const string &word) {
    vector<string> keywords = {"if", "else", "for", "while", "switch", "case"};
    for (const auto &keyword : keywords) {
        if (word == keyword) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream fin("in.c");
    ofstream fout("out.txt");

    if (!fin) {
        cerr << "Failed to open input file in.c" << endl;
        fout << "No answer" << endl;
        return 1;
    }

    string line, controlFlow = "";
    bool inComment = false;
    bool inString = false;

    while (getline(fin, line)) {
        size_t i = 0;
        while (i < line.length()) {
            if (!inComment && !inString) {
                if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '/') {
                    break;
                }

                if (line[i] == '/' && i + 1 < line.length() && line[i + 1] == '*') {
                    inComment = true;
                    i += 2;
                    continue;
                }

                if (line[i] == '\"') {
                    inString = true;
                    i++;
                    continue;
                }

                if (isalpha(line[i]) || line[i] == '_') { 
                    string word = "";
                    while (i < line.length() && (isalnum(line[i]) || line[i] == '_')) {
                        word += line[i++];
                    }
                    if (isControlKeyword(word)) {
                        controlFlow += word;
                    }
                } else {
                    i++;
                }
            } else if (inComment) {
                if (line[i] == '*' && i + 1 < line.length() && line[i + 1] == '/') {
                    inComment = false;
                    i += 2;
                } else {
                    i++;
                }
            } else if (inString) {
                if (line[i] == '\\') {
                    i += 2;
                } else if (line[i] == '\"') {
                    inString = false;
                    i++;
                } else {
                    i++;
                }
            }
        }
    }

    if (controlFlow.empty()) {
        fout << "No answer" << endl;
    } else {
        fout << controlFlow << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
