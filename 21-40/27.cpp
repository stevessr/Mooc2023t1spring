#include <iostream>
using std::cout,std::endl,std::cin,std::string;
int main(){
    unsigned int L,R,times=0,Lin;
    cin>>L>>R;R++;
    for(;L<R;L++){
        Lin = L;
        while(Lin != 0){
            if (Lin%10 == 2){
                times++;
            }
            Lin /= 10;
        }
    }
    cout<<times;
    return 0;
}