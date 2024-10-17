#include <iostream>
#include <cmath> // 引入用于四舍五入的头文件
using std::cout, std::endl, std::cin;

int main()
{
    short x, y;
    cin >> x >> y;
    short value[x][y];

    // 读取输入的图像像素值
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> value[i][j];
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << value[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
