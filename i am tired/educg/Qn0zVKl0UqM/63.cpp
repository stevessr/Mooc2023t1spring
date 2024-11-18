#include <iostream>
using namespace std;
int main()
{
    int h, m, s;
    char ch;
    cin >> h >> ch >> m >> ch >> s;
    if (++s == 60)
    {
        s = 0;
        if (++m == 60)
        {
            m = 0;
            if (++h == 24)
            {
                h = 0;
            }
        }
    }
    cout << h << ":" << m << ":" << s;
    return 0;
}