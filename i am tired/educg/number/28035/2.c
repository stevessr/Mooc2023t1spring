#include <stdio.h>
int main()
{
    int T;
    scanf("%d", &T);
    int min, max, temp;
    scanf("%d", &temp);
    min = max = temp, T--;
    while (T--)
    {
        scanf("%d", &temp);
        if (temp > max)
        {
            max = temp;
        }
        else if (temp < min)
        {
            min = temp;
        }
    }
    printf("%d %d", max, min);
}