#include <iostream>
using namespace std;
int main(){
short mount ;
long max , min,temp;
cin>>mount>>temp;
min = max = temp;
while (--mount>0){
    cin>>temp;
    if(temp>max){
        max = temp;
    }else if(temp<min){
        min = temp;
    }
}
    return 0;
}