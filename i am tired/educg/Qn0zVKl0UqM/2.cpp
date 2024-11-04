#include <iostream>
#include <vector>
using namespace std;
int sumOfDivisors(int num) {
    int sum = 1; 
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<pair<int, int>> twins;
    for (int A = M; A <= N; ++A) {
        int B = sumOfDivisors(A);
        if (B > A && B <= N && sumOfDivisors(B) == A) {
            twins.push_back({A, B});
        }
    }
    if (twins.empty()) {
        cout << "NONE";
    } else {
        for (const auto &pair : twins) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}
