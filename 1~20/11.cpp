#include <iostream>
#include <cmath>
using std::cout,std::endl,std::cin,std::string;
int main(){
    long long h,r;
    cin>>h>>r;
    long double v = M_PI*r*r*h/1000;
    long target = 20.0/v;
    if (target < 20.0/v){
        cout<<target+1;
    }else{
        cout<<target;
    }
    return 0;
}