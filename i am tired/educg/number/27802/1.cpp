#include <iostream>
using std::cout,std::endl,std::cin,std::string;
int main(){
    short b;
    cin>>b;
    if (b<1000){
        cout<<"Error!";
    }else {
            cout.put('A'+b/1000+12);
            cout.put('A'+(b/100)%10+12);
            cout.put('A'+(b/10)%10+12);
            cout.put('A'+b%10+12);
    }
    return 0;
}