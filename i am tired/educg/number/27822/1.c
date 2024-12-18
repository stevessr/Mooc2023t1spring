#include <stdio.h>

int main(){
    int a,a1;
    scanf("%d",&a);
    a1 = a;
    short al=0;
    short ac[5];
    while (a1 > 0){
        ac[al]=a1%10;
        a1 /=10;
        al++;
    }
printf("%d\n%d\n",al,a);
for (int i=0;i<al;i++){
    printf("%d",ac[i]);
}
}