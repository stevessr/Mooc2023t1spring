#include <iostream>
#include <fstream>
#include <string>

void encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key) {
    if (key.empty()) {
        std::cout << "密钥为空，未加密文件。" << std::endl;
        return;
    }
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "无法打开输入文件 " << inputFile << std::endl;
        return;
    }
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "无法打开输出文件 " << outputFile << std::endl;
        inFile.close();
        return;
    }
    char ch;
    int keyLen = key.length();
    int i = 0;
    while (inFile.get(ch)) {
        char encryptedChar = ch ^ key[i % keyLen];
        outFile.put(char(encryptedChar));
        i++;
    }
    inFile.close();
    outFile.close();
    std::cout << "文件已加密并输出到 " << outputFile << std::endl;
}

int main() {
    std::string key;
    std::cout << "请输入密钥：";
    std::getline(std::cin, key);
    encryptFile("1txt", "2txt", key);

    return 0;
}
