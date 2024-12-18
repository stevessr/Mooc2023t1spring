#include <stdio.h>
#include <math.h>
int main(){
    int input;
    scanf("%d",&input);
    for(int i=1;i<input;i++){
        if(input%i==0){
            printf("%d ",i);
        }
    }
    printf("%d",input);
    return 0;
}