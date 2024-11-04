#include <iostream>
using namespace std;
int main()
{
    short a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i < 10)
        {
            if (i * i % 10 == i)
            {
                cout << i << endl;
            }
        }
        else
        {
            if (i * i % 100 == i)
            {
                cout << i << endl;
            }
        }
    }

    return 0;
}