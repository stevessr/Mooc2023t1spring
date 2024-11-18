#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double cosx(long double value, long double x, long times, bool alpha, long target)
{
    if (times > target)
    {
        return value;
    }
    else
    {
        long double term = powl(x, 2 * times) / tgammal(2 * times + 1);
        if (alpha)
        {
            return cosx(value - term, x, times + 1, !alpha, target);
        }
        else
        {
            return cosx(value + term, x, times + 1, !alpha, target);
        }
    }
}

int main()
{
    long double x;
    long T;
    cin >> x >> T;
    cout << fixed << setprecision(8) << cosx(1, x, 1, true, T);
    return 0;
}
