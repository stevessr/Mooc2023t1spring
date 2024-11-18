#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string searchStr;
    std::cout << "请输入待查找的字符串：";
    std::cin >> searchStr;

    std::ifstream inputFile("filein.txt"); // 输入文件
    if (!inputFile.is_open()) {
        std::cerr << "无法打开输入文件filein.txt！" << std::endl;
        return 1;
    }

    std::ofstream outputFile("fileout.txt"); // 输出文件
    if (!outputFile.is_open()) {
        std::cerr << "无法创建输出文件fileout.txt！" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(searchStr, pos)) != std::string::npos) {
            line.insert(pos, "\"");
            pos += searchStr.length() + 1;
            line.insert(pos, "\"");
            pos++;
        }
        outputFile << line << '\n'; 
    }

    std::cout << "操作完成！结果已保存到fileout.txt。" << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
