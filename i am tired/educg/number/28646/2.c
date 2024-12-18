#include <stdio.h>
int addposall(int temp)
{
    if (temp > 10)
    {
        return ((temp % 10) + addposall(temp / 10));
    }
    else
    {
        return temp;
    }
}
int main()
{
    int T, temp;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &temp);
        printf("%d ", addposall(temp));
    }
    return 0;
}