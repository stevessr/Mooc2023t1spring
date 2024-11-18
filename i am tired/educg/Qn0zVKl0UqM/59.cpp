#include <iostream>
#include <string>

void escape(std::string &s, const std::string &t) {
    for (char ch : t) {
        if (ch == '\n') {
            s += "\\n";  // 将换行符转换为"\\n"
        } else if (ch == '\t') {
            s += "\\t";  // 将制表符转换为"\\t"
        } else {
            s += ch;  // 其他字符直接复制
        }
    }
}

int main() {
    std::string t;
    // 使用 std::getline 获取输入，确保读取包含空格的整行输入
    std::getline(std::cin, t, '\0');  // 读取整个输入，包括换行符
    
    std::string s;
    escape(s, t);  // 调用 escape 函数进行转换
    s=s.substr(0,s.size()-2);
    
    std::cout << s << std::endl;  // 输出转换后的字符串
    return 0;
}
