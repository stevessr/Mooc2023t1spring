//数字排序
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int cmp(const void * a , const void * b){
    return *(double *)a - *(double*)b;
}
int main(){
    double a[3];
    scanf("%lf %lf %lf",a,a+1,a+2);
    qsort(a,3,sizeof(double),cmp);
    printf("%g %g %g",a[0],a[1],a[2]);

    return 0;
}