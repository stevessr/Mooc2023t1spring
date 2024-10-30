#include <iostream>
using std::cout, std::endl, std::cin, std::string;

int main() {
    string a;
    cin >> a;
    int c = a.length(), d[26] = {0};
    
    // 统计每个字母出现的次数
    for (int i = 0; i < c; i++) {
        d[a[i] - 'a']++;
    }
    
    // 找到第一个仅出现一次的字符
    for (int i = 0; i < c; i++) {
        if (d[a[i] - 'a'] == 1) {
            cout << a[i];
            return 0;
        }
    }
    
    // 如果没有找到仅出现一次的字符
    cout << "no";
    return 0;
}