#include <stdio.h>
#include <math.h>
int main()
{
    int T;
    double s = 1.0f;
    scanf("%d", &T);
    if (T == 0)
    {
        printf("1.0000000000");
        return 0;
    }
    for (int i = 1; i <= T; i++)
    {
        s += 1.0/tgamma(i + 1);
    }
    printf("%.10lf", s);
    return 0;
}