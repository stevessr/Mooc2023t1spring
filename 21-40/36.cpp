#include <iostream>
using std::cout,std::endl,std::cin,std::string;
int main(){
    int a,b;
    cin>>a>>b;
    while(a>b?a%b==0:b%a==0){
        a>b?a%=b:b%=a;
    }
    cout<<(a<b?a:b);
    return 0;
}