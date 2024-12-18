#include <iostream>
#include <cmath>
using namespace std;
int out(long double expected)
{
    int n = 1;
    while (abs(1.0 / (2 * n + 1)) > expected)
    {
        n++;
    }
    return n+1;
}
int main()
{
    long double a;
    cin >> a;
    cout << out(a/4.0);
    return 0;
}