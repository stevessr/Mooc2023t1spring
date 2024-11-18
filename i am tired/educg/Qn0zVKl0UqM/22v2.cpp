#include <iostream>
#include <set>
#include <vector>
using namespace std;

class point {
public:
    int x, y, value;

    point(int xin, int yin, int valuein) : x(xin), y(yin), value(valuein) {}

    bool operator<(const point &po) const {
        return (x < po.x) || (x == po.x && y < po.y);
    }

    void print() const {
        cout << value << " " << x + 1 << " " << y + 1 << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int group[10][10];

    // Read the 2D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> group[i][j];
        }
    }

    set<point> max_points;

    // Find row max points
    for (int i = 0; i < n; i++) {
        int row_max = group[i][0];
        for (int j = 1; j < m; j++) {
            if (group[i][j] > row_max) {
                row_max = group[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            if (group[i][j] == row_max) {
                max_points.insert(point(i, j, row_max));
            }
        }
    }

    // Find column max points and check if they are in row max points
    set<point> result;
    for (int j = 0; j < m; j++) {
        int col_max = group[0][j];
        for (int i = 1; i < n; i++) {
            if (group[i][j] > col_max) {
                col_max = group[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            point p(i, j, col_max);
            if (group[i][j] == col_max && max_points.count(p)) {
                result.insert(p);
            }
        }
    }

    // Output all maximum points in sorted order
    for (const auto &p : result) {
        p.print();
    }

    return 0;
}
