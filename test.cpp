#include <iostream>
#include <string>
using std::cout,std::endl,std::cin,std::string;
int main(){
    int ch = ' ';
    while(ch != EOF){
        ch=getchar();
        cout<<"output:";
        cout.put(ch)<<"\tch="<<ch<<endl;
    }
    return 0;
}

