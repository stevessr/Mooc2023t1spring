#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    // 动态分配二维数组
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // 输入矩阵元素
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 输出旋转后的矩阵维度
    printf("%d %d\n", n, m);

    // 输出旋转后的矩阵
    for (int j = 0; j < n; j++)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 释放动态分配的内存
    for (int i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
