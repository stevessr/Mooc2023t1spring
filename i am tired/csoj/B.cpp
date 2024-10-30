#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    // 按从小到大的顺序排列三条边
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    // 检查是否能构成三角形
    if (a + b <= c) {
        cout << "Not triangle" << endl;
    } else {
        long long a2 = a * a;
        long long b2 = b * b;
        long long c2 = c * c;

        if (a2 + b2 == c2) {
            cout << "Right triangle" << endl;
        } else if (a2 + b2 > c2) {
            cout << "Acute triangle" << endl;
        } else {
            cout << "Obtuse triangle" << endl;
        }
        
        if (a == b || b == c) {
            cout << "Isosceles triangle" << endl;
        }
        
    }

    return 0;
}
