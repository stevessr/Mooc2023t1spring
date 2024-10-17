#include <iostream>
using std::cout,std::endl,std::cin,std::string;
int main(){
    long a,temp;
    cin>>temp;
    a=temp;

    cin>>temp;
    if (temp>a){
        a = temp;
    }
    cin>>temp;
    if (temp>a){
        a = temp;
    }
    cout<<a;
    return 0;
}