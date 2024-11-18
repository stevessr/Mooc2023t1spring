#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double e;
    cin >> e;
    double pi_2 = 1.0;
    double best_pi = 0.0;
    int n = 1;
    double min_diff = 1e9;
    while (true) {
        double current_term = (2.0 * n) / (2.0 * n - 1) * (2.0 * n) / (2.0 * n + 1);
        pi_2 *= current_term;
        double current_pi = 2.0 * pi_2;
        double diff = fabs(current_pi - e);
        if (diff < min_diff) {
            best_pi = current_pi;
            min_diff = diff;
        } else {
            break;
        }

        n++;
    }

    // 输出最接近的π值，并保留9位小数
    cout << fixed << setprecision(9) << best_pi << " " << n-1 << endl;

    return 0;
}
