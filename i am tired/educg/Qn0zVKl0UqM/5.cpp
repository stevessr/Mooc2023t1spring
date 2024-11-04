#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    bool allow = true;
    vector<int> vst;
    vst.push_back(2);
    for (int i = 3; i <= T; i++)
    {
        allow = true;
        for (int j : vst)
        {
            if (i % j == 0)
            {
                allow = false;
                break;
            }
        }
        if (allow)
        {
            vst.push_back(i);
        }
    }
    for (int k : vst)
    {
        if (k != 2)
        {
            cout << " " << k;
        }
        else
        {
            cout << k;
        }
    }
    return 0;
}