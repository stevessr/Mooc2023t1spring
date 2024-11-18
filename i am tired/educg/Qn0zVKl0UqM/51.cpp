#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    int len_s = s.length();
    int len_t = t.length();
    int dp[51][51] = {0};
    int maxLength = 0;
    int endPos = 0;
    for (int i = 1; i <= len_s; ++i) {
        for (int j = 1; j <= len_t; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endPos = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    if (maxLength == 0) {
        cout << "No Answer" << endl;
    } else {
        cout << s.substr(endPos - maxLength + 1, maxLength) << endl;
    }

    return 0;
}
