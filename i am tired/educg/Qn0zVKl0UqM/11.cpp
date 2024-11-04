#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class Period {
public:
    int left, right;
    Period(int l, int r) : left(l), right(r) {}
};
vector<Period> mergePeriods(vector<Period> &periods) {
    vector<Period> merged;
    sort(periods.begin(), periods.end(), [](const Period &a, const Period &b) {
        return (a.left < b.left) || (a.left == b.left && a.right < b.right);
    });
    for (auto &period : periods) {
        if (merged.empty() || merged.back().right < period.left) {
            merged.push_back(period);
        } else {
            merged.back().right = max(merged.back().right, period.right);
        }
    }
    return merged;
}

int main() {
    ifstream file("prz.in");
    ofstream output("prz.out");
    int n;
    file >> n;
    
    vector<Period> periods;
    int a, b;
    for (int i = 0; i < n; ++i) {
        file >> a >> b;
        periods.push_back(Period(a, b));
    }
    vector<Period> result = mergePeriods(periods);
    for (auto &p : result) {
        output << p.left << " " << p.right << endl;
    }
    file.close();
    output.close();
    return 0;
}
