#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    int F = (T + 1) / 2;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < (2 * i + 1); j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}