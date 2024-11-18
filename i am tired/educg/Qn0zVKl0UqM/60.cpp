#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    int m, n;
    char colon;
    cin >> m >> colon >> n;
    double minute_angle = n * 6.0;
    double hour_angle = (m % 12) * 30 + n * 0.5;
    double angle = fabs(hour_angle - minute_angle);
    double final_angle = min(angle, 360 - angle);
    cout << fixed << setprecision(3) << final_angle << endl;
    return 0;
}