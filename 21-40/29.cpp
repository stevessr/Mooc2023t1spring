#include <iostream>
#include <vector>
using std::cout,std::endl,std::cin,std::string,std::vector;
int main(){
    short a,c=0;
    vector<short> apple;
    for(short b=0;b<10;b++){
        cin>>a;
        apple.push_back(a);
    }
    cin>>a;
    a+=30;
    for (auto i : apple){
        if (i<=a){
            c++;
        }
    }
    cout<<c;
    return 0;
}