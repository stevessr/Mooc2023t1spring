#include <stdio.h>
#include <stdbool.h>

// 判断是否是指定旋转角度的结果
bool isRotation(int A[][100], int B[][100], int n, int angle) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (angle == 0 && A[i][j] != B[i][j]) return false;
            if (angle == 90 && A[i][j] != B[j][n - i - 1]) return false;
            if (angle == 180 && A[i][j] != B[n - i - 1][n - j - 1]) return false;
            if (angle == 270 && A[i][j] != B[n - j - 1][i]) return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int A[100][100], B[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    if (isRotation(A, B, n, 0)) printf("0");
    else if (isRotation(A, B, n, 90)) printf("90");
    else if (isRotation(A, B, n, 180)) printf("180");
    else if (isRotation(A, B, n, 270)) printf("270");
    else printf("-1");

    return 0;
}
