// 比较两组整数
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
int main(int args, char *argv[], char *env[])
{
    int M, N;
    cin >> M;
    vector<int> Mv(M, 0);
    for (auto &i : Mv)
    {
        cin >> i;
    }
    cin >> N;
    vector<int> Nv(N, 0);
    for (auto &i : Nv)
    {
        cin >> i;
    }
    bool undone = true;
    set<int> did;
    for (auto &i : Mv)
    {
        bool find;
        find = false;
        for (auto &j : Nv)
        {
            if (i == j)
            {
                if (did.find(i) != did.end())
                {
                    break;
                }
                else
                {
                    did.insert(i);
                    find = true;
                }
                break;
            }
        }
        if (find)
        {
            cout << i << " ";
            if (undone)
            {
                undone = false;
            }
        }
    }

    if (undone)
    {
        cout << "No Answer";
    }
    return 0;
}