/*
#include <iostream>
#include <stdio.h>
using std::cout,std::endl,std::cin,std::string;
int main(){
    long double ff;
    cin>>ff;
    printf("%ld.12f",ff);
    return 0;
}
*/ //useless from me
#include <iostream>
#include <iomanip>  // 用于设置输出格式
int main() {
    double num;
    std::cin >> num;  // 读入一个双精度浮点数
    std::cout << std::fixed << std::setprecision(12) << num << std::endl;  // 保留12位小数
    return 0;
}
//powered by gpt-4o