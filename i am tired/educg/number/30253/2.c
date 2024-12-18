// 时钟指针
#include <stdio.h>
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
    printf("%.3ld", differ);
    return 0;
}