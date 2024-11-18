#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long input;
    cin >> input;
    int up = sqrt(input), times = 0;
    //cout<<input<<endl;
    for (int i = 2; i <= up; i++)
    {
        times = 0;
        if (input % i == 0)
        {
            do
            {
                times++;
                input /= i;
            } while (input % i == 0);
        }
        if (times > 1)
        {
            cout << i << " ";
            up = sqrt(input);
        }
    }
    return 0;
}