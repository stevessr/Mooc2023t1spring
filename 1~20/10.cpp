/*
#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout,std::endl,std::cin,std::string;
int main(){
    double radi;
    cin>>radi;
    cout<<std::fixed<<std::setprecision(2)<<3.14*(radi*radi*radi)*4/3;
    return 0;
}
*/ // by myself

#include <iostream>
#include <iomanip>
using std::cout, std::endl, std::cin;

int main() {
    double radi;
    cin >> radi;
    double pi = 3.14;
    double volume = (4.0 / 3.0) * pi * (radi * radi * radi);
    cout << std::fixed << std::setprecision(2) << volume << endl;
    return 0;
}
//by 4o