#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int m;
    long double n, c = 0;
    cin >> n >> m;
    m--;
    c += n;
    while (m--)
    {
        n /= 4;
        c += 2 * n;
    }
    cout << fixed << setprecision(2) << c<<endl<<n/4;
    return 0;
}