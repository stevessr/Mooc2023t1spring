#include <stdio.h>
#include <stdbool.h>
#define Map_MAX 1000

int map[Map_MAX][Map_MAX][2] = {0}, T;

int main(){
    // 读取方阵大小
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            scanf("%d", &map[i][j][0]);
            if (map[i][j][0] == 1) {
                map[i][j][1] = 2; // 标记边界
            }
        }
    }

}