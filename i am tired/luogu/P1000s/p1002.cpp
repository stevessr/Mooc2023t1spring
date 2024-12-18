#include <iostream>
using namespace std;
struct pos
{
    int x, y;
};

int main()
{
    pos man, horse;
    cin >> man.x >> man.y;
    cin >> horse.x >> horse.y;
    int walkmap[25][25] = {{0}};
    int dx[] = {1, 2, -1, -2, 1, -1, 2, -2,0};
    int dy[] = {2, 1, -2, -1, -2, -2, 1, 2,0};
    for (int i = 0; i < 8; i++) {
        int nx = horse.x + dx[i];
        int ny = horse.y + dy[i];
        if (nx >= 0 && nx < 26 && ny >= 0 && ny < 26) {
            walkmap[nx][ny] = -1;
        }
    }
    walkmap[0][0] = 1;
    for (int i = 1; i < 25; i++)
    {
        if (walkmap[i][0] == -1)
        {
            walkmap[++i][0] = 0;
        }
        else
        {
            walkmap[i][0] = walkmap[i - 1][0];
        }
    }
    for (int i = 1; i < 25; i++)
    {
        if (walkmap[0][i] == -1)
        {
            walkmap[0][++i] = 0;
        }
        else
        {
            walkmap[0][i] = walkmap[0][i - 1];
        }
    };
    for (int i = 1; i <= man.x; i++)
    {
        for (int j = 1; j <= man.y; j++)
        {
            if (walkmap[i - 1][j] == -1 && walkmap[i][j - 1] == -1)
            {
                continue;
            }
            else if (walkmap[i - 1][j] == -1 || walkmap[i][j - 1] == -1)
            {
                walkmap[i][j] = walkmap[i - 1][j] + walkmap[i][j - 1] + 1;
            }
            else if (walkmap[i][j] == -1)
            {
                continue;
            }
            else
            {
                walkmap[i][j] = walkmap[i - 1][j] + walkmap[i][j - 1];
            }
        }
    }
    cout << walkmap[man.x][man.y] << endl;
    return 0;
}