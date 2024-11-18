#include <iostream>
int se[4] = {10, 5, 2, 1};
using namespace std;
int main()
{
    int M, temp;
    cin >> M;
    for (int i = 0; i < 4; i++)
    {
        temp = M / se[i];
        M -= temp * se[i];
        cout << temp << " ";
    }
    return 0;
}