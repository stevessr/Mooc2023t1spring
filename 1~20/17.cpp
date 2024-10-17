#include <iostream>
#include <iomanip>  // 用于设置输出格式
using std::cout,std::endl,std::cin,std::string;
int main(){
    int number;
    cin>>number;
    long long total=0,temp;
    long double aver;
    for (int i = 0; i< number;i++){
        cin>>temp;
        total+=temp;
    }
aver = total/double(number);
cout<<std::fixed << std::setprecision(5) <<total<<" "<<aver;
    return 0;
}