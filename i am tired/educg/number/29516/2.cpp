#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    unordered_map<int, int> frequency;
    for (int i = 0; i < n; ++i) {
        frequency[nums[i]]++;
    }

    int maxCount = 0;
    for (const auto& entry : frequency) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }

    vector<int> result;
    for (const auto& entry : frequency) {
        if (entry.second == maxCount) {
            result.push_back(entry.first);
        }
    }

    sort(result.begin(), result.end());

    for (int num : result) {
        cout << num << " " << maxCount << endl;
    }

    return 0;
}
