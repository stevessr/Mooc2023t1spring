#include <iostream>
#include <vector>
using namespace std;
struct pos
{
    int x, y;
};

int main()
{
    int A[9][9] = {0}, B[9][9] = {0}, R[9][9] = {0};
    int SPsize = 0;
    {
        int T;
        cin >> T;
        int column, row, value;
        while (T--)
        {
            cin >> column >> row >> value;
            A[column][row] = value;
            if (SPsize < max(row, column))
            {
                SPsize = max(row, column);
            }
        } // 生成完整的A矩阵
        cin >> T;
        while (T--)
        {
            cin >> column >> row >> value;
            B[column][row] = value;
            if (SPsize < max(row, column))
            {
                SPsize = max(row, column);
            }
        } // 生成完整的B矩阵
    }
    vector<pos> S;
    for (int i = 0; i <= SPsize; i++)
    {
        for (int j = 0; j <= SPsize; j++)
        {
            R[i][j] = 0;
            for (int k = 0; k <= SPsize; k++)
            {
                if (A[i][k] && B[k][j])
                {
                    R[i][j] += A[i][k] * B[k][j];
                }
            }
            if (R[i][j])
            {
                S.push_back({i, j});
            }
        }
    }
    for (auto &i : S)
    {
        cout << i.x << " " << i.y << " " << R[i.x][i.y] << endl;
    }

    return 0;
}