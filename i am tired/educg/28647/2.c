#include <stdio.h>
#include <math.h>
#include <stdio.h>

// 判断是否是回文数的函数
int loop(int x)
{
    int original = x, reversed = 0, remainder;
    while (x != 0)
    {
        remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }
    if (original == reversed)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (loop(i) && i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
