#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

// 将字符串转换为小写
std::string toLower(const std::string& str) {
    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

// 删除字符串中的指定子串，大小写不敏感
void removeSubstring(std::string& line, const std::string& sub) {
    std::string lineLower = toLower(line);
    std::string subLower = toLower(sub);

    size_t pos = 0;
    while ((pos = lineLower.find(subLower, pos)) != std::string::npos) {
        line.erase(pos, sub.length()); // 删除该位置的子串
        lineLower = toLower(line);    // 更新lineLower
    }
}

int main() {
    // 1. 读取要删除的字符串
    std::string delete_str;
    std::cin >> delete_str;

    // 2. 打开输入文件
    std::ifstream infile("filein.txt");
    if (!infile.is_open()) {
        std::cerr << "无法打开输入文件 filein.txt" << std::endl;
        return 1;
    }

    // 3. 打开输出文件
    std::ofstream outfile("fileout.txt");
    if (!outfile.is_open()) {
        std::cerr << "无法打开输出文件 fileout.txt" << std::endl;
        return 1;
    }

    // 4. 逐行处理文件内容
    std::string line;
    while (std::getline(infile, line)) {
        // 删除指定子串
        removeSubstring(line, delete_str);
        // 将处理后的行写入输出文件
        outfile << line << std::endl;
    }

    // 5. 关闭文件
    infile.close();
    outfile.close();

    std::cout << "处理完成，结果已保存到 fileout.txt" << std::endl;

    return 0;
}
