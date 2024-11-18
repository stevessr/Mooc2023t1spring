#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
void itob(long n, string &s, int b);
int main()
{
    long n;
    string str = "";
    int b;
    cin>>n>>b;
    bool fu = (n < 0);
    if (fu)
    {
        n = -n;
        cout << "-";
    }
    itob(n, str, b);
    cout << str;
    return 0;
}
void itob(long n, string &s, int b)
{
    while (n > 0)
    {
        s += ('0' + n % b);
        n /= b;
    }
    reverse(s.begin(),s.end());
}