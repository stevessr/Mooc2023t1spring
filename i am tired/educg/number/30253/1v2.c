// 求公式近似值A improve
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int seekE(double *last, const double x, const double differ)
{
    if (differ == 1)
    {
        return 0;
    }
    double next = 1, lastone;
    int times = 0;
    double different;
    double i = 0;
    do
    {
        times++;
        lastone = next;
        for (; i < times; i++)
        {
            next *= x / (i + 1);
        }
        different = abs(lastone - next);
    } while (differ < next);
    return times;
}
int main()
{
    int x;
    double differ, *last = malloc(sizeof(double));
    *last = 1;
    scanf("%d %lf", &x, &differ);
    printf("%d", seekE(last, x, differ));
    return 0;
}