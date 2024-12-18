#include <stdio.h>
#include <stdbool.h>

#define MAX 9

int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {-1, 1, 0, 0};

void dfs(int area[MAX][MAX], bool visited[MAX][MAX], int x, int y, int T) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < T && ny >= 0 && ny < T && area[nx][ny] == 0 && !visited[nx][ny]) {
            dfs(area, visited, nx, ny, T);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T); 
    int area[MAX][MAX];
    bool visited[MAX][MAX] = {false};
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            scanf("%d", &area[i][j]);
        }
    }
    for (int i = 0; i < T; i++) {
        if (area[i][0] == 0 && !visited[i][0]) dfs(area, visited, i, 0, T);
        if (area[i][T-1] == 0 && !visited[i][T-1]) dfs(area, visited, i, T-1, T);
        if (area[0][i] == 0 && !visited[0][i]) dfs(area, visited, 0, i, T);
        if (area[T-1][i] == 0 && !visited[T-1][i]) dfs(area, visited, T-1, i, T);
    }
    int island_area = 0;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (area[i][j] == 0 && !visited[i][j]) {
                island_area++;
            }
        }
    }

    printf("%d\n", island_area); 
    return 0;
}
