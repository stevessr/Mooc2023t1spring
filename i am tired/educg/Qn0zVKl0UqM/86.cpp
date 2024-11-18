#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string invert(string s)
{
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    int T;
    cin >> T;
    string s;
    while (T--)
    {
        cin >> s;
        cout << invert(s) << endl;
    }
    return 0;
}