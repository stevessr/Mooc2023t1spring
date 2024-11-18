#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int a, b, a2 = 0, b2 = 0;
    cin >> a >> b;
    vector<int> va, vb;
    for (int i = max(a, b); i > 0; i--)
    {
        if (a % i == 0 && a != i)
        {
            va.push_back(i);
            a2 += i;
        }
        if (b % i == 0 && b != i)
        {
            vb.push_back(i);
            b2 += i;
        }
    }
    cout << a << ",";
    bool first = true;
    for (auto &i : va)
    {
        if (!first)
        {
            cout << "+";
        }
        cout << i;
        first = false;
    }
    cout << "=" << a2 << endl;
    cout << b << ",";
    first = true;
    for (auto &i : vb)
    {
        if (!first)
        {
            cout << "+";
        }
        cout << i;
        first = false;
    }
    cout << "=" << b2 << endl;
    cout << (a2 == b);
    return 0;
}