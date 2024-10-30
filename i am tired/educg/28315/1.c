#include <stdio.h>
int main()
{
    long  data1, data2;
    char op;
    scanf("%ld %ld %c", &data1, &data2, &op);
    switch (op)
    {
    case '+':
        printf("%ld", data1 + data2);
        break;
    case '-':
        printf("%ld", data1 - data2);
        break;
    case '*':
        printf("%ld", data1 * data2);
        break;
    case '/':
        if (data1 % data2 == 0)
        {
            printf("%ld", data1 / data2);
        }
        else
        {
            printf("%.2lf", data1 * 1.0 / data2);
        }

        break;
    default:
        break;
    }
    return 0;
}