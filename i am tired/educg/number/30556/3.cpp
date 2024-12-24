#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int main()
{
    double x;
    cin >> x;
    if ((x - long(x)) == 0)
    {
        cout << long(x);
    }
    else
    {
        cout << setprecision(200) << x;
    }

    return -1;
}