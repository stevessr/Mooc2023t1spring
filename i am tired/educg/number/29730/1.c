// 1. 求公式近似值2
#include <stdio.h>
#include <math.h>

double diedai(int x, double y, int times)
{
    if (times == 0)
    {
        return y;
    }
    return diedai(x, y * 2 / 3 + x / (3 * y * y), times - 1);
}
int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    if (x == 0)
    {
        printf("%lf", 0.0);
        return 0;
    }
    else if (x == 1)
    {
        printf("%lf", 1.0);
        return 0;
    }
    double xL = x * 1.0;
    double y = diedai(x, xL, n);
    //printf("%d %d\n", x, n);
    printf("%lf", y);
    return 0;
}