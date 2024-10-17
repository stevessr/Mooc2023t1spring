#include <iostream>
#include <cmath>  // 引入用于四舍五入的头文件
using std::cout, std::endl, std::cin;

int main(){
    short x, y;
    cin >> x >> y;
    short value[x][y];

    // 读取输入的图像像素值
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> value[i][j];
        }
    }

    // 进行模糊化处理
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (i == 0 || j == 0 || i == x - 1 || j == y - 1) {
                // 四周边界像素不变
                cout << value[i][j] << " ";
            } else {
                // 中间像素取周围上下左右5个点的平均值并四舍五入
                int sum = value[i][j] + value[i-1][j] + value[i+1][j] + value[i][j-1] + value[i][j+1];
                cout << round(sum / 5.0) << " ";  // 四舍五入
            }
        }
        cout << endl;
    }

    return 0;
}
