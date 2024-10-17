#include <iostream>
using std::cout,std::endl,std::cin,std::string;
int main(){
    long long x,y;
    cin>>x>>y;
    if( x<=1 && x>=-1 && y>=-1&&y<=1){
        cout<<"yes";
    }else{
        cout<<"no";
    }
    return 0;
}