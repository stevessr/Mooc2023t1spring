#include <stdio.h>
#include <math.h>
long fac(int n);
int main()
{
    int t;
    scanf("%d", &t);
    printf("%ld", fac(t));
    return 0;
}
long fac(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fac(n - 1);
}