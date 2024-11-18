#include <iostream>
#include <vector>
#pragma GCC optimize("O3")
using namespace std;
void target(int s);
int main()
{
    short s;
    cin >> s;
    target(s * s * s);
    return 0;
}
void target(int s)
{
    int sum, current, start = 1;
    vector<int> vint;
    while (true)
    {
        sum = 0;
        current = start;
        bool success = false;
        vint.empty();
        while (sum < s)
        {
            sum += current;
            vint.push_back(current);
            current += 2;
            if (sum == s)
            {
                for (auto i : vint)
                {
                    cout << i << " ";
                }
                success = true;
                break;
            }
            start += 2;
        }
        if (success)
        {
            break;
        }
    }
}