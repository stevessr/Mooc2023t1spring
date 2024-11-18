#include <stdio.h>
#include <stdbool.h>
#define Map_MAX 1000
int map[Map_MAX][Map_MAX][2] = {0}, T;
bool up(int i, int j) {
    while (map[i][j][0] != 1) {
        i--;
        if (i < 0) {
            return false;
        }
    }
    return true;
}
bool down(int i, int j) {
    while (map[i][j][0] != 1) {
        i++;
        if (i == T) {
            return false;
        }
    }
    return true;
}
bool left(int i, int j) {
    while (map[i][j][0] != 1) {
        j--;
        if (j < 0) {
            return false;
        }
    }
    return true;
}
bool right(int i, int j) {
    while (map[i][j][0] != 1) {
        j++;
        if (j == T) {
            return false;
        }
    }
    return true;
}

int main() {
    int total0=0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            scanf("%d", &map[i][j][0]);
            if (map[i][j][0] == 1) {
                map[i][j][1] = 2; 
            }else if(map[i][j][0] == 0){
                total0++;
            }
        }
    }
    for (int i = 1; i < T - 1; i++) {
        for (int j = 1; j < T - 1; j++) {
            if (up(i, j) && down(i, j) && left(i, j) && right(i, j)) {
                map[i][j][1] = 1;
            }
        }
    }
    int temp = 0;
    for (int i = 1; i < T - 1; i++) {
        for (int j = 1; j < T - 1; j++) {
            if (map[i][j][1] == 1 &&map[i+1][j][1] != 0 && map[i-1][j][1] != 0 && map[i][j+1][1] != 0 && map[i][j-1][1] != 0) {
                temp++;
            }
        }
    }
    printf("%d\n", total0-temp);
    return 0;
}
