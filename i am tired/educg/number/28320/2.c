#include <stdio.h>
#include <math.h>
int main()
{
    int num, T = 0, temp;
    scanf("%d", &num);
    temp = num;
    while (temp / 1000)
    {
        if (temp / 1000)
        {
            T++;
        }
        temp /= 1000;
    }
    printf("%d", temp);
    while (T--)
    {
        temp = num;
        for (int i = 0; i < T; i++)
        {
            temp /= 1000;
        }
        printf(",%d", temp % 1000);
    }
    return 0;
}