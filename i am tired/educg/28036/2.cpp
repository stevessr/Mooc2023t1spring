#include <iostream>
using namespace std;

// 判断是否为直角三角形、普通三角形或无法构成三角形
short vaild(long double max, long double s1, long double s2) {
    if (max >= s1 + s2) {
        return -1; // 无法构成三角形
    } else if (max * max == s1 * s1 + s2 * s2) {
        return 1; // 直角三角形
    } else {
        return 0; // 普通三角形
    }
}

int main() {
    long double a, b, c;
    cin >> a >> b >> c;

    // 检测三条边中最大的一边并调用 vaild 判断
    if (a >= b && a >= c) {
        cout << vaild(a, b, c);
    } else if (b >= a && b >= c) {
        cout << vaild(b, a, c);
    } else {
        cout << vaild(c, a, b);
    }

    return 0;
}
