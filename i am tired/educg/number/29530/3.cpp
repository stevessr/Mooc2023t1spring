#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> s;
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        s.push_back(n);
    }
    cin >> T;
    while (T--)
    {
        cin >> n;
        s.push_back(n);
    }
    sort(s.begin(), s.end());
    for (auto &i : s)
    {
        cout << i << " ";
    }
    return 0;
}