#include <iostream>
using std::cout, std::endl, std::cin, std::string;
int main()
{
    long long a, b;
    char c;
    cin >> a >> b >> c;
    if (c == '+')
    {
        cout<<a+b;
    }
    else if (c == '-')
    {
        cout<<a-b;
    }
    else if (c == '*')
    {
        cout<<a*b;
    }
    else if (c == '/')
    {
        if (b==0){
            cout<<"Divided by zero!";
        }else{
            cout<<a/b;
        }
    }
    else
    {
        cout<<"Invalid operator!";
    }
    return 0;
}