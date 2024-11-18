#include <iostream>
#include <vector>
using namespace std;

void find_decomposition(int x) {
    bool found = false;
    int max_n = 0;
    vector<int> result;
    for (int n = 2; n * (n - 1) / 2 < x; ++n) {
        // 计算a的值
        int numerator = x - n * (n - 1) / 2;
        if (numerator % n == 0) {
            int a = numerator / n;
            if (a > 0) {
                vector<int> sequence;
                for (int i = 0; i < n; ++i) {
                    sequence.push_back(a + i);
                }
                if (n > max_n) {
                    max_n = n;
                    result = sequence;
                    found = true;
                }
            }
        }
    }
    if (found) {
        cout << x << "=";
        for (int i = 0; i < result.size(); ++i) {
            if (i > 0) cout << "+";
            cout << result[i];
        }
        cout << endl;
    } else {
        cout << x << ":NOANSWER" << endl;
    }
}

int main() {
    int x;
    cin >> x;
    find_decomposition(x);
    return 0;
}
