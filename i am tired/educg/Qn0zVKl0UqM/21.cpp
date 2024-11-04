#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

pair<int, string> longestPalindrome(const string& s) {
    int maxLength = 0;
    string longestPalin = "";
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            string substring = s.substr(i, j - i + 1);
            if (isPalindrome(substring) && substring.size() > 1) {
                if (substring.size() > maxLength) {
                    maxLength = substring.size();
                    longestPalin = substring;
                }
            }
        }
    }
    
    return {maxLength, longestPalin};
}

int main() {
    string input;
    cin >> input;
    auto result = longestPalindrome(input);
    cout << result.first << endl;
    cout << result.second << endl;
    return 0;
}
