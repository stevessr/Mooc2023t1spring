#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        char ch;
        while(columnNumber>0){
            ch = 'A' + (columnNumber)%26 -1;
            ans = ch + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};