#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    T = T * T * T;
    int init = 1, i, all;
rebegin:
    all = 0, i = init;
    for (; (all + i) <= T; i += 2)
    {
        all += i;
    }
    if (all == T)
    {
        cout << init << " " << (i - init)/2 << endl;
    }
    else
    {
        init += 2;
        goto rebegin;
    }
    return 0;
}