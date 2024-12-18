// 公式计算π
#include <iostream>
#include <cmath>
#include <iomanip>
#pragma GCC optimize(3)
long double eachstep(long double n)
{
    return 4.0 * n * n / (4.0 * n * n - 1);
}
long double pi(long double e)
{
    long double last = 2, next = 2;
    int n = 0;
     while (abs(last - e) >= abs(next - e))
    {
        last = next;
        next *= eachstep(++n);
    }
    std::cout <<std::fixed<<std::setprecision(9)<< last << " " << n - 1;
    return n;
}
int main()
{
    long double e;
    std::cin>>e;
    pi(e);
    return 0;
}