#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool isprime(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else
    {
        int max = sqrt(n) + 1;
        for (int i = 2; i <= max; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", isprime(n));
    return 0;
}