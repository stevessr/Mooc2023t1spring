#include <iostream>
using namespace std;

struct pos {
    int x, y;
};

int main() {
    pos man, horse;
    cin >> man.x >> man.y;
    cin >> horse.x >> horse.y;

    // 棋盘大小，假设 25x25
    const int SIZE = 25;
    int walkmap[SIZE][SIZE] = {0};

    // 标记马的位置和威胁区域，确保不越界
    walkmap[horse.x][horse.y] = -1;



    // 初始化起点
    if (walkmap[0][0] == -1) {
        cout << 0 << endl;
        return 0;
    }
    walkmap[0][0] = 1;

    // 初始化第一列
    for (int i = 1; i < SIZE; i++) {
        if (walkmap[i][0] == -1) {
            break; // 后续位置都不可达
        }
        walkmap[i][0] = walkmap[i - 1][0];
    }

    // 初始化第一行
    for (int j = 1; j < SIZE; j++) {
        if (walkmap[0][j] == -1) {
            break; // 后续位置都不可达
        }
        walkmap[0][j] = walkmap[0][j - 1];
    }

    // 动态规划计算路径数
    for (int i = 1; i <= man.x; i++) {
        for (int j = 1; j <= man.y; j++) {
            if (walkmap[i][j] == -1) {
                continue; // 马的位置或威胁区域
            }
            if (walkmap[i - 1][j] != -1) {
                walkmap[i][j] += walkmap[i - 1][j];
            }
            if (walkmap[i][j - 1] != -1) {
                walkmap[i][j] += walkmap[i][j - 1];
            }
        }
    }

    // 输出结果
    cout << walkmap[man.x][man.y] << endl;

    return 0;
}
