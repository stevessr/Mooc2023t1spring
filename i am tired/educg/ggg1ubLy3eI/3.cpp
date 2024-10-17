#include <iostream>
#include <iomanip>
using namespace std;
auto after (long double &money){};
int main(){
long double money;
cin>>money;
after(money);
cout<<fixed<<setprecision(2)<<money;

    return 0;
}

auto after (long double &money){
if(money<1000){
}else if (money<2000){
    money *= 0.9;
    money += 100; 
}else if (money<3000){
    money *= 0.85;
    money += 200; 
}else if (money<4000){
    money *= 0.8;
    money += 350; 
}else if (money>4000){
    money *= 0.75;
    money += 550; 
}
}