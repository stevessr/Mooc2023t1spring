#include <iostream>
#include <cmath>
#include <iomanip>
#pragma GCC optimize("Ofast")

double eachstep(double n) {
    return 4.0 * n * n / (4.0 * n * n - 1);
}

int pi(double e) {
    double last = 2.0, next = 2.0;
    double diff_last = std::abs(last - e);
    int n = 0;

    while (true) {
        next *= eachstep(++n);
        double diff_next = std::abs(next - e);

        if (diff_next >= diff_last) {
            break;
        }

        diff_last = diff_next;
        last = next;
    }

    std::cout << std::fixed << std::setprecision(9) << last << " " << n - 1 << '\n';
    return n;
}

int main() {
    double e;
    std::cin >> e;
    pi(e);
    return 0;
}
