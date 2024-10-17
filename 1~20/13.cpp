#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout, std::endl, std::cin;

short delta(long double a, long double b, long double c, long double &d) {
    long double discriminant = b * b - 4 * a * c;  // 判别式 b² - 4ac
    d = sqrt(std::abs(discriminant));  // 绝对值取平方根，用于处理虚根情况
    if (discriminant == 0) {
        return 1;  // 重根
    } else if (discriminant > 0) {
        return 0;  // 两个不同实根
    } else {
        return -1;  // 虚根
    }
}

int main() {
    long double a, b, c, d;
    cin >> a >> b >> c;

    cout << std::fixed << std::setprecision(5);

    long double realPart = -b / (2 * a);  // 实部
    if (std::abs(realPart) < 1e-6) {  // 如果实部非常接近0，将其设为正的0.00000
        realPart = 0.00000;
    }

    switch (delta(a, b, c, d)) {
        case 1:  // 重根
            cout << "x1=x2=" << realPart << endl;
            break;
        case 0:  // 两个不同的实根
            cout << "x1=" << (realPart + d / (2 * a)) << ";x2=" << (realPart - d / (2 * a)) << endl;
            break;
        case -1:  // 虚根
            cout << "x1=" << realPart << "+" << d / (2 * a) << "i;"
                 << "x2=" << realPart << "-" << d / (2 * a) << "i" << endl;
            break;
    }

    return 0;
}
