#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

class point
{
public:
    int x, y, value;

    // 构造函数
    point() {}
    point(int xin, int yin, int valuein) : x(xin), y(yin), value(valuein) {}

    // 重载 < 运算符
    bool operator<(const point &po) const {
        return (x < po.x) || (x == po.x && y < po.y);
    }

    // 打印函数
    void print() const {
        cout << value << " " << x + 1 << " " << y + 1 << endl;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int group[10][10];

    // 输入二维数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> group[i][j];
        }
    }

    set<point> pset1, pset2;

    // 找到每行的最大值点
    for (int i = 0; i < n; i++) {
        point tempp(i, 0, group[i][0]);
        for (int j = 1; j < m; j++) {
            if (tempp.value < group[i][j]) {
                tempp = point(i, j, group[i][j]);
            }
        }
        pset1.insert(tempp);
    }

    // 找到每列的最大值点
    for (int j = 0; j < m; j++) {
        point tempp(0, j, group[0][j]);
        for (int i = 1; i < n; i++) {
            if (tempp.value < group[i][j]) {
                tempp = point(i, j, group[i][j]);
            }
        }
        pset2.insert(tempp);
    }

    // 合并两个集合，得到同时满足行和列最大值的点
    vector<point> mix;
    set_intersection(pset1.begin(), pset1.end(), pset2.begin(), pset2.end(), back_inserter(mix));

    // 按要求输出
    for (const auto &p : mix) {
        p.print();
    }

    return 0;
}
