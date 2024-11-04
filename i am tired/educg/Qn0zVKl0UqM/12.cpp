#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    vector<int> s1;
    set<int> s2;
    int num;
    cin >> num;
    do
    {
        s1.push_back(num);
        cin >> num;
    } while (num != -1);
    cin >> num;
    do
    {
        s2.insert(num);
        cin >> num;
    } while (num != -1);

    for (auto i : s1)
    {
        if (s2.find(i) == s2.end())
        {
            cout << i << " ";
        }

        }
    return 0;
}