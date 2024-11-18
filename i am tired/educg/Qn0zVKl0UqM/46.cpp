#include <map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    set<int> nums;
    int temp;
    while (T--) {
        cin >> temp;
        nums.insert(temp);
    }
    vector<int> numv;
    for (auto &i : nums) {
        numv.push_back(i);
    }

    int maxkey = 1;  
    vector<pair<int, int>> longestSeqs;
    int currentkey = 1;
    int currentStart = 0;

    // 遍历numv，寻找所有最长连续升序子序列
    for (int i = 1; i < numv.size(); ++i) {
        if (numv[i] == numv[i - 1] + 1) {
            currentkey++; 
        } else {
            if (currentkey >= 2) {
                if (currentkey > maxkey) {
                    maxkey = currentkey;
                    longestSeqs.clear();
                    longestSeqs.push_back({currentStart, i - 1});
                } else if (currentkey == maxkey) {
                    longestSeqs.push_back({currentStart, i - 1});
                }
            }
            currentStart = i;
            currentkey = 1;
        }
    }

    if (currentkey >= 2) {
        if (currentkey > maxkey) {
            maxkey = currentkey;
            longestSeqs.clear();
            longestSeqs.push_back({currentStart, numv.size() - 1});
        } else if (currentkey == maxkey) {
            longestSeqs.push_back({currentStart, numv.size() - 1});
        }
    }

    cout << maxkey << endl;

    if (maxkey >= 2) {
        for (const auto& seq : longestSeqs) {
            for (int i = seq.first; i <= seq.second; ++i) {
                cout << numv[i] << " ";
            }
            cout << endl;
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}
