#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct Point
{
    double x, y;
};
double polygonArea(const vector<Point> &points)
{
    double area = 0.0;
    int N = points.size();

    for (int i = 0; i < N; i++)
    {
        int j = (i + 1) % N;
        area += points[i].x * points[j].y - points[i].y * points[j].x;
    }

    return abs(area) * 0.5;
}

int main()
{
    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    cout << fixed << setprecision(2) << polygonArea(points);

    return 0;
}
