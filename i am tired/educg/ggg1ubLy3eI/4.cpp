#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
long a,b,c;
long double s,size;
cin>>a>>b>>c;
s = (a+b+c)/2;
size =sqrt(s*(s-a)*(s-b)*(s-c));
cout<<fixed<<setprecision(3)<<size;
    return 0;
}