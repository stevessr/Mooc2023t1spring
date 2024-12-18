#include <iostream>
#include <vector>
using namespace std;

const int N = 5; // 棋盘大小
int drawCount = 0; // 平局计数

// 检查是否有五子连珠
bool hasFiveInARow(vector<vector<char>>& board, char player) {
    // 检查横向和纵向
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j <= N - 5) { // 横向
                bool win = true;
                for (int k = 0; k < 5; ++k)
                    if (board[i][j + k] != player) {
                        win = false;
                        break;
                    }
                if (win) return true;
            }
            if (i <= N - 5) { // 纵向
                bool win = true;
                for (int k = 0; k < 5; ++k)
                    if (board[i + k][j] != player) {
                        win = false;
                        break;
                    }
                if (win) return true;
            }
        }
    }
    // 检查斜线
    for (int i = 0; i <= N - 5; ++i) {
        for (int j = 0; j <= N - 5; ++j) {
            // 右下斜
            bool win = true;
            for (int k = 0; k < 5; ++k)
                if (board[i + k][j + k] != player) {
                    win = false;
                    break;
                }
            if (win) return true;

            // 左下斜
            win = true;
            for (int k = 0; k < 5; ++k)
                if (board[i + 4 - k][j + k] != player) {
                    win = false;
                    break;
                }
            if (win) return true;
        }
    }
    return false;
}

// 回溯递归模拟棋局
void simulateGame(vector<vector<char>>& board, int step, bool whiteTurn) {
    if (step == N * N) { // 棋盘填满
        if (!hasFiveInARow(board, 'W') && !hasFiveInARow(board, 'B'))
            ++drawCount; // 平局
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == '.') { // 空格可落子
                board[i][j] = whiteTurn ? 'W' : 'B';
                // 剪枝：若当前局面已分胜负，则跳过
                if (!hasFiveInARow(board, whiteTurn ? 'W' : 'B'))
                    simulateGame(board, step + 1, !whiteTurn);
                board[i][j] = '.'; // 回溯
            }
        }
    }
}

int main() {
    vector<vector<char>> board(N, vector<char>(N, '.')); // 初始化棋盘
    simulateGame(board, 0, true); // 白棋先手
    cout << drawCount << endl; // 输出平局总数
    return 0;
}
