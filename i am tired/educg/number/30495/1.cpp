// sinx计算公式
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double result = 0.0, temp;
    for (int i = 1; i <= n; i++)
    {
        temp = 1.0;
        for (int j = 1; j < (2 * i); j++)
        {
            temp *= x / j;
        }
        //cout << temp << endl;
        result += temp * ((i % 2 == 0) ? -1 : 1);
    }
    cout << fixed << setprecision(8) << result;
    return 0;
}