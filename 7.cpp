#include <iostream>
using std::cout,std::endl,std::cin,std::string;
string To8(string &s){
string ss = s;
int len = s.length();
s = "";
for (int i = 8; i > len;i--){
    s+=" ";
}
s+=ss;
return s;
}
int main(){
string s1,s2,s3;
cin>>s1>>s2>>s3;
cout<<To8(s1)<<" "<<To8(s2)<<" "<<To8(s3);
    return 0;
}

