#include <iostream>
#include "bigint.h"
using namespace std;
bigint getnum(int len);
int main(){
    int a,n;
    cin>>a>>n;
    bigint begin = getnum(n);
    for(int i=1;i<n;i++){
        begin -=getnum(i);
    }
    cout<<a*begin;
    return 0;
}
bigint getnum(int len){
    if(len>1)
    return 1+getnum(len-1)*bigint(10);
    else
    return 1;
}