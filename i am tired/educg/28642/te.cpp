#include <iostream>
using namespace std;
#define N 1000
int main()

{
    int m, k, i, j, n, x[N];
    cin >> m >> k;
    n = 0;                      // 数组下标
    for (i = m + 1; n < k; i++) // 对范围内的数进行循环
    {
        for (j = 2; j <= i; j++) // 判断是否素数
            if (i % j == 0)
                break;
        if (j == i)
            x[n++] = i; // 存入数组
    }

    for (i = 0; i < n; i++)
        cout << x[i] << ",";
    return 0;
}