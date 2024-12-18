//求差集
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    vector<int> av;
    int temp;
    do
    {
        cin >> temp;
        if (temp == -1)
        {
            break;
        }
        else
        {
            av.push_back(temp);
        }
    } while (temp != -1);
    set<int> bs;
    do
    {
        cin >> temp;
        if (temp == -1)
        {
            break;
        }
        else
        {
            bs.insert(temp);
        }
    } while (temp != -1);
    for (auto &i : av)
    {
        if (bs.find(i) == bs.end())
        {
            cout << i << " ";
        }
    }
    return 0;
}