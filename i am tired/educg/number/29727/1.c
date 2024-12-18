// 简易计算器
#include <stdio.h>

int main()
{
    int data1, data2;
    char op;

    scanf("%d %d %c", &data1, &data2, &op);

    if (op == '+')
    {
        printf("%d\n", data1 + data2);
    }
    else if (op == '-')
    {
        printf("%d\n", data1 - data2);
    }
    else if (op == '*')
    {
        printf("%d\n", data1 * data2);
    }
    else if (op == '/')
    {
        if (data2 == 0)
        {
            printf("Error! Division by zero.\n");
        }
        else
        {
            if (data1 % data2 == 0)
            {
                printf("%d\n", data1 / data2);
            }
            else
            {
                printf("%.2f\n", (float)data1 / data2);
            }
        }
    }
    else
    {
        printf("Invalid operator!\n");
    }

    return 0;
}
