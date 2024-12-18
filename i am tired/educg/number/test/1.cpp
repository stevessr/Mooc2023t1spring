#include <stdio.h>
#include <iostream>
#include <typeinfo>
int main()
{
    int T;
    std::cin >> T;
    int *x1;
    int *(*x2);
    int *x3();
    int *(*x4)();
    std::cout << typeid(x1).name();
    return 0;
}