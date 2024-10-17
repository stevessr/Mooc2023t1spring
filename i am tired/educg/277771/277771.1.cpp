#include <iostream>
#include <iomanip>
int main(){
long long a;
char b;
long double c;
std::cin >> a >> b >> c;
std::cout << std::fixed << a << " " << b << " " << std::setprecision(6) << c << std::endl;
    return 0;
}