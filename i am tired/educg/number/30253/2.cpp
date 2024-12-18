// 时钟指针
#include <cmath>
// #include <algorithm>
#include <iostream>
#include <cstdio>
#include <iomanip>
int main()
{
    int m, n;
    scanf("%d:%d", &m, &n);
    double differ = m * 30 - n * 6 + n / 60.0 * 30;
    if (differ < 0)
    {
        differ = -differ;
    }
    while (differ > 180)
    {
        differ = 360 - differ;
    }
    if (differ < 0)
    {
        differ = -differ;
    }
    std::cout << std::fixed << std::setprecision(3) << differ;
    return 0;
}