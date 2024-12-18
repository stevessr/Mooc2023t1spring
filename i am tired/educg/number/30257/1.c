// 矩阵操作
#include <stdio.h>
#include <stdbool.h>
int main()
{
    int N, temp, sum = 0, max = 0, min = 0;
    scanf("%d", &N);
    int matrix[N][N];
    bool first = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &temp);
            matrix[i][j] = temp;
            sum += temp;
            if (first)
            {
                first = false;
                max = min = temp;
            }
            else
            {
                if (temp > max)
                {
                    max = temp;
                }
                if (temp < min)
                {
                    min = temp;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || j == 0 || i == (N - 1) || j == (N - 1))
            {
                printf("%5d", min);
            }
            else if (i >= (N - 3) / 2 && i <= (N + 1) / 2 && j >= (N - 3) / 2 && j <= (N + 1) / 2)
            {
                if (i == (N - 1) / 2 && j == (N - 1) / 2)
                {
                    printf("%5d", max);
                }
                else
                {
                    printf("%5d", sum);
                }
            }
            else
            {
                printf("%5d", min);
            }
        }
        printf("\n");
    }
    return 0;
}