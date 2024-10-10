#include <iostream>
#include <iomanip>  // 用于设置输出格式
using std::cout,std::endl,std::cin,std::string;
int main(){
    char a;
    long long b;
    float c;
    double d;
    cin>>a>>b>>c>>d;
    cout << std::fixed << std::setprecision(6) << a<<" "<<b<<" "<<c<<" "<<d;  // 保留6位小数
    return 0;
}