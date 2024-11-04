#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, temp;
    set<int> set1, set2, resultSet;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        set1.insert(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        if (set1.count(temp))
        {
            set1.erase(temp);
        }
        else
        {
            set2.insert(temp);
        }
    }
    resultSet.insert(set1.begin(), set1.end());
    resultSet.insert(set2.begin(), set2.end());
    bool first = true;
    for (auto it = resultSet.begin(); it != resultSet.end(); ++it)
    {
        if (!first)
            cout << " ";
        cout << *it;
        first = false;
    }
    return 0;
}
