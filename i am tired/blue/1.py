from itertools import product

# 棋盘大小
N = 5
# 棋盘格子数
TOTAL_CELLS = N * N

def is_draw(board):
    # 检查是否为平局（没有任何五子连珠的情况）
    def has_five_in_a_row(b, player):
        # 检查横、竖、斜方向是否有五子连珠
        for i in range(N):
            for j in range(N):
                if all(b[i][k] == player for k in range(j, min(j + 5, N))):  # 横向
                    return True
                if all(b[k][j] == player for k in range(i, min(i + 5, N))):  # 纵向
                    return True
        # 检查斜线
        for i in range(N - 4):
            for j in range(N - 4):
                if all(b[i + k][j + k] == player for k in range(5)):  # 右下斜
                    return True
                if all(b[i + 4 - k][j + k] == player for k in range(5)):  # 左下斜
                    return True
        return False

    # 将平铺的棋局转换为二维形式
    b = [board[i * N:(i + 1) * N] for i in range(N)]
    return not (has_five_in_a_row(b, 'W') or has_five_in_a_row(b, 'B'))

# 枚举所有棋局
draw_count = 0
for board in product('WB', repeat=TOTAL_CELLS):
    if is_draw(board):
        draw_count += 1

print(draw_count)
