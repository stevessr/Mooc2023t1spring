#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
struct Position {
    int line;
    int column;
    bool operator<(const Position& other) const {
        if (line != other.line)
            return line < other.line;
        return column < other.column;
    }
};
std::string to_lowercase(const std::string& str) {
    return str;
    std::string lower;
    lower.reserve(str.size());
    for(char c : str){
        lower += std::tolower(c);
    }
    return lower;
}

int main() {
    // 定义需要排除的单词，使用小写形式便于后续比较
    std::unordered_map<std::string, bool> exclusion_set = {
        {"a", true},
        {"an", true},
        {"the", true},
        {"and", true}
    };
    std::unordered_map<std::string, std::vector<Position>> word_map;

    // 打开输入文件
    std::ifstream infile("crossin.txt");
    if (!infile.is_open()) {
        std::cerr << "无法打开输入文件 crossin.txt" << std::endl;
        return 1;
    }

    std::string line;
    int line_num = 0;
    while (std::getline(infile, line)) {
        line_num++;
        int i = 0;
        int len = line.length();
        while (i < len) {
            // 如果当前字符是字母
            if (std::isalpha(line[i])) {
                int start = i;
                // 检查单词长度不超过100
                int word_length = 1;
                i++;
                while (i < len && (std::isalpha(line[i]) || line[i] == '-') && word_length < 100) {
                    word_length++;
                    i++;
                }
                // 提取单词
                std::string word = line.substr(start, word_length);
                // 检查是否以连字符开头（已由正则判断以字母开头）
                // 过滤包含其他字符的单词（已由条件过滤）
                // 排除单词
                std::string word_lower = to_lowercase(word);
                if (exclusion_set.find(word_lower) == exclusion_set.end()) {
                    // 记录位置（列号从1开始）
                    int column_num = start + 1;
                    word_map[word].push_back(Position{line_num, column_num});
                }
            }
            else {
                i++;
            }
        }
    }

    infile.close();

    // 分离以大写字母和小写字母开头的单词
    std::vector<std::string> uppercase_words;
    std::vector<std::string> lowercase_words;

    for (const auto& pair : word_map) {
        const std::string& word = pair.first;
        if (!word.empty()) {
            if (std::isupper(word[0]))
                uppercase_words.push_back(word);
            else if (std::islower(word[0]))
                lowercase_words.push_back(word);
        }
    }

    // 排序单词
    std::sort(uppercase_words.begin(), uppercase_words.end());
    std::sort(lowercase_words.begin(), lowercase_words.end());

    // 合并排序后的单词列表
    std::vector<std::string> sorted_words;
    sorted_words.reserve(uppercase_words.size() + lowercase_words.size());
    for (const auto& word : uppercase_words)
        sorted_words.push_back(word);
    for (const auto& word : lowercase_words)
        sorted_words.push_back(word);

    // 打开输出文件
    std::ofstream outfile("crossout.txt");
    if (!outfile.is_open()) {
        std::cerr << "无法打开输出文件 crossout.txt" << std::endl;
        return 1;
    }

    // 写入输出文件
    for (const auto& word : sorted_words) {
        const std::vector<Position>& positions = word_map[word];
        // 排序位置
        std::vector<Position> sorted_positions = positions;
        std::sort(sorted_positions.begin(), sorted_positions.end());

        // 构造位置字符串
        std::string pos_str;
        for (size_t i = 0; i < sorted_positions.size(); ++i) {
            pos_str += "(" + std::to_string(sorted_positions[i].line) + "," + std::to_string(sorted_positions[i].column) + ")";
            if (i != sorted_positions.size() - 1)
                pos_str += ",";
        }

        // 写入格式：word:(line1,colm1),(line2,colm2),...
        outfile << word << ":" << pos_str << "\n";
    }

    outfile.close();

    return 0;
}
