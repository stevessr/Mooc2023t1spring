#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
const int N = 19;
const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
bool check_victory(queue<pair<int, int>>& q, int color, map<pair<int, int>, int>& board) {
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
            int count = 1; 
            int nx = x + dx, ny = y + dy;
            while (nx >= 0 && nx < N && ny >= 0 && ny < N && board[{nx, ny}] == color) {
                count++;
                nx += dx;
                ny += dy;
            }
            bool has_empty_end1 = (nx >= 0 && nx < N && ny >= 0 && ny < N && board[{nx, ny}] == 0);
            nx = x - dx, ny = y - dy;
            while (nx >= 0 && nx < N && ny >= 0 && ny < N && board[{nx, ny}] == color) {
                count++;
                nx -= dx;
                ny -= dy;
            }
            bool has_empty_end2 = (nx >= 0 && nx < N && ny >= 0 && ny < N && board[{nx, ny}] == 0);
            if (count == 4 && (has_empty_end1 || has_empty_end2)) {
                cout << color << ": " << x + 1 << "," << y + 1 << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    queue<pair<int, int>> q1, q2;
    map<pair<int, int>, int> board; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                q1.push({i, j});
                board[{i, j}] = 1;
            } else if (temp == 2) {
                q2.push({i, j});
                board[{i, j}] = 2;
            }
        }
    }
    if (check_victory(q1, 1, board)) return 0;
    if (check_victory(q2, 2, board)) return 0;
    cout << "No" << endl;
    return 0;
}
