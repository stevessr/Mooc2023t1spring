#include <iostream>
using namespace std;
long long factorial(long num)
{
    long long factorial2 = 1;
    for (long i = 1; i <= num; ++i)
    {
        factorial2 *= i;
    }
    return factorial2;
}
long long cuuu(long m, long n)
{
    long long  ans = 1;
    for(long long i =1;i<=m;i++){
        ans = ans * (n-m+i)/i; 
    }
    return ans;
}
int main()
{
    short T, in;
    cin >> T;
    while (T--)
    {
        cin >> in;
        for (long i = 0; i < in ; i++)
        {
            for (long j = 0; j < i; j++)
            {
                cout << cuuu(j, i) << " ";
            }
            cout <<"1" << endl;
        }
    }

    return 0;
}