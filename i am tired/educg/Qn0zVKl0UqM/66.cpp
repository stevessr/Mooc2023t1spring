#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int M;
    cin >> M;
    int stop = M / 2 + 1;
    int begin = 0;
    for (int i = 1, j; i < stop; i++)
    {
        begin = 0;
        for (j = i; begin < M; j++)
        {
            begin += j;
        }
        if (begin == M)
        {
            for (int m = i; m < j; m++)
            {
                cout << m << " ";
            }
            cout << endl;
        }
    }
    return 0;
}