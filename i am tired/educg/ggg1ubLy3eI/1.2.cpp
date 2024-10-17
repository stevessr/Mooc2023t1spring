#include <iostream>
#include <iomanip>  // 用于设置输出精度
#pragma GCC optimize(3)
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 关闭 C++ 流与 C 流的同步，提高性能
    cin.tie(0);                   // 解开 cin 与 cout 的绑定，提高性能

    long x, y, z;
    
    // 从键盘输入三个整数
    cin >> x >> y >> z;
    
    // 计算三个数的和
    long sum = x + y + z;
    
    // 计算三个数的平均值
    // 将 sum 转换为浮点数后再做除法，避免整除问题
    double average = sum / 3.0;
    
    // 输出三个数的和
    cout << sum << '\n';
    
    // 设置浮点数输出精度，并输出平均值
    cout << fixed << setprecision(2) << average << '\n';
    
    return 0;
}
