#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=1;i<9;i++){
        for(int j=1;j<i;j++){
            if(T==(10*i+j)*(10*j+i)){
                cout<<j<<i;
                return 0;
            }
        }
    }
    return 0;
}