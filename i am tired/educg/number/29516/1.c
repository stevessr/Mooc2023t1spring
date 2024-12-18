#include <stdio.h>
int main()
{
    int temp;
    scanf("%d", &temp);
    int N[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100, temp};
    for (int i = 9; i >= 0; i--)
    {
        if ((temp >= N[i - 1]) && (temp <= N[i]))
        {
            N[i+1] = N[i];
            N[i] = temp;
            break;
        }
        else if (i == 0)
        {
            N[1] = N[0];
            N[0] = temp;
        }
        else if (i == 9 && temp > N[9])
        {
            break;
        }
        else
        {
            N[i + 1] = N[i];
            continue;
        }
    }
    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", N[i]);
    }
    return 0;
}