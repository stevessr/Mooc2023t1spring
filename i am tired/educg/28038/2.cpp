#include <iostream>
using namespace std;

void primeFactorization(int n) {
    bool first = true;

    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            n /= i;
            first = false;
        }
    }

    if (n > 1) { // 如果 n 最终大于1，说明 n 本身是质数
        if (!first) {
            cout << " ";
        }
        cout << n;
    }
}

int main() {
    int n;
    cin >> n;

    primeFactorization(n);
    return 0;
}
