#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin >> T;
    string str;
    while (T--)
    {
        cin >> str;
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}