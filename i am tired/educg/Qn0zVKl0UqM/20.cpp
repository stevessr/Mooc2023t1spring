#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = i * n + j + 1;
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
