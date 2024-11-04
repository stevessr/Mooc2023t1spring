#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    long double a,an;
    int T;
    cin>>a>>T;
    an=a;while(T--){
        an=(2*an+a/an/an)/3;
    }
    cout<<fixed<<setprecision(5)<<an;
    return 0;
}