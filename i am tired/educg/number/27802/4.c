#include <stdio.h>
void try(double * xray ,double x1 ){
*xray = (*xray+x1/(*xray))/2;
}
int main(){
double xray,x1;
int T;
scanf("%lf %d",&xray,&T);
x1=xray;
while(T--){
    try(&xray,x1);
}
printf("%.5lf",xray);
    return 0;
}