// 求公式近似值A
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int seekE(double *last, const int x, const double differ)
{
    if(differ == 1){
        return 0;
    }
    double next = 1;
    int times = 0;
    do
    {
        times++;
        next = pow(x,times);
        for(double i=0;i<times;i++){
            next /= i+1;
        }
    } while (differ < next);
    return times;
}
int main()
{
    int x;
    double differ, *last = malloc(sizeof(double));
    *last = 1;
    scanf("%d %lf", &x, &differ);
    printf("%d", seekE(last, abs(x), differ));
    return 0;
}