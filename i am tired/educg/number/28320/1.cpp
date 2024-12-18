#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    scanf("%d:%d", &m, &n);
    long double hour_angle = 30 * (m % 12) + 0.5 * n;
    long double minute_angle = 6 * n;

    long double angle = fabs(hour_angle - minute_angle);
    if (angle > 180) {
        angle = 360 - angle;
    }

    cout << fixed << setprecision(3) << angle;
    return 0;
}
