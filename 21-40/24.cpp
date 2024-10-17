#include <iostream>
#include <string>
#include <algorithm>  // 用于reverse函数
using namespace std;

int main() {
    int N;
    cin >> N;

    // 记录符号，取绝对值
    bool isNegative = (N < 0);
    N = abs(N);

    // 将整数转换为字符串
    string str = to_string(N);

    // 反转字符串
    reverse(str.begin(), str.end());

    // 去掉前导零
    int result = stoi(str);

    // 如果原来的数是负数，结果也应是负数
    if (isNegative) {
        result = -result;
    }

    // 输出反转后的结果
    cout << result << endl;

    return 0;
}
