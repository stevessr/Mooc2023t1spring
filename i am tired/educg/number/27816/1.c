#include <stdio.h>

int main(){
    int number;
    scanf("%d",&number);
    if (number<100 || number >999){
        printf("%d",-1);
    }else{
        printf("%d",number+number%10*99-number/100*99);
    }
    return 0;
}