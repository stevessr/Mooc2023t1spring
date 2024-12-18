// 整数求和
#include <stdio.h>
int na(int times,int a){
if(times==1){
    return a;
}
return 10*na(times-1,a)+a;
}
int main()
{
    int a, n, sum = 0,temp;
    scanf("%d %d",&a, &n);
    sum = a;
    printf("%d ",a);
    for (int i = 2; i <= n; i++)
    {
        temp = na(i,a);
        printf("+ %d ",temp);
        sum += temp;
    }
    printf("= %d", sum);
    return 0;
}