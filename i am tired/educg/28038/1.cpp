#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int * m = new int , *n = new int;
    cin>>*m>>*n;
    int martix[*m][*n];
    for(int i=0 ; i<*m;i++){
        for (int j =0;j<*n;j++){
            cin>>martix[i][j];
        }
    }
    cout<<*n<<" "<<*m<<endl;
    for (int j=0;j<*n ;j++){
        for (int i=*m-1;i>-1;i--){
            cout<<martix[i][j]<<" ";
        }cout<<endl;
    }
    delete(m),delete(n);
    return 0;
}