#include <iostream>
using namespace std;
int main()
{
    int T;
    short a = 0, b1 = 1, b2 = 2, v = 3;
    cin >> T;
    while (T--)
    {
        cin >> a;
        if (a == b1)
        {
            a = v;
            v = b2;
            b2 = a;
        }
        else if (a == b2)
        {
            a = v;
            v = b1;
            b1 = a;
        }
        else if (a == v)
        {
            cout << "NO";
            return 0;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}