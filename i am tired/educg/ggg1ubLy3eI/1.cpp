#include <iostream>
#include <iomanip>  // 用于设置输出精度

using namespace std;

int main() {
    int x, y, z;
    
    // 从键盘输入三个整数
    cin >> x >> y >> z;
    
    // 计算三个数的和
    int sum = x + y + z;
    
    // 计算三个数的平均值
    double average = sum / 3.0;
    
    // 输出三个数的和
    cout << sum << endl;
    
    // 设置浮点数输出精度，并输出平均值
    cout << fixed << setprecision(2) << average << endl;
    
    return 0;
}
