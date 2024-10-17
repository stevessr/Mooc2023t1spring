#include <iostream>
using std::cout, std::endl, std::cin, std::string;
int main()
{
    long long x, y, n, ap, bp;
    cin >> n >> x >> y;
    ap = y / x;
    bp = n - ap;
    if (ap * x == y)
    {
        cout << bp;
    }
    else
    {
        if (bp < 1)
        {
            cout << 0;
        }
        else
        {
            cout << bp - 1;
        }
    }
    return 0;
}