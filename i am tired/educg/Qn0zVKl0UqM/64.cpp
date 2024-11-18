#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin>>x>>y;
    while ((x > y ? x % y : y % x) != 0)
    {
        x > y ? x %= y : y %= x;
    }
    cout << (x < y ? x : y);
    return 0;
}