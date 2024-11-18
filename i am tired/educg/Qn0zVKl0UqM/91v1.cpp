#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Element {
    int row, col, value;
};

int main() {
    int T1;
    cin >> T1;
    vector<Element> A;
    for (int i = 0; i < T1; ++i) {
        int row, col, value;
        cin >> row >> col >> value;
        A.push_back({row, col, value});
    }

    int T2;
    cin >> T2;
    vector<Element> B;
    for (int i = 0; i < T2; ++i) {
        int row, col, value;
        cin >> row >> col >> value;
        B.push_back({row, col, value});
    }

    map<int, vector<Element>> B_by_col;
    for (const auto& elem : B) {
        B_by_col[elem.col].push_back(elem);
    }

    map<pair<int, int>, int> result;

    for (const auto& a : A) {
        if (B_by_col.find(a.col) != B_by_col.end()) {
            for (const auto& b : B_by_col[a.col]) {
                int row = a.row;
                int col = b.col;
                result[{row, col}] += a.value * b.value;
            }
        }
    }

    vector<Element> result_sparse;
    for (const auto& [key, value] : result) {
        if (value != 0) {
            result_sparse.push_back({key.first, key.second, value});
        }
    }

    sort(result_sparse.begin(), result_sparse.end(), [](const Element& e1, const Element& e2) {
        if (e1.row != e2.row) return e1.row < e2.row;
        return e1.col < e2.col;
    });

    for (const auto& elem : result_sparse) {
        cout << elem.row << " " << elem.col << " " << elem.value << endl;
    }

    return 0;
}
