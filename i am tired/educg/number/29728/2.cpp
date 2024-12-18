// 分数化简
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, n, m1, n1;
    cin >> m >> n;
    m1 = m, n1 = n;
    while ((m1>n1?m1%n1:n1%m1)!=0)
    {
        m1>n1?m1%=n1:n1%=m1;
    }
    cout<<m/min(m1,n1)<<" "<<n/min(m1,n1)<<endl;
    return 0;
}