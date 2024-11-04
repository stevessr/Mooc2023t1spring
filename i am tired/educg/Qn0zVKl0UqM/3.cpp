#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct point
{
    short x, y;
};
double hai(double a, double b, double c)
{
    double p = (a + b + c) * 0.5;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double distance(point p1, point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
    point p1, p2, ptemp;
    double size = 0, a, b, c;
    short T;
    cin >> T;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    a = distance(p1, p2);
    T -= 2;
    while (T--)
    {
        cin >> ptemp.x >> ptemp.y;
        b = distance(p1, ptemp);
        c = distance(p2, ptemp);
        size += hai(a, b, c);
        p2 = ptemp;
    }
    cout << fixed << setprecision(2) << size;
    return 0;
}
