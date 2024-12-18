#include <stdio.h>
#include <stdlib.h>

int same_set(int a[], int b[], int len)
{
    int count_a[101] = {0};
    int count_b[101] = {0};

    for (int i = 0; i < len; i++)
    {
        count_a[a[i]]++;
    }

    for (int i = 0; i < len; i++)
    {
        count_b[b[i]]++;
    }

    // 比较两个计数数组
    for (int i = 0; i < 101; i++)
    {
        if (count_a[i] != count_b[i])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int len;
    scanf("%d", &len);
    int a[len], b[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &b[i]);
    }

    if (same_set(a, b, len))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
