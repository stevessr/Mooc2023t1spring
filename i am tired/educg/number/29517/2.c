//求最小点
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);  // 输入行数和列数

    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);  // 输入数组元素
        }
    }

    // 遍历每个元素，判断是否为最小点
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isRowMin = 1;  // 假设是所在行的最小值
            int isColMin = 1;  // 假设是所在列的最小值

            // 检查是否是所在行的最小值
            for (int k = 0; k < n; k++) {
                if (a[i][k] < a[i][j]) {
                    isRowMin = 0;  // 如果发现更小的值，则不是行最小
                    break;
                }
            }

            // 检查是否是所在列的最小值
            for (int k = 0; k < m; k++) {
                if (a[k][j] < a[i][j]) {
                    isColMin = 0;  // 如果发现更小的值，则不是列最小
                    break;
                }
            }

            // 如果是最小点，输出其值和位置
            if (isRowMin && isColMin) {
                printf("%d %d %d\n", a[i][j], i + 1, j + 1);
            }
        }
    }

    return 0;
}