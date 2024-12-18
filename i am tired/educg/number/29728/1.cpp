//旋转矩阵
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;  // 输入矩阵的行数和列数
    vector<vector<int>> matrix(m, vector<int>(n));  // 原矩阵

    // 输入矩阵内容
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // 输出新矩阵的行列数
    cout << n << " " << m << endl;

    // 输出转置后的矩阵
    for (int j = 0; j < n; ++j) {
        for (int i = m-1; i >-1; --i) {
            cout << matrix[i][j];
            if (i != 0) {
                cout << " ";  // 每个元素之间用空格分隔，但最后一个元素后没有空格
            }
        }
        cout << endl;
    }

    return 0;
}
