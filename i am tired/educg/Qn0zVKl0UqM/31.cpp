#include <iostream>
using namespace std;
bool Armstrong(long num);
long trice(long num);
int main()
{
    long a, b;
    cin >> a >> b;
    bool success = false;
    if (a > b || a == 0 || b == 0)
    {
        cout << "error";
        return 0;
    }
    for (; a <= b; a++)
    {
        if (Armstrong(a))
        {
            cout << a << endl;
            success = true;
        }
    }
    if (!success)
    {
        cout << "no";
    }
    return 0;
}
bool Armstrong(long num)
{
    long ntemp = num, stemp = 0;

    while (ntemp > 0)
    {
        stemp += trice(ntemp % 10);
        ntemp /= 10;
    }
    return (stemp == num);
}
long trice(long num)
{
    return num * num * num;
}