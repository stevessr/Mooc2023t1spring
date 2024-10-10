#include <iostream>
using namespace std;

int main() {
    char a;
    cin >> a;

    // 输出字符菱形
    cout << "  " << a << endl;        // 第一行：两个空格后输出一个字符
    cout << " " << a << a << a << endl;  // 第二行：一个空格后输出三个字符
    cout << a << a << a << a << a << endl;  // 第三行：直接输出五个字符
    cout << " " << a << a << a << endl;  // 第四行：一个空格后输出三个字符
    cout << "  " << a ;        // 第五行：两个空格后输出一个字符

    return 0;
}
